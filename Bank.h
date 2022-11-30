#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "AccountHolder.h"
#include "windows.h"
#include "Employee.h"

using namespace std;

class Bank
{
private:
	vector<AccountHolder> customers;
	Employee* employee;
	int size;
public:
	Bank();
	void createCustomer();
	int searchCustomer(int accountNum);
	void deleteCustomer();
	void updateCustomer();
	string getName(int index);
	void displayMaster();
	void displayVisa();
	void displaySaving();
	void displayChecking();
	void createEmployee(string f, string l, int id);
	int numberOfCustomers();
	void deposit_Customer(int index);
	void withdrawUsingCard_Customer(int index);
	void withdrawUsingBook_Customer(int index);
	void displayBalance_Customer(int index);
	void displayMinStatement_Customer(int index);
	void displayHist(int index);
	int fileExists();
	void updataEmployeeID(int ID, string fileID);
	void creatCustomer_File(string customerid, string customercard, string f, string l, string c, string a, string t, string d, string aT, string cT, double balance);
	void loadData(int ID);
	void saveData(int ID);
	~Bank();
};

