/*
 * Airgead Banking App
 *
 *  Date: 04-01-2023
 *  Author: Crailin Mogged
 */

#ifndef USERINPUT_H
#define USERINPUT_H

class userInput {
    public:
        void getUserData(double &initialInvestment, double &monthlyDeposit, double &interestRate, int &numberOfYears);
    private:
        double getUserInputUInt();
        double getUserInputUDouble();
};

#endif

