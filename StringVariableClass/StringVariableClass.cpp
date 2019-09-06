// StringVariableClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class StringVar
{
public:
	StringVar(int size);

	StringVar();

	StringVar(const char a[]);

	StringVar(const StringVar& stringObject);
	//Copy constructor

	~StringVar();
	//Destructor:Returns all the dynamic memory used by the object to the freestore

	int length()const;

	void inputLine(istream& ins);

	friend ostream& operator <<(ostream& outs, const StringVar& theString);

private:
	char* value;
	//Pointer to dynamic array that holds the string value.

	int maxLength;
	//Declared max length of any string value.
};

void conversation(int maxNameSize);
//Carries on a conversation with the user.



int main()
{
	conversation(30);
	cout << "End of demonstration.\n";

	return 0;
}

StringVar::StringVar(int size) :maxLength(size)
{
	value = new char[maxLength];
	value[0] = '\0';
}

StringVar::StringVar() :maxLength(100)
{
	value = new char[maxLength ];
	value[0] = '\0';
}

StringVar::StringVar(const char a[]) :maxLength(strlen(a))
{
	value = new char[maxLength ];
	strcpy_s(value,maxLength, a);
}

StringVar::StringVar(const StringVar& stringObject) :maxLength(stringObject.length())
{
	value = new char[maxLength ];
	strcpy_s(value,maxLength, stringObject.value);
}

StringVar::~StringVar()
{
	delete[] value;
}

int StringVar::length() const
{
	return strlen(value);
}

void StringVar::inputLine(istream& ins) 
{
	ins.getline(value, maxLength );
}

void conversation(int maxNameSize)
{
	StringVar yourName(maxNameSize),ourName("Borg");

	cout <<"What is your name?\n";
	yourName.inputLine(cin);

	cout <<"We are "<< ourName <<endl;
	cout <<"We will meet again " <<yourName<<endl;
}

ostream& operator<<(ostream& outs, const StringVar& theString)
{
	outs << theString.value;
	return outs;
}



