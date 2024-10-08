#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>

class Celsius;
class Fahrenheit;
class Kelvin;

class Celsius {
private:
    float temperature;

public:
    Celsius();
    Celsius(float temp);
    void assign(float temp);
    void display() const;
    operator Fahrenheit() const;
    operator Kelvin() const;
};

class Fahrenheit {
private:
    float temperature;

public:
    Fahrenheit();
    Fahrenheit(float temp);
    void assign(float temp);
    void display() const;
    operator Celsius() const;
    operator Kelvin() const;
};

class Kelvin {
private:
    float temperature;

public:
    Kelvin();
    Kelvin(float temp);
    void assign(float temp);
    void display() const;
    operator Celsius() const;
    operator Fahrenheit() const;
};

#endif

