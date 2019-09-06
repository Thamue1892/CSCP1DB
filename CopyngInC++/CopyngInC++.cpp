// CopyngInC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class StringVar
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	StringVar(const char* string)
	{
		m_Size=strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer,string,m_Size);
		m_Buffer[m_Size] = 0;
	}

	friend  ostream& operator<<(ostream& stream,const StringVar& string_var);

	StringVar(const StringVar& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size+1];
		memcpy(m_Buffer,other.m_Buffer,m_Size + 1);
	}

	~StringVar()
	{
		delete[] m_Buffer;
	}

};

ostream& operator<<(ostream& stream,const StringVar& string_var)
{
	stream << string_var.m_Buffer;
	return stream;
}

int main()
{
   StringVar string = "Thaymes";
	StringVar second = string;
	cout <<string <<endl;
	cout <<second <<endl;

	return 0;
}
