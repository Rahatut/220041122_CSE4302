#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
private:
    float abscissa;
    float ordinate;

public:
    Coordinate();
    Coordinate(float x, float y);
    ~Coordinate();
    void display() const;
    float getDistance() const;
    float operator-(const Coordinate& c) const;
    void move_x(float val);
    void move_y(float val);
    void move(float x_val, float y_val);
    bool operator>(const Coordinate& c) const;
    bool operator<(const Coordinate& c) const;
    bool operator>=(const Coordinate& c) const;
    bool operator<=(const Coordinate& c) const;
    bool operator==(const Coordinate& c) const;
    bool operator!=(const Coordinate& c) const;
};

#endif
