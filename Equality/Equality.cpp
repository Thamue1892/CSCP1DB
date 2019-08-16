// Equality.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class DayOfYear
{
public:
	DayOfYear(int theMonth, int theDay);
	DayOfYear();

	void input();

	void output();

	int getMonth();

	int getDay();

private:
	void checkDate();
	int month;
	int day;

};

bool equal(DayOfYear date1, DayOfYear date2);
//Precondition: date1 and date2 have values.
//Returns true if date1 and date2 represent the same date,
//otherwise,returns false.

int main()
{
	DayOfYear today, bachBirthday(3, 21);

	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();

	cout << "J.S Bach's birthday is ";
	bachBirthday.output();

	if (equal(today, bachBirthday))
		cout << "Happy birthday Johann Sebastian!\n";
	else
		cout << "Happy unbirthday Johann Sebastian!\n";

	return 0;
}
bool equal(DayOfYear date1, DayOfYear date2)
{
	return (date1.getMonth() == date2.getMonth() && date1.getDay() == date2.getDay());
}

DayOfYear::DayOfYear()
{

}


DayOfYear::DayOfYear(int theMonth, int theDay)
	:month(theMonth), day(theDay)
{
	checkDate();
}

int DayOfYear::getMonth()
{
	return month;
}

int DayOfYear::getDay()
{
	return day;
}

void DayOfYear::input()
{
	cout << " Enter the month as a number: ";
	cin >> month;
	cout << "Enter the day of the month: ";
	cin >> day;
}

void DayOfYear::output()
{
	cout << "month = " << month
		<< ", day = " << day << endl;
}

void DayOfYear::checkDate()
{
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "Illegal date. Aborting program.\n";
		exit(1);


	}
}









