#include "Bank.h"
#include <string>

HANDLE color3 = GetStdHandle(STD_OUTPUT_HANDLE);

Bank::Bank()
{
	customers = vector<AccountHolder>(30);
	employee = nullptr;
	size = 0;
}

void Bank::createCustomer()
{
	bool flag = true;
	int id = 0;
	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	string f, l, c, a, t, d, aT, cT = "";
	cout << endl;
	cout << "                           Customers' information: " << endl ;
	cout << "                           Enter first name: ";
	cin >> f;
	cout << "                           Enter last name: ";
	cin >> l;
	cout << "                           Enter CNIC: ";
	cin >> c;
	cout << "                           Enter address: ";
	cin >> a;
	cout << "                           Enter telephone number: ";
	cin >> t;
	cout << "                           Enter date of birth: ";
	cin >> d;
	
	do
	{
		flag = true;

		cout << "                           Enter account type (SavingAccount/CheckingAccount): ";
		cin >> aT;

		if (aT != "SavingAccount" && aT != "CheckingAccount")
		{
			SetConsoleTextAttribute(color3, 12);
			cout << "ERROR: You can only enter either SavingAccount or CheckingAccount" << endl;
			SetConsoleTextAttribute(color3, 7);
			flag = false;
		}
	} while (flag == false);

	do
	{
		flag = true;
		
		cout << "                           Enter credit card type (MasterCard/VisaCard): ";
		cin >> cT;
		
		if (cT != "MasterCard" && cT != "VisaCard")
		{
			SetConsoleTextAttribute(color3, 12);
			cout << "ERROR: You can only input either MasterCard or VisaCard" << endl;
			SetConsoleTextAttribute(color3, 7);
			flag = false;
		}
	} while ( flag == false );

	AccountHolder* customer =  new AccountHolder(f, l, c, a, t, d, aT, cT); // dynamically allocated 
	customers[size] = *customer; // dereferencing the pointer of accholder and storing the contents directly
								 // customer is an vector (array) of accountholder.  
	size++;
}

int Bank::searchCustomer(int accountNum)
{
	for (int i = 0; i < size; i++)
	{	
		if (customers[i].getAccNumber() == accountNum)
		{
			return i;
		}
	}
	
	return -1;
}

void Bank::deleteCustomer()
{
	int id = 0;
	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	int accountNum = 0;
	cout << "                           Enter account number of the account you want to delete: ";
	cin >> accountNum;

	int index = searchCustomer(accountNum);

	if (index == -1)
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: No account with entered account number exists" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		customers[i] = customers[i + 1];   // indices are moved on step back so that the data remains contigous (consecutive address)
	}
	size--;

	cout << "Account successfully deleted!" << endl;
}

void Bank::updateCustomer()
{
	int id = 0;
	int accountNum = 0;

	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	cout << "                           Enter account number of the account you want to update: ";
	cin >> accountNum;

	int index = searchCustomer(accountNum);

	if (index == -1)
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: No account with entered account number exists" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	string toDo = "";
	cout << "                           Do you want to withdraw or deposit money (W/D)? ";
	cin >> toDo;

	if (toDo == "W")
	{
		double amount = 0.0;
		string option = "";
		cout << "                           Enter the amount you want to withdraw: ";
		cin >> amount;
		cout << "                           Do you want to withdraw using chequebook or credit card (ChequeBook/CreditCard):";
		cin >> option;

		if (option == "ChequeBook")
		{
			int returned = customers[index].withdrawUsingBook(amount);

			if (returned == 1)
			{
				cout << "You have successfully withdrew " << amount << " + charges from your account" << endl;
			}
		}
		else if (option == "CreditCard")
		{
			int returned = customers[index].withdrawUsingCard(amount);

			if (returned == 1)
			{
				cout << "You have successfully withdrew " << amount << " + tax and charges from your account" << endl;
			}
		}
		else
		{
			SetConsoleTextAttribute(color3, 12);
			cout << "ERROR: You can only enter either ChequeBook or CreditCard" << endl;
			SetConsoleTextAttribute(color3, 7);
		}
		
		return;
	}
	else if (toDo == "D")
	{
		double amount = 0.0;
		cout << "                           Enter the amount you want to deposit: ";
		cin >> amount;
		customers[index].setDeposit(amount);

		cout << "You have successfully deposited " << amount << " into the account" << endl;

		return;
	}
	else
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: You can only enter either W or D" << endl;
		SetConsoleTextAttribute(color3, 7);
	}
}

