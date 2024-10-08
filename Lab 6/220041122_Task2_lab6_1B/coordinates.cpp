#include <iostream>
#include <cmath>
#include <cstdlib>
#include "coordinates.h"

using namespace std;

Coordinate::Coordinate() : abscissa(0), ordinate(0) {}

Coordinate::Coordinate(float x, float y) : abscissa(x), ordinate(y) {}

Coordinate::~Coordinate() {}

void Coordinate::display() const {
    cout << "Coordinate(" << abscissa << ", " << ordinate << ")\n";
}

float Coordinate::getDistance() const {
    return sqrt(abscissa * abscissa + ordinate * ordinate);
}

float Coordinate::operator-(const Coordinate& c) const {
    return sqrt(pow(c.abscissa - abscissa, 2) + pow(c.ordinate - ordinate, 2));
}

void Coordinate::move_x(float val) {
    abscissa += val;
}

void Coordinate::move_y(float val) {
    ordinate += val;
}

void Coordinate::move(float x_val, float y_val) {
    abscissa += x_val;
    ordinate += y_val;
}

bool Coordinate::operator>(const Coordinate& c) const {
    return getDistance() > c.getDistance();
}

bool Coordinate::operator<(const Coordinate& c) const {
    return getDistance() < c.getDistance();
}

bool Coordinate::operator>=(const Coordinate& c) const {
    return getDistance() >= c.getDistance();
}

bool Coordinate::operator<=(const Coordinate& c) const {
    return getDistance() <= c.getDistance();
}

bool Coordinate::operator==(const Coordinate& c) const {
    return getDistance() == c.getDistance();
}

bool Coordinate::operator!=(const Coordinate& c) const {
    return getDistance() != c.getDistance();
}


