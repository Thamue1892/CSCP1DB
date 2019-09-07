// DigitalTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dtime.h"
using namespace std;

int main()
{
	DigitalTime clock, oldClock;

	cout << "Enter the time in 24-hour notation: ";
	cin >> clock;

	oldClock = clock;
	clock.advance(15);
	if (clock == oldClock)
		cout << "Something is wrong.";
	cout << "You entered " << oldClock << endl;
	cout << "15 minutes later the time will be "
		<< clock << endl;

	clock.advance(2, 15);
	cout << "2 Hours and 15 minutes after that\n"
		<< "the time will be "
		<< clock << endl;

	return 0;
}

