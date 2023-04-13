/*
 * Airgead Banking App
 *
 *  Date: 04-01-2023
 *  Author: Crailin Mogged
 */

#include <iostream>
#include <iomanip>
#include "userInput.h"
#include "calcShowBalance.h"

using namespace std;


int main()
{
    userInput ui;
    calcShowBalance showBal;
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numberOfYears;
    string input;
    bool exit = false;
    
    while (exit == false)
    {
        // get initial values
        ui.getUserData(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
        
        // calculate and display balance and interest information
        if (monthlyDeposit == 0)
        {
            cout << "******************************************************************" << endl;
            cout << "**** Balance and Interest Without Additional Monthly Deposits ****" << endl;
            cout << left << setfill(' ') << setw(20) << "Year";
            cout << left << setfill(' ') << setw(20) << "Year End Balance";
            cout << left << setfill(' ') << setw(20) << "Year End Interest" << endl;
            showBal.calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
            cout << "******************************************************************" << endl;
        }
        else
        {
            cout << "******************************************************************" << endl;
            cout << "***** Balance and Interest With Additional Monthly Deposits ******" << endl;
            cout << left << setfill(' ') << setw(20) << "Year";
            cout << left << setfill(' ') << setw(20) << "Year End Balance";
            cout << left << setfill(' ') << setw(20) << "Year End Interest" << endl;
            showBal.balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
            cout << "******************************************************************" << endl;
        }
        
        cout << "\nWould you like to try again?" << endl;
        cout << "Enter 'y' for yes or 'n' for no:" << endl;
        
        // exit program if 'y' character detected
        getline(cin, input, '\n');
        if (input != "y")
        exit = true;
    }
    
    return 0;
}

