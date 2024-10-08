#include<iostream>
#include<string>

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
    SavingsAccount() : AnnualInterestRate(0.0), CurrentBalance(0.0), minimumBalance(0.0) {}

    void setAccName(const string &Name) {
        AccountName = Name;
    }

    void setAccHolderName(const string &Holder) {
        AccountHolderName = Holder;
    }

    void setAddress(const string &addr) {
            Address = addr;
    }

    void setAnnualInterestRate(double Rate) {
        AnnualInterestRate = Rate;
    }

    void setCurrentBalance(double Amount) {
        CurrentBalance = Amount;
        if (CurrentBalance < minimumBalance) minimumBalance = CurrentBalance;
    }

    string getAccName() const {
        return AccountName;
    }

    string getAccHolderName() const {
        return AccountHolderName;
    }

    string getAddress() const {
        return Address;
    }

    double getAnnualInterestRate() const {
        return AnnualInterestRate;
    }

    double getCurrentBalance() const {
        return CurrentBalance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            CurrentBalance += amount;
            cout << "Deposited " << amount << ". New Balance: " << CurrentBalance << endl;
        }
        else {
            cout << "Invalid amount deposited" << endl;
        }
    }

    void withdrawal(float amount) {
        if (amount > 0 && CurrentBalance >= amount) {
            CurrentBalance -= amount;
            cout << "Withdrew " << amount << ". New Balance: " << CurrentBalance << endl;
        }
        else {
            cout << "Invalid withdrawal." << endl;
        }
    }

    double calculateInterest(int periodInMonths) const {
        double monthlyRate = AnnualInterestRate / 12.0 / 100.0;
        return minimumBalance * monthlyRate * periodInMonths;
    }

    void disburseInterest(int periodInMonths) {
        double interest = calculateInterest(periodInMonths);
        deposit(interest);
        minimumBalance = CurrentBalance;
        cout << "Interest disbursed: " << interest << endl;
    }
};
