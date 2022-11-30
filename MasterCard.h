#pragma once
#include "CreditCard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MasterCard : public CreditCard
{
private:
	double limit;
	double interestRate;
	double interest;
public:
	MasterCard();
	MasterCard(int cardNum);
	double interestCalculation(double amount);
	double getLimit();
	int getCreditCardNumber();
	~MasterCard();
};

