#include "AccountHolder.h"

HANDLE color2 = GetStdHandle(STD_OUTPUT_HANDLE);

AccountHolder::AccountHolder() : Person()
{
	accountType = "";
	account = NULL;
	cardType = "";
	creditCard = NULL;
}

AccountHolder::AccountHolder(string f, string l, string c, string a, string t, string d, string aT, string cT) : Person(f, l, c, a, t, d)
{
	accountType = aT;
	cardType = cT;

	// create checking account for this person
	if (accountType == "CheckingAccount")
	{
		double amount = 0.0;
		cout << "                           Please Enter initial amount: ";
		cin >> amount;
		
		account = new CheckingAccount(amount);
		cout << "Congratulations! " << getName() << " your CheckingAccount has been created!" << endl;
	}
	else if (accountType == "SavingAccount")
	{
		// create saving account for this person
		double amount = 0.0;
		cout << "                           Please Enter initial amount: ";
		cin >> amount;
		
		account = new SavingAccount(amount);
		cout << "Congratulations! " << getName() << " your SavingAccount has been created!" << endl;
	}

	// create master card
	if (cardType == "MasterCard")
	{
		creditCard = new MasterCard();
		cout << "Congratulations! " << getName() << " your MasterCard has been created!" << endl;
	}
	else if (cardType == "VisaCard")
	{
		creditCard = new VisaCard();
		cout << "Congratulations! " << getName() << " your VisaCard has been created!" << endl;
	}
}
// Avoids overwriting of customer acc id and card id
AccountHolder::AccountHolder(int customerid, int customercard, string f, string l, string c, string a, string t, string d, string aT, string cT, double balance) : Person(f, l, c, a, t, d)
{
	accountType = aT;
	cardType = cT;

	if (accountType == "CheckingAccount")
	{
		account = new CheckingAccount(balance, customerid);
		cout << getName() << " - CheckingAccount" << endl;
	}
	else if (accountType == "SavingAccount")
	{
		account = new SavingAccount(balance, customerid);
		cout << getName() << " - SavingAccount" << endl;
	}

	if (cardType == "MasterCard")
	{
		creditCard = new MasterCard(customercard);
		cout << getName() << " - MasterCard" << endl;
	}
	else if (cardType == "VisaCard")
	{
		creditCard = new VisaCard(customercard);
		cout << getName() << " - VisaCard" << endl;
	}
}

// cash deposit
void AccountHolder::setDeposit(double amount)
{
	account->deposit(amount);
}

// mini-statment display
void AccountHolder::getMiniStatement() const
{
	account->displayMiniStatement();
}

// get account number
int AccountHolder::getAccNumber() 
{
	return account->getAccountNumber();
}

// balance inquiry
double AccountHolder::getBalance() const
{
	return account->getAccountBalance();
}

// entire transaction history
void AccountHolder::getTransactionHistory() const
{
	account->displayHistory();
}

// withdraw amount using credit card
int AccountHolder::withdrawUsingCard(double amount)
{
	if (amount > creditCard->getLimit())
	{
		SetConsoleTextAttribute(color2, 12);
		cout << "Amount entered exceeds your card's withdrawal limit. Limit of your " << cardType << " is: " << creditCard->getLimit() << endl;
		SetConsoleTextAttribute(color2, 7);
		return -1;
	}

	double deduction = creditCard->interestCalculation(amount);

	double num = (getBalance() - (deduction + amount));
	try
    {
        if (num < 0)
        {
            throw(num);
        }
        else
        {
			return account->withDraw(deduction, amount);
        }
    }
    catch(double num)
    {
		SetConsoleTextAttribute(color2, 12);
        cout << "Insufficient amount entered" << endl;
		SetConsoleTextAttribute(color2, 7);
		return -1;
    }
}

// withdraw using chequeBook
int AccountHolder::withdrawUsingBook(double amount)
{
	return account->withDraw(0, amount);
}

string AccountHolder::getaccountType() const
{
	return accountType;
}

string AccountHolder::getCardType() const
{
	return cardType;
}

int AccountHolder::getCardNumber()
{
	return creditCard->getCreditCardNumber();
}

void AccountHolder::extractHistory(vector<string> History)
{
	account->setHistory(History);
}

vector<string> AccountHolder::getHistory()
{
	return account->gethist();
}

AccountHolder::~AccountHolder()
{
	Person::~Person();
	delete[] account;
	delete[] creditCard;
	cardType = "";
	accountType = "";
}

