#include <iostream>
using namespace std;

class Calculator {
private:
    int currentStatus;

    int getCurrentStatus() const {
        return currentStatus;
    }

    void setCurrentStatus(int status) {
        currentStatus = status;
    }

public:
    Calculator() : currentStatus(0) {}

    Calculator(int initialStatus) : currentStatus(initialStatus) {}

    ~Calculator() {
        cout << endl;
    }

    void add(int value) {
        setCurrentStatus(getCurrentStatus() + value);
    }

    void subtract(int value) {
        setCurrentStatus(getCurrentStatus() - value);
    }

    void multiply(int value) {
        setCurrentStatus(getCurrentStatus() * value);
    }

    int divideBy(int value) {
        if (value == 0) {
            cout << "Invalid arithmetic operation." << endl;
            return getCurrentStatus();
        }
        else {
            int remainder = getCurrentStatus() % value;
            setCurrentStatus(getCurrentStatus() / value);
            return remainder;
        }
    }

    void clear() {
        setCurrentStatus(0);
    }

    void display() const {
        cout << "Calculator display: " << getCurrentStatus() << endl;
    }
};

int main() {
    Calculator calc;

    calc.add(10);
    calc.display();

    calc.add(7);
    calc.display();

    calc.multiply(31);
    calc.display();

    calc.subtract(42);
    calc.display();

    calc.divideBy(7);
    calc.display();

    calc.divideBy(0);  // Invalid operation since divided by 0
    calc.display();

    calc.add(3);
    calc.display();

    calc.clear();
    calc.display();

    // Destructor will be automatically called at the end of the scope
    return 0;
}

