// Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct CDAccount
{
    double balance;
    double interestRate;
    int term;   //Months to maturity.
};

void getData(CDAccount& theAccount);


int main()
{
    CDAccount account;
    getData(account);

    double rateFraction, interest;
    rateFraction = account.interestRate / 100.0;
    interest = account.balance * rateFraction * (account.term / 12.0);
    account.balance = account.balance + interest;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "When your CD matures in "
         << account.term << " months,\n"
         << " it will have a balance of R"
         << account.balance <<endl;

    return 0;
}

void getData(CDAccount& theAccount)
{
    cout << "Enter account balance: R";
    cin >> theAccount.balance;
    cout << "Enter account interest rate: ";
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity\n"
         << "(must be 12 or fewer months): ";
    cin >> theAccount.term;
}


