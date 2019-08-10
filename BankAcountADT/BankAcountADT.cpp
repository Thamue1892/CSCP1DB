// BankAcountADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

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
	int dollarsPart;
	int centsPart;
	double interestRate;
	double fraction(double percent);
	double percent(double fractionValue);
};

int main()
{
	BankAccount account1(100, 2.3), account2;

	cout << "account1 initialized as follows:\n";
	account1.output(cout);
	cout << "accout2 initialized as follows:\n";
	account2.output(cout);

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
		exit(1);
	}
	dollarsPart = dollars;
	centsPart = cents;
	interestRate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate)
{
	if ((dollars < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		exit(1);
	}
	dollarsPart = dollars;
	interestRate = fraction(rate);
}

BankAccount::BankAccount() :dollarsPart(0), centsPart(0), interestRate(0.0)
{

}

double BankAccount::fraction(double percent)
{
	return (percent/100.0);
}

void BankAccount::update()
{
	double balance = getBalance();
	balance = balance + interestRate * balance;
	dollarsPart = static_cast<int>(floor(balance));
	centsPart = static_cast<int>(floor(balance - dollarsPart) * 100);
}

double BankAccount::getBalance()
{
	return (dollarsPart + 0.01 * centsPart);
}

double BankAccount::percent(double fractionValue)
{
	return (fractionValue * 100);
}

double BankAccount::getRate()
{
	return percent(interestRate);
}

void BankAccount::output(ostream& outs)
{
	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);
	outs << "Account balance R" << getBalance() << endl;
	outs << "Interest rate " << getRate() << "%" << endl;
}

void BankAccount::set(int dollars, int cents, double rate)
{
	if ((dollars < 0) || (cents < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}
	dollarsPart = dollars;
	centsPart = cents;
	interestRate = fraction(rate);
}

void BankAccount::set(int dollars, double rate)
{
	if ((dollars < 0) || (rate < 0))
	{
		cout << "Illegal values for money or interest rate.\n";
		return;
	}
	dollarsPart = dollars;
	interestRate = fraction(rate);
}













