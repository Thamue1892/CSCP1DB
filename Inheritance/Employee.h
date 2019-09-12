#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
using namespace std;

namespace  employeethaymes
{
	class Employee
	{
	public:
		Employee();
		Employee(string theName,string theSSN);
		string getName() const;
		string getSSN() const;
		double getNetPay() const;
		void setName(string newName);
		void setSSN(string newSSN);
		void setNetPay(double newNetPay);
		void printCheck() const;

	private:
		string name;
		string ssn;
		double netPay;
	};
}


#endif