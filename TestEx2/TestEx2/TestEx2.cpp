// TestEx2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


int main()
{
    int Number;

    vector<int> NumberVector;

    cout << "Enter numbers-> ";

    while (cin >> Number)
    {
        NumberVector.push_back(Number);

        if (NumberVector.size() >= 10)
        {
            break;
        }

        if (cin.get() == '\n')
        {
            break;
        }
    }

    if (NumberVector.size() < 3)
    {
        cout << "\nPlease, enter at least three numbers!\n";
        return 0;
    }

    StartApp(NumberVector);

    return 0;
}

