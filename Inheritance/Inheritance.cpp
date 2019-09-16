// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using std::cout;
using std::endl;
using namespace employeethaymes;

int main()
{
   HourlyEmployee joe;
	joe.setName("Mighty Joe");
	joe.setSSN("123-45-6789");
	joe.setRate(20.50);
	joe.setHours(40);

	cout << "Check fo " <<joe.getName()
		 << " for " << joe.getHours() <<" hours.\n";
	joe.printCheck();
	cout <<endl;

	SalariedEmployee boss("Mr. Big Shot","987-65-4321",10500.50);
	cout <<"Check for " <<boss.getName()<<endl;
	boss.printCheck();


	return 0;

}
