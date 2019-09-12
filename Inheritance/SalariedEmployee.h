#pragma once

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;

namespace employeethaymes
{

	class SalariedEmployee :public Employee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(string theName, string theSSN, double theWeeklySalary);
		double getSalary()const;
		void setSalary(double newSalary);
		void printCheck();

	private:
		double salary;
	};
}

