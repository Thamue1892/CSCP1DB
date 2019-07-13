// ClassDefinition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class DayOfYear
{
public:
    void output();
    int month;
    int day;
};

int main()
{
    DayOfYear today, birthday;

    cout << "Enter today's date:\n";
    cout << "Enter month as a number: ";
    cin >> today.month;
    cout << "Enter the day of the month: ";
    cin >> today.day;
    cout << "Enter your birthday:\n";
    cout << "Enter month as a number: ";
    cin >> birthday.month;
    cout << "Enter the day of the month: ";
    cin >> birthday.day;

    cout << "Today's date is ";
    today.output();

    if (today.month == birthday.month && today.day == birthday.day)
    {
        cout << "Happy birthday!\n";
    }
    else
    {
        cout << "Good day!\n";
    }

    return 0;
}

void DayOfYear::output()
{
    cout << "month = " << month
        << ", day = " << day << endl;
}


