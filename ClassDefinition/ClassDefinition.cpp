// ClassDefinition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class DayOfYear
{
public:
	void input();
	void output() const;

	void set(int newMonth, int newDay);
	//Precondition:newMonth and newDay form a possible date.
	//Postcondition:The date is reset according to the arguments.

	int getMonth() const;
	//Returns the month, 1 for January, 2 for February, etc.

	int getDay() const;
	//Returns the day of the month.

private:
	void checkDate() const;
	int month;
	int day;
};

int main()
{
	DayOfYear today, bachbirthday;
	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();

	bachbirthday.set(3, 21);
	cout << "J.S Bach's birthday is ";
	bachbirthday.output();

	if (today.getMonth() == bachbirthday.getMonth() && today.getDay() == bachbirthday.getDay())
	{
		cout << "Happy Birthday Johann Sebastian!\n";
	}
	else
	{
		cout << "Happy Unbirthday Johann Sebastian!\n";
	}

	return 0;
}

void DayOfYear::input()
{
	cout << "Enter the month as a number: ";
	cin >> month;
	cout << "Enter the day of the month: ";
	cin >> day;
	checkDate();
}

void DayOfYear::output() const
{
	cout << "month = " << month
		<< ", day = " << day << endl;
}

void DayOfYear::set(int newMonth, int newDay)
{
	month = newMonth;
	day = newDay;
	checkDate();
}

void DayOfYear::checkDate() const
{
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "Illegal date. Aborting program.\n";
		exit(1);


	}
}

int DayOfYear::getMonth() const
{
	return month;
}

int DayOfYear::getDay() const
{
	return day;
}


