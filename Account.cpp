#include "Account.h"

vector<int> Account::accNum_vec = vector<int>();

Account::Account()
{
	serviceCharges = 0.002;
	governmentCharges = 0.025;
	accountBalance = 0;
	
	bool flag = false;
	int rand_int = 0;
	while (true)
	{
		rand_int = rand() % 1000;

		for (int i = 0; i < accNum_vec.size(); i++) // loop to check that the new account num is already assigned to any other customer
		{
			if (accNum_vec[i] == rand_int) // if the newly generated account num equals to already stored account number in the vector
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			flag = false;
			continue;
		}
		else
		{
			break;
		}
	}

	accountNumber = rand_int;
	accNum_vec.push_back(accountNumber);
}

Account::Account(double balance)
{
	serviceCharges = 0.002;
	governmentCharges = 0.025;
	accountBalance = balance;
	
	bool flag = false;
	int rand_int = 0;
	while (true)
	{
		rand_int = rand() % 1000;

		for (int i = 0; i < accNum_vec.size(); i++)
		{
			if (accNum_vec[i] == rand_int)
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			flag = false;
			continue;
		}
		else
		{
			break;
		}
	}

	accountNumber = rand_int;
	accNum_vec.push_back(accountNumber);
	
	cout << "Account ID: " << accountNumber << endl;
	cout << "Initial account balance: " << accountBalance << endl;
}

Account::Account(double balance, int accNumber) // avoids overwriting in account number
{
	serviceCharges = 0.002;
	governmentCharges = 0.025;
	accountBalance = balance;
	accountNumber = accNumber;
	accNum_vec.push_back(accountNumber);

	cout << "Account ID: " << accountNumber << endl;
	cout << "Initial account balance: " << accountBalance << endl;
}

void Account::setAccountBalance(double b)
{
	accountBalance = b;
}

double Account::getAccountBalance() const
{
	return accountBalance;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

Account::~Account()
{
	serviceCharges, governmentCharges, accountBalance, accountNumber = 0;
	accNum_vec.clear();
}

