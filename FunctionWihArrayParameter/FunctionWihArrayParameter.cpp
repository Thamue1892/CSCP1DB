// FunctionWihArrayParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void fillUp(int a[], int size);
//Precondition:size is the declared size of the array a.
//The user will type in size integers.
//Postcondition:The array a is filled with size integers from keyboard.

int main()
{

}

void fillUp(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    size--;

    cout << "The last array index used is " << size << endl;
}

