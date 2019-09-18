// VirtualFunctionsInC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sale.h"
#include "DiscountSale.h"
using namespace std;
using namespace salethaymes;

int main()
{
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if (discount < simple)
	{
		cout<<"Discounted item is cheaper.\n";
		cout <<"Savings is $"<<simple.savings(discount)<<endl;
	}
	else
		cout <<"Discounted item is not cheaper.\n";

	return 0;
}

