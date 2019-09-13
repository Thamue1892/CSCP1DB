#include <string>
#include<iostream>
#include "HourlyEmployee.h"

using namespace std;

namespace employeethaymes
{
	HourlyEmployee::HourlyEmployee() :Employee(), wageRate(0), hours(0)
	{

	}

	HourlyEmployee::HourlyEmployee(string theName, string theSSN, double theWageRate, double theHours)
		: Employee(theName, theSSN), wageRate(theWageRate), hours(theHours)
	{

	}

	void HourlyEmployee::setRate(double newWageRate)
	{
		wageRate = newWageRate;
	}

	double HourlyEmployee::getRate() const
	{
		return wageRate;
	}

	void HourlyEmployee::setHours(double hoursWorked)
	{
		hours = hoursWorked;
	}

	double HourlyEmployee::getHours() const
	{
		return hours;
	}

	void HourlyEmployee::printCheck()
	{
		setNetPay(hours * wageRate);
		cout << "\n__________________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "\n__________________________________________________\n";
		cout << "Check stub:NOT NEGOTIABLE\n";
		cout << "Employee Number: " << getSSN() << endl;
		cout << "Hourly Employee. \nHours worked: " << hours
			 << " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
		cout << "\n__________________________________________________\n";

	}

}
