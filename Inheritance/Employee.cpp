#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"
using namespace std;

namespace employeethaymes
{
	Employee::Employee() :name("No name yet"), ssn("No number yet"), netPay(0)
	{

	}

	Employee::Employee(string theName, string theSSN)
		: name(theName), ssn(theSSN), netPay(0)
	{

	}

	string Employee::getName() const
	{
		return name;
	}

	string Employee::getSSN() const
	{
		return ssn;
	}

	double Employee::getNetPay() const
	{
		return netPay;
	}

	void Employee::setName(string newName)
	{
		name = newName;
	}

	void Employee::setSSN(string newSSN)
	{
		ssn = newSSN;
	}

	void Employee::setNetPay(double newNetPay)
	{
		netPay=newNetPay;
	}

	void Employee::printCheck() const
	{
		cout << "\nError printCheck FUNCTION CALLED FOR AN \n"
			 << "UNDEFFERENTIATED EMPLOYEE. Aborting the program.\n"
			 << "Check with the autor of the program about this bug. \n";

		exit(1);
	}









}

