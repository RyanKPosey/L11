/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/29/2025
*/

#include "professorType.h"
#include <iostream>
#include <string>

using namespace std;

/* Implementation of the professorType class. Doxygen comments removed from
   this translation unit as requested; documentation is kept in the header. */

// Default constructor
professorType::professorType()
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

// Constructor with first and last name
professorType::professorType(const std::string& first, const std::string& last)
    : personType(first, last)
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

// Full constructor
professorType::professorType(const std::string& first, const std::string& last,
                           const std::string& addr, double heightIn,
                           const std::string& dob, char gender, unsigned age,
                           const std::string& employeeID,
                           const std::string& department,
                           const std::string& degree)
    : personType(first, last, addr, heightIn, dob, gender, age)
{
    setEmployeeID(employeeID);
    setDepartment(department);
    setDegree(degree);
}

// Setters
void professorType::setEmployeeID(const std::string& id) {
    employeeID = id;
}

void professorType::setDepartment(const std::string& dept) {
    department = dept;
}

void professorType::setDegree(const std::string& deg) {
    degree = deg;
}

// Getters
std::string professorType::getEmployeeID() const {
    return employeeID;
}

std::string professorType::getDepartment() const {
    return department;
}

std::string professorType::getDegree() const {
    return degree;
}

// Print
void professorType::print() const {
    personType::print();
    cout << "\tEmployee ID: " << employeeID << endl;
    cout << "\tDepartment: " << department << endl;
    cout << "\tDegree: " << degree << endl;
}

// Equals
bool professorType::equals(const professorType& other) const {
    return personType::equals(other) &&
           employeeID == other.employeeID &&
           department == other.department &&
           degree == other.degree;
}