string Bank::getName(int index)
{
	return customers[index].getName();
}

void Bank::displaySaving()
{
	int id = 0;
	cout << "                           Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	cout << "                           List of all the customers having a Saving Account:" << endl;
	cout << "-------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (customers[i].getaccountType() == "SavingAccount")
		{
			cout << "Name: " << customers[i].getName() << "   Account Number: " << customers[i].getAccNumber() << endl;
		}
	}
	cout << "-------------------------------------------" << endl;
}

void Bank::displayChecking()
{
	int id = 0;
	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	cout << "                           List of all the customers having a Checking Account:" << endl;
	cout << "-------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (customers[i].getaccountType() == "CheckingAccount")
		{
			cout << "Name: " << customers[i].getName() << "   Account Number: " << customers[i].getAccNumber() << endl;
		}
	}
	cout << "-------------------------------------------" << endl;
}

void Bank::displayMaster()
{
	int id = 0;
	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	cout << "                           List of all the customers having a Master Card:" << endl;
	cout << "----------------------------------------"  << endl;

	for (int i = 0; i < size; i++)
	{
		if (customers[i].getCardType() == "MasterCard")
		{
			cout << "Name: " << customers[i].getName() << "   Card Number: " << customers[i].getCardNumber() << endl;
		}
	}
	cout << "----------------------------------------" << endl;
}

void Bank::displayVisa()
{
	int id = 0;
	cout << "                           Enter Employee ID to continue: ";
	cin >> id;

	if (id != employee->getID())
	{
		SetConsoleTextAttribute(color3, 12);
		cout << "ERROR: Unauthorized access to carry out this operation" << endl;
		SetConsoleTextAttribute(color3, 7);
		return;
	}

	cout << "                           List of all the customers having a Visa Card:" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (customers[i].getCardType() == "VisaCard")
		{
			cout << "Name: " << customers[i].getName() << "   Card Number: " << customers[i].getCardNumber() << endl;
		}
	}
	cout << "----------------------------------------" << endl;
}

void Bank::createEmployee(string f, string l, int id)
{
	employee = new Employee(f, l, id); // dynamic binding (takes input on run time) 
}

int Bank::numberOfCustomers()
{
	return size;
}

void Bank::deposit_Customer(int index)
{
	double amount = 0.0;
	cout << "                           Enter the amount you want to deposit: ";
	cin >> amount;

	customers[index].setDeposit(amount);

	cout << "You have successfully deposited " << amount << " into your account" << endl;
}

void Bank::withdrawUsingCard_Customer(int index)
{
	double amount = 0.0;
	cout << "                           Enter the amount you want to withdraw: ";
	cin >> amount;

	int returned = customers[index].withdrawUsingCard(amount);

	if (returned == 1)
	{
		cout << "You have successfully withdrew " << amount << " + tax and charges from your account" << endl;
	}
}

void Bank::withdrawUsingBook_Customer(int index)
{
	double amount = 0.0;
	cout << "                           Enter the amount you want to withdraw: ";
	cin >> amount;

	int returned = customers[index].withdrawUsingBook(amount);

	if (returned == 1)
	{
		cout << "You have successfully withdrew " << amount << " + charges from your account" << endl;
	}
}

void Bank::displayBalance_Customer(int index)
{

	cout << "Your current account balance is: " << customers[index].getBalance() << endl;
}

void Bank::displayMinStatement_Customer(int index)
{
	customers[index].getMiniStatement();
}

void Bank::displayHist(int index)
{
	customers[index].getTransactionHistory();
}

int Bank::fileExists() // fstream read and write, but does not create a file
{
	fstream File;
	File.open("CustomerData.txt");

	if (File.fail() == 1) //.fail means file doesn't exist
	{
		return -1;
	}
	else
	{
		File.close();
		return 1;
	}
}

