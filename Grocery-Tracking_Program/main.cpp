/*
 * Grocery-Tracking Program
 *
 *  Date: 04-12-2023
 *  Author: Crailin Mogged
 */

#include <iostream>
#include "ItemFrequency.h"

using namespace std;


int getMenuOption()
{
    int optionNum;
    
    while (true)
    {
        if (cin >> optionNum) // check if cin successfully read an integer
        {
            if ((optionNum >= 0) && (optionNum <= 4)) // is the integer within range
            {
                while (cin.peek() != '\n') // ignore any other input
                cin.ignore();
                
                cin.ignore(); // ignore final '\n' character
                break;
            }
        }
        
        cout << "Invalid input. Please try again." << endl;
        cin.clear();
        
        while (cin.peek() != '\n') // ignore the current input
        cin.ignore();
    }
    
    return optionNum;
}

void continueOnEnter()
{
    cout << "Press [Enter] to continue." << endl;

    while (cin.peek() != '\n') // ignore the current input
    cin.ignore();
}

int main()
{
    ItemFrequency itemFreq;
    int exit = false;
    
    // print item frequency list to file
    if (itemFreq.itemFrequencyToFile())
    {
        cout << "Backup data file could not be written." << endl;
        return 1;
    }

    while (exit == false)
    {
        cout << "\nMain Menu" << endl;
        cout << "Enter '1' to find frequency of item purchased." << endl;
        cout << "Enter '2' to print an item frequency list." << endl;
        cout << "Enter '3' to print a histogram of item frequency." << endl;
        cout << "Enter '4' to exit program." << endl;
        cout << endl;

        switch (getMenuOption()) {
        case 1:
            itemFreq.getItemFrequency();
            continueOnEnter();
            break;
        case 2:
            itemFreq.itemFrequencyList();
            continueOnEnter();
            break;
        case 3:
            itemFreq.itemHistogram();
            continueOnEnter();
            break;
        case 4:
            exit = true;
            break;
        }
    }

    return 0;
}

