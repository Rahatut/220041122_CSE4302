#include<iostream>
#include "temperature.h"

using namespace std;

Celsius::Celsius() : temperature(0) {}

Celsius::Celsius(float temp) : temperature(temp) {
    if (temp < -273.15) {
       cout<< "Temperature below absolute zero\n";
        temperature = -273.15;
    }
}

void Celsius::assign(float temp) {
    if (temp >= -273.15)
        temperature = temp;
    else
        cout<< "Temperature below absolute zero\n";
}

void Celsius::display() const {
    cout << "The temperature is " << temperature << " Celsius.\n";
}

Celsius::operator Fahrenheit() const {
    return Fahrenheit(temperature * 9 / 5 + 32);
}

Celsius::operator Kelvin() const {
    return Kelvin(temperature + 273.15);
}


Fahrenheit::Fahrenheit() : temperature(32) {}

Fahrenheit::Fahrenheit(float temp) : temperature(temp) {
    if (temp < -459.67) {
        cout<< "Temperature below absolute zero\n";
        temperature = -459.67;
    }
}

void Fahrenheit::assign(float temp) {
    if (temp >= -459.67)
        temperature = temp;
    else
       cout<< "Temperature below absolute zero\n";
}

void Fahrenheit::display() const {
    cout << "The temperature is " << temperature << " Fahrenheit.\n";
}

Fahrenheit::operator Celsius() const {
    return Celsius((temperature - 32) * 5 / 9);
}

Fahrenheit::operator Kelvin() const {
    return Kelvin((temperature - 32) * 5 / 9 + 273.15);
}


Kelvin::Kelvin() : temperature(273.15) {}

Kelvin::Kelvin(float temp) : temperature(temp) {
    if (temp < 0) {
        cout<< "Temperature below absolute zero\n";
        temperature = 0;
    }
}

void Kelvin::assign(float temp) {
    if (temp >= 0)
        temperature = temp;
    else
        cout<< "Temperature below absolute zero\n";
}

void Kelvin::display() const {
   cout << "The temperature is " << temperature << " Kelvin.\n";
}

Kelvin::operator Celsius() const {
    return Celsius(temperature - 273.15);
}

Kelvin::operator Fahrenheit() const {
    return Fahrenheit((temperature - 273.15) * 9 / 5 + 32);
}

