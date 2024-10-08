#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "savingsacc.h"

using namespace std;

void EditInformationByKeyboard(SavingsAccount &account) {
    string input;
    string addresss;
    double value;

    cout << "Enter Account Name: ";
    getline(cin, input);
    account.setAccountName(input);

    cout << "Enter Account Holder's Name: ";
    getline(cin, input);
    account.setAccountHolderName(input);

    cout << "Enter Address (type '/' on a new line to finish): ";
    while (true) {
            getline(cin, input);
            if (input == "/") break;
            addresss+= input + "\n";
        }
    account.setAddress(addresss);

    cout << "Enter Annual Interest Rate (%): ";
    cin >> value;
    account.setAnnualInterestRate(value);

    cout << "Enter Current Balance: ";
    cin >> value;
    account.setCurrentBalance(value);

    cin.ignore();
}

string generateRandomString(int minLength, int maxLength) {
    const string chars = "abcdefghijklmnopqrstuvwxyz";
    string randomString;
    int length = rand() % (maxLength - minLength + 1) + minLength;
    for (int i = 0; i < length; ++i) {
        randomString += chars[rand() % chars.length()];
    }
    return randomString;
}

double generateRandomDouble(double min, double max) {
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

void generateInformationRandom(SavingsAccount &account) {
    string accountName = generateRandomString(4, 10) + " " + generateRandomString(4, 10);
    account.setAccountName(accountName);

    string accountHolderName = generateRandomString(4, 10) + " " + generateRandomString(4, 10);
    account.setAccountHolderName(accountHolderName);

    string address = generateRandomString(4, 10) + " " + generateRandomString(4, 10) + " " +
                     generateRandomString(4, 10) + " " + generateRandomString(4, 10) + " " +
                     generateRandomString(4, 10);
    account.setAddress(address);

    double interestRate = generateRandomDouble(2.0, 5.0);
    account.setAnnualInterestRate(interestRate);

    double currentBalance = generateRandomDouble(1000, 50000);
    account.setCurrentBalance(currentBalance);
}

void ShowInterestAll(SavingsAccount accounts[]) {
    for (int i = 0; i < 100; ++i) {
        double interest = accounts[i].calculateInterest(12);
        cout << "Account: " << accounts[i].getAccountName() << " - Interest: " << interest << endl;
    }

    char confirmation;
    cout << "Confirm disbursement? (y/n): ";
    cin >> confirmation;

    if (confirmation == 'y') {
        for (int i = 0; i < 100; ++i) {
            accounts[i].disburseInterest(12);
        }
    }
}

void ShowAllAlphabetically(SavingsAccount accounts[]) {
    for (int i = 0; i < 100 - 1; ++i) {
        for (int j = 0; j < 100 - i - 1; ++j) {
            if (accounts[j].getAccountName() > accounts[j + 1].getAccountName()) {
                SavingsAccount temp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        cout << "Account: " << accounts[i].getAccountName() << " - Balance: "
             << accounts[i].getCurrentBalance() << endl;
    }
}

int main() {
    srand(time(0));
    SavingsAccount accounts[100];

    for (int i = 0; i < 2; ++i) {
        EditInformationByKeyboard(accounts[i]);
    }

    for (int i = 2; i < 100; ++i) {
        generateInformationRandom(accounts[i]);
    }

    ShowInterestAll(accounts);
    ShowAllAlphabetically(accounts);

    return 0;
}
