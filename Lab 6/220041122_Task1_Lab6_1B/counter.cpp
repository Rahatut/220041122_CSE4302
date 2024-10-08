#include<iostream>
#include "counter.h"

using namespace std;

Counter::Counter(){

    count=0;
    incrementStep=1;

} //0 arg

Counter::Counter(int val){ //1 arg
    count = val;
}

void Counter::setIncrementStep(int step_val) {
    if (count == 0) {
        if (step_val > 0) {
            incrementStep = step_val;
        }
    }
    else {
         cout << "Cannot set increment step" <<  endl;
    }
}

int Counter::getCount() const {
    return count;
}

void Counter::increment() {
    count += incrementStep;
}

void Counter::resetCount(int step) {
    count = 0;
    if (step > 0) {
        incrementStep = step;
    }
    else {
        incrementStep = 1;
    }

}

Counter Counter::operator+(const Counter& c) const {
    if (incrementStep == c.incrementStep) {
        return Counter(count + c.count);
    }
    else {
         cout << "Increment steps are not same." <<  endl;
        return Counter();
    }
}

bool Counter::operator>(const Counter& c) const {
    return count > c.count;
}

bool Counter::operator<(const Counter& c) const {
    return count < c.count;
}

bool Counter::operator>=(const Counter& c) const {
    return count >= c.count;
}

bool Counter::operator<=(const Counter& c) const {
    return count <= c.count;
}

bool Counter::operator==(const Counter& c) const {
    return count == c.count;
}

bool Counter::operator!=(const Counter& c) const {
    return count != c.count;
}

Counter& Counter::operator+=(const Counter& c) {
    count += c.count;
   if (c.incrementStep > incrementStep) {
        incrementStep = c.incrementStep;
    }
    return *this;
}

Counter Counter::operator++(int) {
    Counter temp = *this;
    increment();
    return temp;
}

Counter& Counter::operator++() {
    increment();
    return *this;
}

void testFunction(const Counter& c) {
     cout << c.getCount() <<  endl;
}
