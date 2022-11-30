#include "VisaCard.h"

VisaCard::VisaCard() : CreditCard()
{
	limit = 100000;
	interestRate = 0.10;
	interest = 0;
}

VisaCard::VisaCard(int cardNum) : CreditCard(cardNum)
{
	limit = 100000;
	interestRate = 0.10;
	interest = 0;
}

double VisaCard::interestCalculation(double amount)
{
	return (interestRate * amount);
}

double VisaCard::getLimit()
{
	return limit;
}

int VisaCard::getCreditCardNumber()
{
	return cardNumber;
}

VisaCard::~VisaCard()
{
	CreditCard::~CreditCard();
	limit, interestRate, interest = 0;
}