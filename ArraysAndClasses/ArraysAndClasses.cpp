// ArraysAndClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Money
{
public:
	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);

	Money(long dollars, int cents);
	Money(long dollars);
	Money();

	double getValue() const;

	friend istream& operator >>(istream& ins, Money& amount);
	friend ostream& operator <<(ostream& outs, Money& amount);

private:
	long allCents;
};

int digitToInt(char c)
{
	return (static_cast<int>(c) - static_cast<int>('0'));
}

Money operator +(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents + amount2.allCents;
	return temp;
}

Money operator-(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents - amount2.allCents;
	return temp;
}

Money operator-(const Money& amount)
{
	Money temp;
	temp.allCents = -amount.allCents;
	return temp;
}


bool operator ==(const Money& amount1, const Money& amount2)
{
	return (amount1.allCents == amount2.allCents);
}

bool operator<(const Money& amount1, const Money& amount2)
{
	return (amount1.allCents < amount2.allCents);
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

Money::Money(long dollars) :allCents(dollars*100)
{
}

Money::Money() :allCents(0)
{

}

double Money::getValue() const
{
	return (allCents * 0.01);
}

istream& operator>>(istream& ins, Money& amount)
{
	char oneChar, decimalPoint,
		digit1, digit2;	//digits for the amount of cents

	long dollars;
	int cents;
	bool negative;

	ins >> oneChar;
	if (oneChar == '-')
	{
		negative = true;
		ins >> oneChar; //read '$'
	}
	else
		negative = false;
	//If input is legal,then oneChar == '$'

	ins >> dollars >> decimalPoint >> digit1 >> digit2;

	if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input\n";
		exit(1);
	}

	cents = digitToInt(digit1) * 10 + digitToInt(digit2);

	amount.allCents = dollars * 100 + cents;
	if (negative)
		amount.allCents = -amount.allCents;
	return ins;
}

ostream& operator<<(ostream& outs, Money& amount)
{
	long positiveCents, dollars, cents;
	positiveCents = labs(amount.allCents);
	dollars = positiveCents / 100;
	cents = positiveCents % 100;

	if (amount.allCents < 0)
		outs << "-$" << dollars << '.';
	else
		outs << "$" << dollars << '.';

	if (cents < 10)
		outs << '0';
	outs << cents;

	return outs;
}





int main()
{
	Money amount[5], max;
	int i;

	cout << "Enter 5 amounts of money:\n";
	cin >> amount[0];
	max = amount[0];

	for (i = 1; i < 5; i++)
	{
		cin >> amount[i];
		if (max < amount[i])
			max = amount[i];
	}

	Money difference[5];
	for (i = 0; i < 5; i++)
		difference[i] = max - amount[i];

	cout << "The highest amount is " << max << endl;
	cout << "The amount and their\n"
		<< "differences from the largest are:\n";
	for (i = 0; i < 5; i++)
	{
		cout << amount[i] << " off by "
			<< difference[i] << endl;
	}

	return 0;
}

