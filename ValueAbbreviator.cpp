// ValueAbbreviator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Abbreviator.h"
#include "EValueType.h"

using namespace std;



void ShowMenu()
{
    cout << "\n******************\n";
    cout << "Value Abbreviator!\n";
    cout << "******************\n";
}


int main()
{
    char valToAbbreviate;
    int number;
    bool hasChosenType;

    
    Abbreviator abb;

    int menu;
    int chosenType;

    do
    {
        ShowMenu();
        switch (chosenType)
        {
        case 1:
            
            int T_val;
            T_val = abb.ChooseValueType();
            if (T_val == 0)
            {
                chosenType = 0;
                break;
            }
            else
            {
                chosenType = 2;
                break;
            }
            break;

        case 2:


            break;

        case 0:
            menu = 0;
            break;
        }

    } while (menu != 0);


    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
