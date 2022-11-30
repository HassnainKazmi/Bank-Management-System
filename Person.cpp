#include "Person.h"

Person::Person()
{
	firstName = lastName = cnic = address = telNo = dob = "";
}

Person::Person(string f, string l, string c, string a, string t, string d)
{
	firstName = f;
	lastName = l;
	cnic = c;
	address = a;
	telNo = t;
	dob = d;
}

void Person::setFirstName(string f)
{
	firstName = f;
}

void Person::setLastName(string l)
{
	lastName = l;
}

void Person::setCnic(string c)
{
	cnic = c;
}

void Person::setAddress(string a)
{
	address = a;
}

void Person::setTelNo(string t)
{
	telNo = t;
}

void Person::setDob(string d)
{
	dob = d;
}

string Person::getName() const
{
	return firstName + " " + lastName;
}

string Person::getFirstName() const
{
	return firstName;
}
string Person::getLastName() const
{
	return lastName;
}

string Person::getCnic() const
{
	return cnic;
}

string Person::getAddress() const
{
	return address;
}

string Person::getTelNo() const
{
	return telNo;
}

string Person::getDob() const
{
	return dob;
}

Person::~Person()
{
	firstName, lastName, cnic, address, telNo, dob = "";
}
