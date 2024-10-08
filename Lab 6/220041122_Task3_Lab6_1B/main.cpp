#include "temperature.h"

int main() {
    Celsius c(100);
    c.display();

    Fahrenheit f = c;
    f.display();

    Kelvin k = c;
    k.display();

    Fahrenheit f2(32);
    f2.display();

    Celsius c2 = f2;
    c2.display();

    Kelvin k2 = f2;
    k2.display();

    Kelvin k3(473.15);
    k3.display();

    Celsius c3 = k3;
    c3.display();

    Fahrenheit f3 = k3;
    f3.display();

    Kelvin k4(-1);
    k4.display();


    k.assign(200);
    k.display();
    f.assign(-500);
    f.display();
    c.assign(-270.15);
    c.display();


    return 0;
}