void Bank::updataEmployeeID(int ID, string fileID) 
{
	fstream oldFile; // fstream reads
	ofstream newFile; // ofstream writes 

	oldFile.open("CustomerData.txt");
	newFile.open("Temp.txt");

	string fileLine = "";
	for (int i = 0; !oldFile.eof(); i++)
	{
		getline(oldFile, fileLine);

		if (fileLine == fileID)
		{
			newFile << ID << endl;
		}
		else
		{
			newFile << fileLine << endl;
		}
	}

	newFile.close();
	oldFile.close();
	
	remove("CustomerData.txt"); // deletes the file (old file)
	int returned = rename("Temp.txt", "CustomerData.txt");
}

void Bank::creatCustomer_File(string customerid, string customercard, string f, string l, string c, string a, string t, string d, string aT, string cT, double balance)
{
	AccountHolder* customer = new AccountHolder(stoi(customerid), stoi(customercard), f, l, c, a, t, d, aT, cT, balance);
	customers[size] = *customer;
	size++;
}

void Bank::loadData(int ID)
{
	fstream file; // fstream read and write
	file.open("CustomerData.txt");

	string id = to_string(ID);
	string f, l, c, a, t, d, aT, cT, balanceString, customerid, customercard = "";
	double balance = 0.0;
	string fileLine = "";
	int iteration = 0;
	
	getline(file, fileLine); // getline 1st parameter reads from the file and in 2nd parameter the line gets copied.
	cout << endl;
	
	vector<string> history;
	while (!file.eof())
	{
		if (fileLine == id)
		{
			if (iteration != 0)  // first we need to create atleast 1 customer and then add their extracted history 
			{
				customers[size-1].extractHistory(history); // set history for previous customer
				history.clear(); // vector cleared for new customer
			}

			getline(file, f);
			getline(file, l);
			getline(file, c);
			getline(file, a);
			getline(file, t);
			getline(file, d);
			getline(file, aT);
			getline(file, customerid);
			getline(file, cT);
			getline(file, customercard);
			getline(file, balanceString);
			balance = stod(balanceString);

			creatCustomer_File(customerid, customercard, f, l, c, a, t, d, aT, cT, balance);
			cout << endl;

			iteration++;
		}

		// record storing
		getline(file, fileLine);

		// format of transactions: DepositAmount:amount NewBalance:accountBalance
		// format of transactions:  WithdrawAmount:amount Charges:deduction RemainingBalance:accountBalance	
		bool notDepositCheck = false;
		bool notWithdrawCheck = false;
		
		if (fileLine.substr(0, 7) != "Deposit")
		{
			notDepositCheck = true;
		}
		if (fileLine.substr(0, 8) != "Withdraw")
		{
			notWithdrawCheck = true;
		}

		if (notDepositCheck == true && notWithdrawCheck == true)
		{
			continue;
		}
		else
		{
			//add record
			history.push_back(fileLine);
		}
	}

	customers[size-1].extractHistory(history); // sets history last customer
	history.clear();
}

void Bank::saveData(int ID)
{
	ofstream newFile; // ofstream writes 
	newFile.open("Temp.txt"); 

	for (int i = 0; i < size; i++)
	{
		newFile << ID << endl;
		newFile << customers[i].getFirstName() << endl;
		newFile << customers[i].getLastName() << endl;
		newFile << customers[i].getCnic() << endl;
		newFile << customers[i].getAddress() << endl;
		newFile << customers[i].getTelNo() << endl;
		newFile << customers[i].getDob() << endl;
		newFile << customers[i].getaccountType() << endl;
		newFile << customers[i].getAccNumber() << endl;
		newFile << customers[i].getCardType() << endl;
		newFile << customers[i].getCardNumber() << endl;
		newFile << customers[i].getBalance() << endl;
		
		// Store only complete history
		vector<string> Complete;
		Complete.clear();
		
		Complete = customers[i].getHistory();
		
		int size = Complete.size();
		for (int i = 0; i < size; i++)
		{
			newFile << Complete[i] << endl;
		}
	}

	newFile.close();

	remove("CustomerData.txt");
	int returned = rename("Temp.txt", "CustomerData.txt");
}

Bank::~Bank()
{
	size = 0;
	customers.clear();
}