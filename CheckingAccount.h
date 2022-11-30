#pragma once
#include"Account.h"
#include "windows.h"

class CheckingAccount:public Account
{
	string MiniRecord[10] = { "" };
	int miniIndex;

	string CompleteRecord[30] = { "" };
	int completeIndex;
public:
	CheckingAccount();
	CheckingAccount(double b);
	CheckingAccount(double b, int accNumber);
	int getAccountNumber();
	int withDraw(double previousTax, double originalamount);
	void deposit(double a);
	void displayMiniStatement();
	void displayHistory();
	void setHistory(vector<string> History);
	vector<string> gethist();
	~CheckingAccount();
};

