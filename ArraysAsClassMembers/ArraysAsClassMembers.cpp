// ArraysAsClassMembers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_LIST_SIZE = 50;

class TemperatureList
{
public:
	TemperatureList();

	void addTemperature(double temperature);

	bool full() const;

	int getSize();
	double getTemperature(int position);

	friend  ostream& operator <<(ostream& outs,
		const TemperatureList& theObject);
	//Overloads the << operater so it can be used to output values of 
	//type TemperatureList.Temperatures are output one per line.
	//Precondition:If outs is a file output stream,then outs
	//has already been connected to a file.

private:
	double list[MAX_LIST_SIZE];
	int size;

};


int main()
{
}

TemperatureList::TemperatureList() :size(0)
{
}

void TemperatureList::addTemperature(double temperature)
{
	if (full())
	{
		cout << "Error: adding to a full list\n";
		exit(1);
	}
	else
	{
		list[size] = temperature;
		size++;
	}
}

bool TemperatureList::full() const
{
	return (size == MAX_LIST_SIZE);
}

int TemperatureList::getSize()
{
	return size;
}

double TemperatureList::getTemperature(int position)
{
	if ((0 <= position) && (position < MAX_LIST_SIZE))
	{
		return (list[position]);
	}
	else
	{
		cout << "Error: "
			<< " reading an empty list position.\n";
		exit(1);
	}
}

ostream& operator<<(ostream& outs, const TemperatureList& theObject)
{
	for (int i = 0; i < theObject.size; i++)
		outs << theObject.list[i] << "F\n";

	return outs;
}
