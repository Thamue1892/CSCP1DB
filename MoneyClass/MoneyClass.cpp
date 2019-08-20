// MoneyClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money
{
public:
	friend Money add(const Money amount1, const Money amount2);
	//Precondition:amount1 and amount2 have been given values.
	//Returns the sum of the values of amount1 and amount2.

	friend bool equal(const Money amount1, const Money amount2);
	//Precondition:amount1 and amount2 have been given values.
	//Returns true if the amount1 and amount2 have the same value.
	//otherwise returns false

	Money(long dollars, int cents);

	Money(long dollars);

	Money();

	double getValue() const;
	//Precondition:The calling object has been given a value.
	//Returns the amount of money recorded in the data of the calling object.

	void input(istream& ins);
	//Precondition:If ins is a file input stream,then ins has already been
	//connected to a file.An amount of money,including a dollar sign,has been
	//entered in the input stream ins.Notation for negative amount is -$100.00.
	//Postcondition:The value of the calling object has been set to
	//the amount of money read from the input stream ins.

	void output(ostream& outs) const;
	//Precondition:If outs is a file output stream,then outs has already been
	//connected to a file.
	//Postcondition:A dollar sign and the amount of money recorded
	//in the calling object have been sent to the output stream outs.

private:
	long allCents;
};

int digitToInt(char c);
//Function declaration for function used in the definition of Money::input:
//Precondition:c is onre of the digits '0' through '9'.
//Returns the integer for the digit:eg digitToInt('3') eturns 3.

int main()
{
	Money yourAmount, myAmount(10, 9), ourAmount;
	cout << "Enter an amount of money: ";
	yourAmount.input(cin);
	cout << "Your amount is ";
	yourAmount.output(cout);
	cout << endl;
	cout << "My amount is ";
	myAmount.output(cout);
	cout << endl;

	if (equal(yourAmount, myAmount))
		cout << "We have the same amounts.\n";
	else
		cout << "One of us is richer.\n";
	ourAmount = add(yourAmount, myAmount);
	yourAmount.output(cout);
	cout << " + ";
	myAmount.output(cout);
	cout << " equal ";
	ourAmount.output(cout);
	cout << endl;

	return 0;

}

Money add(const Money amount1, const Money amount2)
{
	Money temp;

	temp.allCents = amount1.allCents + amount2.allCents;
	return temp;
}

bool equal(const Money amount1, const Money amount2)
{
	return (amount1.allCents == amount2.allCents);
}

Money::Money(long dollars, int cents)
{
	if (dollars * cents < 0)//If one is negative and one is positive
	{
		cout << "Illegal values for dollars and cents.\n";
		exit(1);
	}
	allCents = dollars * 100 + cents;
}

Money::Money() :allCents(0)
{

}

double Money::getValue() const
{
	return (allCents * 0.01);
}

void Money::input(istream& ins)
{
	char oneChar, decimalPoint, digit1, digit2;
	long dollars;
	int cents;
	bool negative;

	ins >> oneChar;
	if (oneChar == ' ')
	{
		negative = true;
		ins >> oneChar; //read '$'

	}
	else
	{
		negative = false;

	}
	ins >> oneChar;
	//if input is legal,then oneChar == '$'

	ins >> dollars >> decimalPoint >> digit1 >> digit2;

	if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input\n";
		exit(1);
	}
	cents = digitToInt(digit1) * 10 + digitToInt(digit2);

	allCents = dollars * 100 + cents;
	if (negative)
		allCents = -allCents;
}

void Money::output(ostream& outs) const
{
	long positiveCents, dollars, cents;
	positiveCents = labs(allCents);
	dollars = positiveCents / 100;
	cents = positiveCents % 100;

	if (allCents < 0)
		outs << "-$" << dollars << '.';
	else
		outs << "$" << dollars << '.';

	if (cents < 10)
		outs << '0';

	outs << cents;
}

int digitToInt(char c)
{
	return (static_cast<int>(c) - static_cast<int>('0'));
}







