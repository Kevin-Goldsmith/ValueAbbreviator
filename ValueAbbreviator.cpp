// ValueAbbreviator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Abbreviator.h"
#include "EValueType.h"
#include "E_UI_Phases.h"

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

    int menu = 1;
    int phaseIndex = 1;
    
    Phases curPhase = Phases::ChooseType;

    do
    {
        switch (curPhase)
        {
        case ChooseType:
            
            ShowMenu();

            int T_val;
            T_val = abb.ChooseValueType();
            if (T_val == 0)
            {
                curPhase = Phases::Exit;
                break;
            }
            else
            {
                curPhase = Phases::EnterAmt;
                break;
            }
            break;

        case EnterAmt:

            switch (abb.InputValueToAbbreviate())
            {
            case 3:
                curPhase = Phases::Encore;
                break;

            case 0:
                curPhase = Phases::Exit;
                break;
            }
            break;

        case Encore:

            int encoreIndex;

            cout << "\n******************************************\n";
            cout << "Press 1 if you want to try another number\n";
            cout << "Press 2 if you want to return to main menu\n";
            cout << "Press 0 if you want to exit\n";
            cin >> encoreIndex;

            switch (encoreIndex)
            {
            case 1:
                curPhase = Phases::EnterAmt;
                break;

            case 2:
                curPhase = Phases::ChooseType;
                break;

            case 0:
                curPhase = Phases::Exit;
                break;

            default:
                cout << "Invalid response. Try Again!\n";
                break;
            }
            break;

        case Exit:

            cout << "\nSee you next time :)\n";
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
