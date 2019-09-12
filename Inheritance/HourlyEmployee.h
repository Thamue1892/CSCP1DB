#pragma once

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;
namespace employeethaymes
{

	class HourlyEmployee :public Employee
	{
	public:
		HourlyEmployee();
		HourlyEmployee(string theName,string theSSN,double theWageRate,double theHours);
		void setRate(double newWageRate);
		double getRate()const;
		void setHours(double hoursWorked);
		double getHours()const;
		void printCheck();

	private:
		double wageRate;
		double hours;
	};
}

#endif
