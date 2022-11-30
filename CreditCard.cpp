#include "CreditCard.h"

vector<int> CreditCard::allCardNumber = vector<int>();

CreditCard::CreditCard()
{
	bool flag = false;
	int rand_int = 0;
	while (true)
	{
		rand_int = rand() % 1000;

		for (int i = 0; i < allCardNumber.size(); i++)
		{
			if (allCardNumber[i] == rand_int)
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

	allCardNumber.push_back(rand_int);
	cardNumber = rand_int;

	cout << "Credit Card ID: " << cardNumber << endl;
}

CreditCard::CreditCard(int cardNum)
{
	allCardNumber.push_back(cardNum);
	cardNumber = cardNum;

	cout << "Credit Card ID: " << cardNumber << endl;
}

int CreditCard::getCreditCardNumber()
{
	return cardNumber;
}

CreditCard::~CreditCard()
{
	cardNumber = 0;
	allCardNumber.clear();
}