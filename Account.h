#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;

class Account
{
protected:   // declared protected because data members of this class is used in derived classes
	double serviceCharges, governmentCharges, accountBalance;
	int accountNumber;
public:
	static vector<int> accNum_vec; 
	// static so it could remain same for all objects in the class
	Account();
	Account(double balance);
	Account(double balance, int accNumber);
	void setAccountBalance(double b);
	double getAccountBalance() const;
	virtual int getAccountNumber() const;
	virtual int withDraw(double previousTax, double originalamount) { return 2; };
	virtual void deposit(double a) {};
	virtual void displayMiniStatement() = 0;
	virtual void displayHistory() = 0;
	virtual void setHistory(vector<string> History) {}; 
	virtual vector<string> gethist() { vector<string> nothing; return nothing; };
	virtual ~Account(); // Base class pointer pointing derived classes, so virutal destructor is used to ensure correct order of destruction and avoding memory leak
		// Memory leak: program allocates dynamic memory and loses all pointers to that memory, therefore it can neither address nor free it
};
