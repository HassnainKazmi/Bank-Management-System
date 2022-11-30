#pragma once
#include <iostream>
#include <string>
#include "windows.h"
#include "Person.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "CreditCard.h"
#include "MasterCard.h"
#include "VisaCard.h"

using namespace std;

class AccountHolder : public Person
{
private:
	string accountType;
	Account* account;
	string cardType;
	CreditCard* creditCard;
public:
	AccountHolder();
	AccountHolder(string f, string l, string c, string a, string t, string d, string aT, string cT);
	AccountHolder(int customerid, int customercard, string f, string l, string c, string a, string t, string d, string aT, string cT, double balance);
	void setDeposit(double amount);
	void getMiniStatement() const;
	int getAccNumber();
	double getBalance() const;
	void getTransactionHistory() const;
	int withdrawUsingCard(double amount);
	int withdrawUsingBook(double amount);
	string getaccountType() const;
	string getCardType() const;
	int getCardNumber();
	void extractHistory(vector<string> History);
	vector<string> getHistory();
	~AccountHolder();
};

