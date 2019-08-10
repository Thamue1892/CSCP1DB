// Question_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Odometer
{
public:
	Odometer();
	Odometer(int km);
	void reset();
	void SetFuelEfficiency(double efficiency);
	int kilometersDriven(int km);
	double numberOfLiters();
	void display();

private:
	int kilometers;
	double fuelEfficiency;

};



int main()
{
	Odometer vehicle1(100),vehicle2;
	int kilometers = 50;
	vehicle1.SetFuelEfficiency(45.0);
	vehicle1.numberOfLiters();
	vehicle1.kilometersDriven(kilometers);
	vehicle1.display();


	return 0;

}

Odometer::Odometer() :kilometers(0), fuelEfficiency(0.0)
{
}

Odometer::Odometer(int km)
{
	kilometers = km;
}

void Odometer::reset()
{
	kilometers = 0;
}

void Odometer::SetFuelEfficiency(double efficiency)
{
	if (efficiency < 0)
	{
		cout << "Illegal values for fuel efficiency.\n";
		return;
	}

	fuelEfficiency = efficiency;
}

int Odometer::kilometersDriven(int km)
{
	kilometers = kilometers + km;
	return kilometers;
}

double Odometer::numberOfLiters()
{

	return (kilometers / fuelEfficiency);
}

void Odometer::display()
{
	cout << "For a car with a fuel efficiency of ";
	cout << fuelEfficiency << " km/l, the fuel consumed after ";
	cout << kilometers << " km is " << numberOfLiters();
	cout <<endl;

	cout << "After another "<< kilometersDriven(kilometers) << " km,";		 
	cout << numberOfLiters() <<" liter was used."<<endl;
}










