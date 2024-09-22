#include <iostream>
#include <string>
#include <stdexcept>

class Temperature {
private:
    double value;
    std::string unit;

public:
    // constructor to initialize temperature with value and unit
    Temperature(double val, const std::string& u) {
        assign(val, u);
    }

    // function to assign temperature value and unit
    void assign(double val, const std::string& u) {
        if (u != "Celsius" && u != "Fahrenheit" && u != "Kelvin") {
            throw std::invalid_argument("Invalid unit. Must be 'Celsius', 'Fahrenheit', or 'Kelvin'.");
        }

        if (u == "Kelvin" && val < 0) {
            throw std::invalid_argument("Temperature cannot be below absolute zero (0 K).");
        }
        else if (u == "Celsius" && val < -273.15) {
            throw std::invalid_argument("Temperature cannot be below absolute zero (-273.15 °C).");
        }
        else if (u == "Fahrenheit" && val < -459.67) {
            throw std::invalid_argument("Temperature cannot be below absolute zero (-459.67 °F).");
        }

        value = val;
        unit = u;
    }

    // function to convert temperature to the specified target unit
    double convert(const std::string& targetUnit) {
        if (targetUnit == unit) {
            return value;
        }

        double celsiusValue;
        // convert to Celsius first
        if (unit == "Celsius") {
            celsiusValue = value;
        }
        else if (unit == "Fahrenheit") {
            celsiusValue = (value - 32) * 5.0 / 9.0;
        }
        else { // Kelvin
            celsiusValue = value - 273.15;
        }

        // convert from Celsius to target unit
        if (targetUnit == "Fahrenheit") {
            return celsiusValue * 9.0 / 5.0 + 32;
        }
        else if (targetUnit == "Kelvin") {
            return celsiusValue + 273.15;
        }
        else {
            return celsiusValue; // Celsius
        }
    }

    // function to print the temperature in its current form
    void print() const {
        std::cout << "The temperature is " << value << " " << unit << "." << std::endl;
    }
};

int main() {
    try {
        Temperature temp(25, "Celsius");
        temp.print(); // output: The temperature is 25 Celsius.

        // convert to Fahrenheit
        double tempF = temp.convert("Fahrenheit");
        std::cout << "Converted to Fahrenheit: " << tempF << " °F" << std::endl; // output: Converted to Fahrenheit: 77 °F

        // convert to Kelvin
        double tempK = temp.convert("Kelvin");
        std::cout << "Converted to Kelvin: " << tempK << " K" << std::endl; // output: Converted to Kelvin: 298.15 K

        // attempting to set a temperature below absolute zero
        Temperature invalidTemp(-300, "Celsius"); // this will throw an exception

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

