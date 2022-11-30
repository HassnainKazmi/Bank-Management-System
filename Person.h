#pragma once
#include<iostream>

using namespace std;

class Person
{
protected:
	string firstName;
	string lastName;
	string cnic;
	string address;
	string telNo;
	string dob;
public:
	Person();
	Person(string f, string l, string c, string a, string t, string d);
	void setFirstName(string f);
	void setLastName(string l);
	void setCnic(string c);
	void setAddress(string a);
	void setTelNo(string t);
	void setDob(string d);
	string getName() const;
	string getFirstName() const;
	string getLastName() const;
	string getCnic() const;
	string getAddress() const;
	string getTelNo() const;
	string getDob() const;
	~Person();
};

