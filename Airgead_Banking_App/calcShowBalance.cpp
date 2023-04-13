/*
 * Airgead Banking App
 *
 *  Date: 04-01-2023
 *  Author: Crailin Mogged
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "calcShowBalance.h"

using namespace std;


/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void calcShowBalance::printDetails(int year, double yearEndBalance, double interestEarned){

// you may wish to change this function when you bring it into your program
// for now please get it to work here

//       IMPORTANT TIPS:
// There should be two tabs in between each field
// Dollars should be printed to the second decimal place


/*
Example:
 1               	$110.00                 	$10.00

*/
// TODO: your code here to implement the method
// returns nothing, just prints output to cout
    cout << left << setfill(' ') << setw(20) << fixed << setprecision(2) << year;
    cout << left << setfill(' ') << setw(20) << fixed << setprecision(2) << yearEndBalance;
    cout << left << setfill(' ') << setw(20) << fixed << setprecision(2) << interestEarned << endl;
}


/**
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double calcShowBalance::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
  // you may wish to change this function when you bring it into your program
  // for now please get it to work here as specified

  //       IMPORTANT TIPS:
  // You should assume a working printDetails(int yearIndex, double balance, double interestEarnedThisYear) exists
  // printDetails should be called after each year
  // Compounding should be done monthly
  // Make sure to keep values to at least 2 decimal places
  // Make sure to divide the interest rate by 100 and by 12
  // Year begins with 1, not 0

  /*
  Example:for 100 initial, 10% interest, and 4 years
  Year            Year End Balance        Interest Earned
   1               	$110.47                 	$10.47
   2                $122.04                	    $11.57
   3               	$134.82                 	$12.78
   4              	$148.94                 	$14.12
  */
  // TODO: your code here to implement the method
    int i;
    double interestEarned;
    double yearEndBalance;
    double balanceHeld = initialInvestment;
    
    for (i=1; i <= numberOfYears; i++)
    {
        // calculate year end balance
        yearEndBalance = initialInvestment * pow(1 + interestRate / 100 / 12, 12 * i);
        
        // calculate interest earned
        interestEarned = yearEndBalance - balanceHeld;
        
        // print data
        printDetails(i, yearEndBalance, interestEarned);
        
        balanceHeld = yearEndBalance;// save balance for calculation
    }
    
  // return the final balance
    return yearEndBalance;
}


/**
 * Calculates and returns an end of year balance for a given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param monthlyDeposit dollar amount added into the investment each month
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double calcShowBalance::balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears){
// you may wish to change this function when you bring it into your program
// for now  please get it to work here as specified in this function header

//       IMPORTANT TIPS:
// You may assume a working printDetails(int yearIndex, double balance, double interestEarnedThisYear) exists
// printDetails should be called after each year
// Compounding should be done monthly
// Make sure to divide the interest rate by 100 and by 12
// This month’s deposit does not earn interest(until next month)
// Year begins with 1, not 0

/*
Example for 100 initial investment and 10% interest and $10 monthly payment:
Year            Year End Balance        Interest Earned
 1               	$236.13                 	$16.13
 2                  $386.51                	    $30.38
 3               	$552.64                 	$46.13
 4              	$736.16                 	$63.52
*/

// TODO: your code here to implement the method
    int i;
    double interestEarned = 0;
    double yearEndBalance;
    double balanceHeld = initialInvestment;
    double rPercent = interestRate / 100;
    
    for (i=1; i <= numberOfYears; i++)
    {
        // calculate year end balance
        yearEndBalance = initialInvestment * pow(1 + rPercent/12, 12 * i);
        yearEndBalance += monthlyDeposit * ((pow(1 + rPercent/12, 12 * i) - 1) / (rPercent/12));
        
        // calculate interest earned
        interestEarned = yearEndBalance - balanceHeld - monthlyDeposit*12;
        
        // print data
        printDetails(i, yearEndBalance, interestEarned);
        
        balanceHeld = yearEndBalance;// save balance for calculation
    }
    
// return the ending balance
    return yearEndBalance;
}

