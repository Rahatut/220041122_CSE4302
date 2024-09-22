#include <iostream>

class Counter {
private:
    int count;           // to store the current count
    int incrementStep;   // to store the increment step

public:
    // constructor to initialize count and increment step
    Counter() : count(0), incrementStep(1) {}

    // function to set the increment step
    void setIncrementStep(int step) {
        incrementStep = step;
    }

    // function to get the current count
    int getCount() const {
        return count;
    }

    // function to increment the count by the increment step
    void increment() {
        count += incrementStep;
    }

    // function to reset the count to 0
    void resetCount() {
        count = 0;
    }
};

int main() {
    Counter myCounter;

    // setting the increment step to 5
    myCounter.setIncrementStep(5);

    // incrementing the count twice
    myCounter.increment(); // first increment, count should be 5
    myCounter.increment(); // second increment, count should be 10

    // getting the current count
    std::cout << "Current Count: " << myCounter.getCount() << std::endl; // output: 10

    // resetting the count
    myCounter.resetCount();
    std::cout << "Count after reset: " << myCounter.getCount() << std::endl; // output: 0

    return 0;
}

