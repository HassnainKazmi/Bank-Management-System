#pragma once
#include "Account.h"
#include "windows.h"

class SavingAccount:public Account
{
	string MiniRecord[10] = { "" };
	int miniIndex;

	string CompleteRecord[30] = { "" };
	int completeIndex;
	
	double minimum;
	int depositCount;
public:
	SavingAccount();
	SavingAccount(double b);
	SavingAccount(double b, int accNumber);
	int getAccountNumber(); 
	int withDraw(double previousTax, double originalamount);
	void deposit(double a);
	void displayMiniStatement();
	void displayHistory();
	void setHistory(vector<string> History);
	vector<string> gethist();
	~SavingAccount();
};

