#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinates.h"

using namespace std;

void randomAssignment(Coordinate c[], int size) {
    for (int i = 0; i < size; ++i) {
        float x = static_cast<float>(rand() % 50);
        float y = static_cast<float>(rand() % 50);
        c[i] = Coordinate(x, y);
    }
}

void sort(Coordinate c[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(c[j].getDistance() > c[j + 1].getDistance()) {
                Coordinate temp = c[j + 1];
                c[j + 1] = c[j];
                c[j] = temp;
            }
        }
    }
}


int main() {
    srand(static_cast<unsigned int>(time(0)));
    Coordinate coord[10];


    randomAssignment(coord, 10);

    for (int i = 0; i < 10; i++) {
        coord[i].display();
    }
    sort(coord, 10);
    cout<<"\nsorted:\n"<<endl;
    for (int i = 0; i < 10; i++) {
        coord[i].display();
    }

    if(coord[4]>coord[3])cout<<"c4 is greater than c3\n";
    if(coord[1]<coord[3])cout<<"c1 is smaller than c3\n";
    if(coord[2]<=coord[3])cout<<"c2 is smaller or equal to c3\n";
    if(coord[5]>=coord[3])cout<<"c5 is greater or equal to c3\n";
    if(coord[1]==coord[3])cout<<"c1 is equal to c3\n";
    if(coord[1]!=coord[3])cout<<"c1 is not equal to c3\n";

    cout<<"\n"<<coord[3]-coord[1]<<endl;


    return 0;
}



