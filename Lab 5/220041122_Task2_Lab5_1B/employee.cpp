#include "employee.h"

Employee::Employee() : name("John Doe"), dateOfBirth("2002-01-01"), salary(10000) {}

string Employee::getName() const {
    return name;
}

string Employee::getDateOfBirth() const {
    return dateOfBirth;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setName(const string& newName) {
    if (newName.length() > 2) {
        name = newName;
    }
    else {
        name = "John Doe";
    }
}

void Employee::setDateOfBirth(const string& dob) {
    int birthYear = stoi(dob.substr(0, 4));
    int currentYear = 2024;

    if (currentYear - birthYear > 18) {
        dateOfBirth = dob;
    }
    else {
        dateOfBirth = "2002-01-01";
    }
}

void Employee::setSalary(double sal) {
    if (sal >= 10000 && sal <= 100000) {
        salary = sal;
    }
    else {
        salary = 10000;
    }
}

void Employee::setInfo() {
    string inputName, inputDOB;
    double inputSalary;

    getline(cin, inputName);
    setName(inputName);

    getline(cin, inputDOB);
    setDateOfBirth(inputDOB);

    cin >> inputSalary;
    setSalary(inputSalary);
    cin.ignore();
}

void Employee::getInfo() const {
    cout << "Name: " << getName() << endl;
    cout << "Date of Birth: " << getDateOfBirth() << endl;
    cout << "Salary: " << getSalary() << endl;
}


Employee Employee::compareAge(const Employee& e) const {
    int currentYear = stoi(dateOfBirth.substr(0, 4));
    int otherYear = stoi(e.dateOfBirth.substr(0, 4));

    if (currentYear < otherYear) {
        return e;
    }
    return *this;
}



