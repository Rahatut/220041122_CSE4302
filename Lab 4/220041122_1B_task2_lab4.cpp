#include <iostream>
#include <string>
using namespace std;

class Flight {
private:
    int Flightnumber;
    string Destination;
    float Distance;
    float MaxFuelCapacity;

    double CalFuel() const {
        if (Distance <= 1000)
            return 500;
        else if (Distance > 1000 && Distance <= 2000)
            return 1100;
        else
            return 2200;
    }

public:
    void FeedInfo() {
        cout << "Enter Flight Number: ";
        cin >> Flightnumber;
        cout << "Enter Destination: ";
        cin.ignore();
        getline(cin, Destination);
        cout << "Enter Distance: ";
        cin >> Distance;
        cout << "Enter Maximum Fuel Capacity: ";
        cin >> MaxFuelCapacity;
    }

    void ShowInfo() const {
        cout << "Flight Number: " << Flightnumber << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << Distance << " km" << endl;
        cout << "Maximum Fuel Capacity: " << MaxFuelCapacity << " liters" << endl;

        double requiredFuel = CalFuel();
        cout << "Fuel required for this flight: " << requiredFuel << " liters" << endl;
        cout<<endl;
        if (MaxFuelCapacity >= requiredFuel)
            cout << "Fuel capacity is fit for this flight distance." << endl;
        else
            cout << "Not sufficient Fuel Capacity for this flight." << endl;
    }
};

int main() {
    Flight flight;
    cout<<endl;
    flight.FeedInfo();
    cout<<endl;
    flight.ShowInfo();

    return 0;
}

