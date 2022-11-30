#include "MasterCard.h"

MasterCard::MasterCard() : CreditCard()
{
	limit = 50000;
	interestRate = 0.18;
	interest = 0;
}

MasterCard::MasterCard(int cardNum) : CreditCard(cardNum)
{
	limit = 50000;
	interestRate = 0.18;
	interest = 0;
}

double MasterCard::interestCalculation(double amount)
{
	return (interestRate*amount);
}

double MasterCard::getLimit()
{
	return limit;
}

int MasterCard::getCreditCardNumber()
{
	return cardNumber;
}

MasterCard::~MasterCard()
{
	CreditCard::~CreditCard();
	limit, interestRate, interest = 0;
}