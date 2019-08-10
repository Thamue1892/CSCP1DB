// BankAccountClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Class for bank account
class BankAccount
{
public:
	BankAccount(int dollars, int cents, double rate);
	BankAccount(int dollars, double rate);
	BankAccount();
	void set(int dollars, int cents, double rate);
	void set(int dollars, double rate);
	void update();
	double getBalance();
	double getRate();
	void output(ostream& outs);

private:
	double balance;
	double interestRate;
	double fraction(double percent);
};

int main()
{
	BankAccount account1(100, 2.3), account2;

	cout << "account1 initialized as follows:\n";
	account1.output(cout);
	cout << "account2 initialized as follows:\n";
	account2.output(cout);

	//Explit call to the constructor
	account1 = BankAccount(999, 99, 5.5);
	cout << "account1 reset to the following:\n";
	account1.output(cout);

	return 0;
}
BankAccount::BankAccount(int dollars, int cents, double rate)
{
	if ((dollars < 0) || (cents < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}
	balance = dollars + 0.01 * cents;
	interestRate = rate;
}
BankAccount::BankAccount(int dollars, double rate)
{
	if ((dollars < 0 || (rate < 0)))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}

	balance = dollars;
	interestRate = rate;
}
BankAccount::BankAccount() :balance(0), interestRate(0.0)
{
}

void BankAccount::set(int dollars, int cents, double rate)
{
	if ((dollars < 0) || (cents < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}
	balance = dollars + 0.01 * cents;
	interestRate = rate;
}

void BankAccount::set(int dollars, double rate)
{
	if ((dollars < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}
	balance = dollars;
	interestRate = rate;
}

void BankAccount::update()
{
	balance = balance + fraction(interestRate) * balance;
}

double BankAccount::fraction(double percentValue)
{
	return (percentValue / 100.0);
}

double BankAccount::getBalance()
{
	return balance;
}

double BankAccount::getRate()
{
	return interestRate;
}

void BankAccount::output(ostream& outs)
{
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);
	outs << "Account balance R" << balance << endl;
	outs << "Interest rate " << interestRate << "%" << endl;
}







