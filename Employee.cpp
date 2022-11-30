#include "Employee.h"

Employee::Employee()
{
	firstName, lastName = "";
	ID = 0;
}

Employee::Employee(string f, string l, int id)
{
	firstName = f;
	lastName = l;
	ID = id;

	cout << "Employee has been created!" << endl;
}

int Employee::getID() const
{
	return ID;
}

Employee::~Employee()
{
	firstName, lastName = "";
	ID = 0;
}
