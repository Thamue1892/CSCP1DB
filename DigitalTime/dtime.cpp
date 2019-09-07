#include <iostream>
#include <cctype>
#include <cstdlib>
#include "dtime.h"
using namespace std;

void readHour(istream& ins, int& theHour);
//Precondition: Next input in the stream ins is a time in 24-hour notation
//Postcondition: theHour has been set to the hour part of the time.
//The colon has been discarded and the next input to be readis the minute.

void readMinute(istream& ins, int& theMinute);
//Reads the minute from the stream ins after readHour has read the hour.

int digitToInt(char c);
//Precondition: c is one of the igits '0' through '9'.
//Returns the integer for the digit.

bool operator==(const DigitalTime& time1, const DigitalTime& time2)
{
	return (time1.hour == time2.hour && time1.minute == time2.minute);
}

DigitalTime::DigitalTime(int theHour, int theMinute)
{
	if (theHour < 0 || theHour >23 || theMinute < 0 || theMinute>59)
	{
		cout << "Illegal argument to DigitalTime constructor.";
		exit(1);
	}
	else
	{
		hour = theHour;
		minute = theMinute;
	}
}

DigitalTime::DigitalTime() :hour(0), minute(0)
{

}

void DigitalTime::advance(int minutesAdded)
{
	int grossMinutes = minute + minutesAdded;
	minute = grossMinutes % 60;

	int hourAdjustment = grossMinutes / 60;
	hour = (hour + hourAdjustment) % 24;
}

void DigitalTime::advance(int hoursAdded, int minutesAdded)
{
	hour = (hour + hoursAdded)%24;
	advance(minutesAdded);
}


ostream& operator<<(ostream& outs, const DigitalTime& theObject)
{
	outs << theObject.hour << ':';
	if (theObject.minute < 10)


		outs << '0';
	outs << theObject.minute;
	return outs;
}

istream& operator>>(istream& ins, DigitalTime& theObject)
{
	readHour(ins, theObject.hour);
	readMinute(ins, theObject.minute);
	return ins;
}

int digitToInt(char c)
{
	return (static_cast<int>(c) - static_cast<int>('0'));
}

void readMinute(istream& ins, int& theMinute)
{
	char c1, c2;
	ins >> c1 >> c2;

	if (!(isdigit(c1) && isdigit(c2)))
	{
		cout << "Error illegal input to readMinute\n";
		exit(1);
	}

	theMinute = (digitToInt(c1) * 10) + digitToInt(c2);

	if (theMinute < 0 || theMinute>59)
	{
		cout << "Error illegal input to readMinute\n";
		exit(1);
	}
}

void readHour(istream& ins, int& theHour)
{
	char c1, c2;
	ins >> c1 >> c2;
	if (!(isdigit(c1) && (isdigit(c2) || c2 == ':')))
	{
		cout << "Error illegal input to readHour\n";
		exit(1);
	}

	if (isdigit(c1) && c2 == ':')
	{
		theHour = digitToInt(c1);
	}
	else
	{
		theHour = (digitToInt(c1) * 10) + digitToInt(c2);
		ins >> c2;
		if (c2 != ':')
		{
			cout << "Error illegal input to readHour\n";
			exit(1);
		}
	}

	if (theHour < 0 || theHour>23)
	{
		cout << "Error illegal input to readHour\n";
		exit(1);
	}
}










