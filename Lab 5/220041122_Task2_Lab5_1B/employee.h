#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee {
private:
    string name;
    string dateOfBirth;
    double salary;

public:
    Employee();

    string getName() const;
    string getDateOfBirth() const;
    double getSalary() const;

    void setName(const string& name);
    void setDateOfBirth(const string& dateOfBirth);
    void setSalary(double salary);

    void setInfo();
    void getInfo() const;
    Employee compareAge(const Employee& e) const;
};

#endif // EMPLOYEE_H

