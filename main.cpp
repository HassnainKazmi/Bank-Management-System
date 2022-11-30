#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "windows.h"
#include "Bank.h"

using namespace std;

int main()
{
	srand(time(0)); 
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	Bank bankobject;

	string f, l = "";
	int id = 0;
	int number = 0;

	// create employee first
	cout << endl << endl << endl << endl << endl <<endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
	cout << "                                           Create an employee to begin with" << endl << endl;
	cout << "                               Enter employee's first name: ";
	cin >> f;
	cout << "                               Enter employee's last name: ";
	cin >> l;
	do
	{
		cout << "                               Enter employee's ID (must be greater than 10000): ";
		cin >> id;

		if (id <= 10000)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: ID must be greater than 10000. Try again!" << endl;
			SetConsoleTextAttribute(color, 7);
		}

	} while (id <= 10000);
	
	bankobject.createEmployee(f, l, id);

	backtostart:
	system("pause");
	system("CLS");


	// display a menu here asking to go to sudo mode or to load customers from file?
	int input = 0;
	cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
	cout << "                                       Select either of the options given below" << endl << endl;
	cout << "                               1- Enter sudo mode" << endl;
	cout << "                               2- Load customer data from database" << endl;
	cout << "                               Please enter your choice: ";
	cin >> input;

	if (input == 1)
	{
		goto nocustomer;

	}
	else if (input == 2)
	{
		// check if file exists or not
		int returned = bankobject.fileExists();
	
		if (returned == 1)
		{
			// we know that file exists, we need to edit the file in a way that the employee id gets replaced with the new one entered
			fstream File;
			File.open("CustomerData.txt");
			string line = "";
			getline(File,line);
			File.close();
			
			if (line == "")
			{
				goto emptyfile;
			}
			
			bankobject.updataEmployeeID(id, line);

			// then we load the data
			bankobject.loadData(id);
			cout << "Customer data successfully read from database!" << endl;
			
			goto dataloaded;
		}
		else
		{
			emptyfile:
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: No database with customers' data exists. Proceeding to sudo mode" << endl;
			SetConsoleTextAttribute(color, 7);
			goto nocustomer;
		}
	}
	else
	{
		SetConsoleTextAttribute(color, 12);
		cout << "ERROR: You can only enter either 1 or 2" << endl;
		SetConsoleTextAttribute(color, 7);
		goto backtostart;
	}

	nocustomer:
	system("pause");
	system("CLS");

	// now create customers 
	cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
	cout << "                                      Create customer(s) before proceeding ahead" << endl << endl << endl;
	cout << "                                       How many customers you want to create: ";
	cin >> number;
	cout << endl;

	for (int i = 0; i < number; i++)
	{
		bankobject.createCustomer();
		cout << endl;
	}

	dataloaded:
	if (bankobject.numberOfCustomers() == 0)
	{
		SetConsoleTextAttribute(color, 12);
		cout << "ERROR: Can not proceed ahead. Please create atleast one customer" << endl;
		SetConsoleTextAttribute(color, 7);
		goto nocustomer;
	}

	system("pause");
	system("CLS");

	cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
	cout << "                                   Now that we have created an employee and atleast" << endl;
	cout << "                                        1 customer, we can proceed to the menu" << endl;
	
	wrongoption:
	system("pause");
	system("CLS");

	// create menu
	int option = 0;
	cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
	cout << "                                       Select either of the options given below" << endl << endl;
	cout << "                               1- Employee mode" << endl;
	cout << "                               2- Customer mode" << endl;
	cout << "                               3- Exit" << endl;
	cout << "                               Please enter your choice: ";
	cin >> option;

	if (option == 1)
	{
		// make employee mode menu
		wrongInsideOption:
		system("pause");
		system("CLS");

		int insideOption = 0;
		
		cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
		cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl;
		cout << "                                       Select either of the options given below" << endl << endl;
		cout << "                               1- Create customer" << endl;
		cout << "                               2- Delete customer" << endl;
		cout << "                               3- Update customer" << endl;
		cout << "                               4- Show a list of all Saving Accounts" << endl;
		cout << "                               5- Show a list of all Checking Accounts" << endl;
		cout << "                               6- Show a list of account holders having a Master Card" << endl;
		cout << "                               7- Show a list of account holders having a Visa Card" << endl;
		cout << "                               8- Exit" << endl;
		cout << "                               Please enter your choice: ";
		cin >> insideOption;

		switch (insideOption)
		{
			case 1:
			{
				// create customer
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.createCustomer();
				break;
			}
			case 2:
			{
				// delete customer
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.deleteCustomer();
				break;
			}
			case 3:
			{
				// update customer i.e withdraw or deposit amount in some customer's account
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.updateCustomer();
				break;
			}
			case 4:
			{
				// display saving
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.displaySaving();
				break;
			}
			case 5:
			{
				// display checking
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.displayChecking();
				break;
			}
			case 6:
			{
				// display master
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.displayMaster();
				break;
			}
			case 7:
			{
				// display visa
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				bankobject.displayVisa();
				break;
			}
			case 8:
			{
				// Exit
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       EMPLOYEE MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				cout << endl << "					         EXITING EMPLOYEE MODE" << endl;
				goto wrongoption;
			}
			default: 
			{
				SetConsoleTextAttribute(color, 12);
				cout << "ERROR: You can only enter either 1, 2, 3, 4, 5, 6, 7 or 8" << endl;
				SetConsoleTextAttribute(color, 7);
				goto wrongInsideOption;
			}
		}
		goto wrongInsideOption;
	}
	else if (option == 2)
	{
		//make customer mode menu
		system("pause");
		system("CLS");

		int iD = 0;

		cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
		cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl;

		// ask for customr login i.e their account number
		cout << "                                              Enter your ID to login: ";
		cin >> iD;

		int index = bankobject.searchCustomer(iD);

		if (index == -1)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: No account with entered account number exists" << endl;
			SetConsoleTextAttribute(color, 7);
			goto wrongoption;
		}
		else
		{
			cout << "Welcome " << bankobject.getName(index) << endl;
		}

		wrongCustomerOption:
		system("pause");
		system("CLS");

		cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
		cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl;

		int insideoption = 0;
		cout << "                                       Select either of the options given below" << endl << endl;
		cout << "                               1- Deposit" << endl;
		cout << "                               2- Withdraw using Credit Card" << endl;
		cout << "                               3- Withdraw using Cheque Book" << endl;
		cout << "                               4- Display current balance" << endl;
		cout << "                               5- Display mini-statement" << endl;
		cout << "                               6- Display complete transaction history" << endl;
		cout << "                               7- Exit" << endl;
		cout << "                               Please enter your choice: ";
		cin >> insideoption;

		switch (insideoption)
		{
			case 1: 
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				
				// make deposit
				bankobject.deposit_Customer(index);
				
				break;
			}
			case 2:
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;

				// withdraw using card
				bankobject.withdrawUsingCard_Customer(index);

				break;
			}
			case 3:
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;

				// withdraw using book
				bankobject.withdrawUsingBook_Customer(index);

				break;
			}
			case 4:
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;

				// display balance 
				bankobject.displayBalance_Customer(index);
				
				break;
			}
			case 5:
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;

				// display mini-statement 
				bankobject.displayMinStatement_Customer(index);

				break;
			}
			case 6:
			{
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;

				// display transaction history
				bankobject.displayHist(index);

				break;
			}
			case 7:
			{
				// Exit
				system("CLS");
				cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
				cout << "                \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       CUSTOMER MODE      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl << endl << endl << endl;
				cout << endl << "					         EXITING CUSTOMER MODE" << endl;
				goto wrongoption;
			}
			default:
			{
				SetConsoleTextAttribute(color, 12);
				cout << "ERROR: You can only enter either 1, 2, 3, 4, 5, 6 or 7" << endl;
				SetConsoleTextAttribute(color, 7);
				goto wrongCustomerOption;
			}
		}

		goto wrongCustomerOption;
	}
	else if (option == 3)
	{
		wrong:
		system("pause");
		system("CLS");
		
		int choice = 0;
		cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
		cout << "                                       Select either of the options given below" << endl << endl;
		cout << "                               1- Save current customer state" << endl;
		cout << "                               2- Exit without saving current customer state" << endl;
		cout << "                               Please enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			bankobject.saveData(id);

			cout << "Current customer state saved. Continuing to exit screen" << endl;
		}
		else if (choice == 2)
		{
			cout << "Continuing to exit screen without saving current customer state" << endl;
		}
		else
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: you can enter either 1 or 2" << endl;
			SetConsoleTextAttribute(color, 7);
			goto wrong;
		}
	
		// Exit
		system("pause");
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << "                \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BANK MANAGEMENT SYSTEM  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl << endl;
		cout << endl << "							EXITING" << endl << endl << endl << endl;

		return 0;
	}
	else
	{
		SetConsoleTextAttribute(color, 12);
		cout << "ERROR: You can only input either 1, 2 or 3" << endl;
		SetConsoleTextAttribute(color, 7);
		goto wrongoption;	
	}
}