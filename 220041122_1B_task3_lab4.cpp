#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string Num;
    string Name;
    string AccType;
    float CurrBalance;
    const float MinBalance;

    static int active;
    static int total;
    static float totTax;


public:

    BankAccount(string accNo, string holderName, string accType, float balance, float minBalance)
        : Num(accNo), Name(holderName), AccType(accType), CurrBalance(balance), MinBalance(minBalance) {
        total++;
        active++;
    }

    void assign(string accNo, string holderName, string accType, float balance) {
        Num = accNo;
        Name = holderName;
        AccType = accType;
        CurrBalance = balance;
    }

    void ShowInfo() const {
        cout << "Account Holder: " << Name << endl;
        cout << "Account Number: " << Num << endl;
        cout << "Account Type: " << AccType << endl;
        cout << "Current Balance: " << CurrBalance << endl;
        cout << "Minimum Balance: " << MinBalance << endl;
    }

    void showBalance() const {
        cout << "Current Balance: " << CurrBalance << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            CurrBalance += amount;
            cout << "Deposited " << amount << ". New Balance: " << CurrBalance << endl;
        }
        else {
            cout << "Invalid amount" << endl;
        }
    }

    void withdrawal(float amount) {
        if (amount > 0 && (CurrBalance - amount) >= MinBalance) {
            CurrBalance -= amount;
            cout << "Withdrew " << amount << ". New Balance: " << CurrBalance << endl;
        }
        else {
            cout << "Invalid withdrawal." << endl;
        }
    }

    void giveInterest(float Rate = 3.0) {

        float interest = (CurrBalance * Rate) / 100;
        float srcTax = interest * 0.10;
        float netInterest = interest - srcTax;


        totTax += srcTax;
        deposit(netInterest);

        //cout << "Interest: " << interest << ", Source Tax: " << srcTax << ", Net Interest: " << netInterest << endl;
        //cout << "New Balance: " << CurrBalance << endl;
    }

    ~BankAccount() {
        cout << "Account of Mr. " << Name << " with account no " << Num << " is destroyed with a balance BDT " << CurrBalance << endl;
        active--;
    }

    static int getTotAcc(){
        return total;
    }

    static int getActiveAcc(){
        return active;
    }

    static float getTax(){
        return totTax;
    }

    float getBalance(){
        return CurrBalance;
    }

    string getHolderName(){
        return Name;
    }



};


void display_stat() {
    cout << "Total Bank Account created: " << BankAccount::getTotAcc() << endl;
    cout << "Total Bank Account present: " << BankAccount:: getActiveAcc()<< endl;
    cout << "Total source tax collected: " << BankAccount:: getTax()<< endl;
}

BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    return (A.getBalance() > B.getBalance()) ? A : B;
}

int main() {
    BankAccount account1("12345", "John Doe", "Savings", 10000, 500);
    BankAccount account2("67890", "Jane Smith", "Current", 15000, 1000);

    account1.ShowInfo();
    account1.deposit(2000);
    account1.withdrawal(500);
    account1.giveInterest();

    account2.ShowInfo();
    account2.deposit(3000);
    account2.withdrawal(2000);
    account2.giveInterest(5.0);

    display_stat();

    BankAccount larger = Larger(account1, account2);
    cout << "Account with larger balance belongs to " << larger.getHolderName() << " with balance BDT " << larger.getBalance() << endl;

    return 0;
}

