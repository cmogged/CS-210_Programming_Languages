/*
 * Airgead Banking App
 *
 *  Date: 04-01-2023
 *  Author: Crailin Mogged
 */

#ifndef CALCSHOWBALANCE_H
#define CALCSHOWBALANCE_H

class calcShowBalance {
    public:
        double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
        double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
    private:
        void printDetails(int year, double yearEndBalance, double interestEarned);
};

#endif

