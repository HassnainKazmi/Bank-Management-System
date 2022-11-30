#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee
{
private:
	string firstName;
	string lastName;
	int ID;
public:
	Employee();
	Employee(string f, string l, int id);
	int getID() const;
	~Employee();
};

