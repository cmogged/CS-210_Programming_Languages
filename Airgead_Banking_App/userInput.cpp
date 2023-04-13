/*
 * Airgead Banking App
 *
 *  Date: 04-01-2023
 *  Author: Crailin Mogged
 */

#include <iostream>
#include <iomanip>
#include "userInput.h"

using namespace std;


double userInput::getUserInputUInt()
{
    unsigned int i;
    string input_str;
    bool is_int = false;
    
    while (is_int == false)
    {
        // get user input
        getline(cin, input_str, '\n');
        
        // check if input is an unsigned floating point
        if (input_str.size())
        is_int = true;
        
        for (i=0; i < input_str.size(); i++)
        if ( !isdigit(input_str.at(i)) ) // check if digit is a number
        is_int = false;
        
        if (is_int == false)
        cout << "Invalid input." << endl;
    }

    // convert string to integer and return
    return stoi(input_str);
}

double userInput::getUserInputUDouble()
{
    unsigned int i;
    string input_str;
    int decimalPointCnt;
    bool is_float = false;
    
    while (is_float == false)
    {
        // get user input
        getline(cin, input_str, '\n');
        
        // check if input is an unsigned floating point
        if (input_str.size())
        is_float = true;
        
        decimalPointCnt = 0;
        for (i=0; i < input_str.size(); i++)
        {
            if ( !isdigit(input_str.at(i)) ) // check if digit is a number
            {
                if (input_str.at(i) == '.') // create decimal exception
                {
                    decimalPointCnt++;
                    
                    if (decimalPointCnt > 1) // check that it only has one decimal point
                    is_float = false;
                    
                    if (input_str.size() == 1) // check for digits
                    is_float = false;
                }
                else
                is_float = false;
            }
        }
        
        if (is_float == false)
        cout << "Invalid input." << endl;
    }

    // convert string to double and return
    return stod(input_str);
}

void userInput::getUserData(double &initialInvestment, double &monthlyDeposit, double &interestRate, int &numberOfYears)
{
    string any_input;
    
    // get input data from user
    cout << "\n******************************************" << endl;
    cout << "**************** Welcome *****************" << endl;
    cout << "Please enter initial investment amount:" << endl;
    initialInvestment = getUserInputUDouble();
    cout << "Please enter monthly deposit:" << endl;
    monthlyDeposit = getUserInputUDouble();
    cout << "Please enter annual interest:" << endl;
    interestRate = getUserInputUDouble();
    cout << "Please enter number of years:" << endl;
    numberOfYears = getUserInputUInt();
    cout << "******************************************\n" << endl;
    
    // display user entered data
    cout << "******************************************" << endl;
    cout << "************** Given Amounts *************" << endl;
    cout << fixed << setprecision(2) << "Initial Investment Amount: " << initialInvestment << endl;
    cout << "Monthly Deposit: " << monthlyDeposit << endl;
    cout << "Annual Interest: " << interestRate << endl;
    cout << setprecision(0) << "Number of Years: " << numberOfYears << endl;
    cout << "******************************************" << endl;
    cout << "Press [Enter] to continue . . ." << endl;
    getline(cin, any_input, '\n');
}

