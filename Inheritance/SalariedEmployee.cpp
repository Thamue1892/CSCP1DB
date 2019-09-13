#include <iostream>
#include <string>
#include "SalariedEmployee.h"
using namespace std;

namespace employeethaymes
{
	SalariedEmployee::SalariedEmployee() :Employee(),salary(0)
	{
		
	}

	SalariedEmployee::SalariedEmployee(string theName, string theSSN, double theWeeklySalary)
		:Employee(theName,theSSN),salary(theWeeklySalary)
	{
		
	}

	double SalariedEmployee::getSalary() const
	{
		return salary;
	}

	void SalariedEmployee::setSalary(double newSalary)
	{
		salary=newSalary;
	}

	void SalariedEmployee::printCheck()
	{
		setNetPay(salary);
		cout << "\n__________________________________________________\n";
		cout << "Pay to the order of "<<getName() <<endl;
		cout << "The sum of " <<getNetPay() <<" Dollars\n";
		cout << "\n__________________________________________________\n";
		cout << "Check Stub: NOT NEGOTIABLE \n";
		cout << "Employee Number: " << getSSN()<<endl;
		cout <<"Salaried Employee. Regular Pay: "
			 << salary <<endl;
		cout << "\n__________________________________________________\n";

	}


}
