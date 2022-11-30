#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class CreditCard
{
protected: // declared protected because data members of this class is used in derived classes
	int cardNumber;
public:
	static vector<int> allCardNumber; // static so it could remain same for all objects in the class, only one copy for all objects ot the class
	CreditCard();
	CreditCard(int cardNum);
	virtual int getCreditCardNumber();
	virtual double interestCalculation(double amount) { return 0; };
	virtual double getLimit() = 0;
	virtual ~CreditCard(); // Base class pointer pointing derived classes, so virutal destructor is used to ensure correct ordeer of destruction and avoding memory leak
		 // Memory leak: program allocates dynamic memory and loses all pointers to that memory, therefore it can neither address nor free it
};

