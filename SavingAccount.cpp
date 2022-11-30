#include "SavingAccount.h"

HANDLE color5 = GetStdHandle(STD_OUTPUT_HANDLE);

SavingAccount::SavingAccount() : Account()
{
	minimum = 0;
	depositCount = 0;
	miniIndex = 0;
	completeIndex = 0;
}

SavingAccount::SavingAccount(double b) : Account(b)
{

	minimum = b;
	depositCount = 0;
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

SavingAccount::SavingAccount(double b, int accNumber) : Account(b, accNumber) // avoids overwiting of account num while loading data from file 
{
	minimum = b;
	depositCount = 0;
	miniIndex = 0;
	completeIndex = 0;
}

int SavingAccount::getAccountNumber() 
{
	return accountNumber;
}

int SavingAccount::withDraw(double previousTax, double originalamount)
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

			// store minimum for interest payment
			if (accountBalance < minimum)
			{
				minimum = accountBalance;
			}

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
		SetConsoleTextAttribute(color5, 12);
		cout << "Insufficient amount entered" << endl;
		SetConsoleTextAttribute(color5, 7);
		return -1;
	}
}

void SavingAccount::deposit(double a)
{
	accountBalance += a;

	// format of transactions: DepositAmount:amount NewBalance:accountBalance
	string transaction = "DepositAmount:" + to_string(a) + " NewBalance:" + to_string(accountBalance);
	
	depositCount++;

	// interest calculation
	if (depositCount >= 10)
	{
		depositCount = 0;
		
		double interest = 0.01*minimum; // interest on minimum balance in complete transcation history
		double tax = 0.005 * interest;
		accountBalance += (interest - tax);
	}

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

void SavingAccount::displayMiniStatement()
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

void SavingAccount::displayHistory()
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

void SavingAccount::setHistory(vector<string> History) // File reading to restore deposit count, complete and mini history
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

		if (History[i].substr(0, 7) == "Deposit")
		{
			depositCount++;

			if (depositCount >= 10)
			{
				depositCount = 0;
			}
		}
	}
}

vector<string> SavingAccount::gethist() // Returns a vector of complete history which is used to write in the file
{
	vector<string> toReturn;
	toReturn.clear();

	for (int i = 0; i < completeIndex; i++)
	{
		toReturn.push_back(CompleteRecord[i]);
	}

	return toReturn;
}

SavingAccount::~SavingAccount()
{
	Account::~Account();
	minimum, depositCount = 0;
}