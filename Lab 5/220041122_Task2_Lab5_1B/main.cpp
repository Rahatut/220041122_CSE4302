#include <iostream>
#include "employee.h"

using namespace std;

int main() {
    Employee emp1, emp2;

    cout << "Enter information for Employee 1:" << endl;
    emp1.setInfo();

    cout << "\nEnter information for Employee 2:" << endl;
    emp2.setInfo();

    cout << "\nEmployee 1 Information:" << endl;
    emp1.getInfo();

    cout << "\nEmployee 2 Information:" << endl;
    emp2.getInfo();

    Employee elder = emp1.compareAge(emp2);
    cout << "\nElder Employee Information:" << endl;
    elder.getInfo();

    return 0;
}
