#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

class Counter {
private:
    int count;
    int incrementStep;

public:
    Counter();
    Counter(int count_val);
    void setIncrementStep(int step_val);
    int getCount() const;
    void increment();
    void resetCount(int step = 1);
    Counter operator+(const Counter& c) const;
    bool operator>(const Counter& c) const;
    bool operator<(const Counter& c) const;
    bool operator>=(const Counter& c) const;
    bool operator<=(const Counter& c) const;
    bool operator==(const Counter& c) const;
    bool operator!=(const Counter& c) const;
    Counter& operator+=(const Counter& c);
    Counter operator++(int);
    Counter& operator++();
    friend void testFunction(const Counter& c);
};

#endif
