#include "CheckingAccount.h"

HANDLE color4 = GetStdHandle(STD_OUTPUT_HANDLE);

CheckingAccount::CheckingAccount() : Account()
{
	miniIndex = 0;
	completeIndex = 0;
}

CheckingAccount::CheckingAccount(double b) : Account(b)
{
	miniIndex = 0;
	completeIndex = 0;
	string transaction = "";

	// format of transactions: DepositAmount:amount NewBalance:accountBalance
	transaction = "DepositAmount:" + to_string(b) + " NewBalance:" + to_string(accountBalance);

	// do mini statement thingy
	MiniRecord[miniIndex] = transaction;
	miniIndex++;

	if (miniIndex >= 10)
	{
		miniIndex = 0;
	}

	// do complete history thingy
	CompleteRecord[completeIndex] = transaction;
	completeIndex++;
}

CheckingAccount::CheckingAccount(double b, int accNumber) : Account(b, accNumber)
{
	miniIndex = 0;
	completeIndex = 0;
}

int CheckingAccount::getAccountNumber()
{
	return accountNumber;
}

int CheckingAccount::withDraw(double previousTax, double originalamount)
{

	double deduction = 0;

	if (originalamount > 5000)
	{
		deduction += (serviceCharges * originalamount);
	}
	if (originalamount > 50000)
	{
		deduction += (governmentCharges * originalamount);
	}
	
	double num = accountBalance - (previousTax + deduction + originalamount);
	try
	{
		if (num < 0)
		{
			throw(num);
		}
		else
		{
			accountBalance = accountBalance - (originalamount + previousTax + deduction);
			deduction += previousTax;

			// format of transactions:  WithdrawAmount:amount Charges:deduction RemainingBalance:accountBalance 
			string transaction = "WithdrawAmount:" + to_string(originalamount) + " Charges:" + to_string(deduction) + " RemainingBalance:" + to_string(accountBalance);

			// do mini statement thingy
			MiniRecord[miniIndex] = transaction;
			miniIndex++;

			if (miniIndex >= 10)
			{
				miniIndex = 0;
			}

			// do complete history thingy
			CompleteRecord[completeIndex] = transaction;
			completeIndex++;

			return 1;
		}
	}
	catch (double num)
	{
		SetConsoleTextAttribute(color4, 12);
		cout << "Insufficient amount entered" << endl;
		SetConsoleTextAttribute(color4, 7);
		return -1;
	}
}

void CheckingAccount::deposit(double a)
{
	accountBalance += a;

	// format of transactions: DepositAmount:amount NewBalance:accountBalance
	string transaction = "DepositAmount:" + to_string(a) + " NewBalance:" + to_string(accountBalance);

	// do mini statement thingy
	MiniRecord[miniIndex] = transaction;
	miniIndex++;

	if (miniIndex >= 10)
	{
		miniIndex = 0;
	}

	// do complete history thingy
	CompleteRecord[completeIndex] = transaction;
	completeIndex++;
}

void CheckingAccount::displayMiniStatement()
{
	cout << "                                       Mini-Statement:" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	for (int i = 0; i < 10; i++)
	{
		if (MiniRecord[i] == "")
		{
			continue;
		}
		else
		{
			cout << MiniRecord[i] << endl;
		}
	}

	cout << "---------------------------------------------------------------------------------------------" << endl;
}

void CheckingAccount::displayHistory()
{
	cout << "                                     Transaction History:" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < 30; i++)
	{
		if (CompleteRecord[i] == "")
		{
			continue;
		}
		else
		{
			cout << CompleteRecord[i] << endl;
		}
	}

	cout << "---------------------------------------------------------------------------------------------" << endl;
}

void CheckingAccount::setHistory(vector<string> History) // File reading to restore deposit count, complete and mini history
{
	int size = History.size();

	if (size == 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		CompleteRecord[completeIndex] = History[i];
		MiniRecord[miniIndex] = History[i];
		completeIndex++;
		miniIndex++;

		if (miniIndex >= 10)
		{
			miniIndex = 0;
		}
	}
}

vector<string> CheckingAccount::gethist() // Returns a vector of complete history which is used to write in the file
{
	vector<string> toReturn;
	toReturn.clear();

	for (int i = 0; i < completeIndex; i++)
	{
		toReturn.push_back(CompleteRecord[i]);
	}

	return toReturn;
}

CheckingAccount::~CheckingAccount()
{
	Account::~Account();
}