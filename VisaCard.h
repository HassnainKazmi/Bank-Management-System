#pragma once
#include "CreditCard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VisaCard : public CreditCard
{
private:
	double limit;
	double interestRate;
	double interest;
public:
	VisaCard();
	VisaCard(int cardNum);
	double interestCalculation(double amount);
	double getLimit();
	int getCreditCardNumber();
	~VisaCard();
};

