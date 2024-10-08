#include <iostream>
#include "counter.h"

using namespace std;

int main() {
    Counter c1, c2, c3;

    c1.setIncrementStep(5);
    c2.setIncrementStep(5);
    c3.setIncrementStep(10);

    c1.increment();
    c2.increment();
    c3.increment();

    testFunction(c1);
    testFunction(c2);
    testFunction(c3);

    c1 = c2 + c3;

    testFunction(c1);
    c1.resetCount();
    c1.setIncrementStep(2);
    c1.increment();
    testFunction(c1);

    c1 += c2;
    testFunction(c1);

    c1 = c2++;
    testFunction(c1);
    testFunction(c2);

    c1 = ++c2;
    testFunction(c1);
    testFunction(c2);

    Counter c4(10),c5(10);
    if(c4>c5)cout<<"c4 is greater than c5\n";
    if(c4<c5)cout<<"c4 is smaller than c5\n";
    if(c4<=c5)cout<<"c4 is smaller or equal to c5\n";
    if(c4>=c5)cout<<"c4 is greater or equal to c5\n";
    if(c4==c5)cout<<"c4 is equal to c5\n";
    if(c4!=c5)cout<<"c4 is not equal to c5\n";


    return 0;
}
