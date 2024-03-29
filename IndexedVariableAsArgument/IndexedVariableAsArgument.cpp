// IndexedVariableAsArgument.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int NUMBER_OF_EMPLOYEES = 3;

int adjustDays(int oldDAys);
//Returns oldDays plus 5.

int main()
{
    using namespace std;

    int vacation[NUMBER_OF_EMPLOYEES], number;

    cout << "Enter allowed vacation days for employees 1"
        << " through " << NUMBER_OF_EMPLOYEES << ":\n";
    for (number = 1; number <= NUMBER_OF_EMPLOYEES; number++)
        cin >> vacation[number - 1];
    for (number = 0; number < NUMBER_OF_EMPLOYEES; number++)
        vacation[number] = adjustDays(vacation[number]);
    cout << "The revised number of vacation days are:\n";
    for (number = 1; number <= NUMBER_OF_EMPLOYEES; number++)
        cout << "Employee number " << number
        << " vacation days = " << vacation[number - 1] << endl;

    return 0;
}

int adjustDays(int oldDAys)
{
    return (oldDAys + 5);
}


