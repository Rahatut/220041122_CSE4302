#ifndef SAVINGSACC_H
#define SAVINGSACC_H

#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string AccountName;
    string AccountHolderName;
    string Address;
    double AnnualInterestRate;
    double CurrentBalance;
    double minimumBalance;

public:
    SavingsAccount();

    void setAccountName(const string &Name);
    void setAccountHolderName(const string &Holder);
    void setAddress(const string &addr);
    void setAnnualInterestRate(double Rate);
    void setCurrentBalance(double Amount);

    string getAccountName() const;
    string getAccountHolderName() const;
    string getAddress() const;
    double getAnnualInterestRate() const;
    double getCurrentBalance() const;

    void deposit(double amount);
    void withdrawal(double amount);
    double calculateInterest(int periodInMonths) const;
    void disburseInterest(int periodInMonths);
};

void EditInformationByKeyboard(SavingsAccount &account);
void generateInformationRandom(SavingsAccount &account);
void ShowInterestAll(SavingsAccount accounts[]);
void ShowAllAlphabetically(SavingsAccount accounts[]);

#endif
