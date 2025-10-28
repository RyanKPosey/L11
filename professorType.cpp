/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/23/2025
*/

#include "professorType.h"
#include <iostream>
using namespace std;

/**
 * @file studentType.cpp
 * @brief Implementation of the studentType class.
 */

#include "studentType.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Default constructor.
 * @brief Traditional Style
 */
professorType::professorType()
{
        //cout << "Default ProfessorType constructor called" << endl;
        setEmployeeID("NOT SET");
        setDepartment("NOT SET");
        setDegree("NOT SET");
}


/**
 * @brief Constructor initializing first and last name.
 * @brief Style #2
 * @param first First name.
 * @param last Last name.
 */
professorType::professorType(const string first, const string last)
        : personType(first, last)
{/** CODE BLOCK **/
        //cout << getFirstName() << " " << "professorType constructor called" << endl;
        setEmployeeID("NOT SET");
        setDepartment("NOT SET");
        setDegree("NOT SET");
        setGPA(0.0);
}


professorType::professorType(const string first, const string last, const string addr, double heightIn, const string dob, char gender, unsigned age, const string employeeID, const string department, const string degree)
        : personType(first, last, addr, heightIn, dob, gender, age)
{
        setEmployeeID(employeeID);
        setDepartment(department);
        setDegree(degree);
}
        //cout << "First Name, Last Name, gpa, id, classification studentType constructor called" << endl;
}

 

professorType::~professorType(){
        //cout << "Inside professorType Destructor for: " << getFirstName() << endl;
}


// Setters
void professorType::setEmployeeID(const string id) {
        employeeID = id;
}

void professorType::setDepartment(const string dept) {
        department = dept;
}

void professorType::setDegree(const string deg) {
        degree = deg;
}

void professorType::setEmployeeID(const string ident) {
        employeeID = ident;
}

void professorType::setDepartment(const string dept) {
        department = dept;
}

// Getters
string professorType::getEmployeeID() const {
        return employeeID;
}

string professorType::getDepartment() const {
        return department;
}

string professorType::getDegree() const {
        return degree;
}

string professorType::getEmployeeID() const {
        return employeeID;
}

string professorType::getDepartment() const {
        return department;
}

string professorType::getDegree() const {
        return degree;
}

/**
 * @brief Prints all data members, including those inherited.
 */
void professorType::print() const {
        personType::print();
        cout << "\tEmployee ID: " << employeeID << endl;
        cout << "\tDepartment: " << department << endl;
        cout << "\tDegree: " << degree << endl;
}

/**
 * @brief Compares two professorType objects for equality.
 * @param other The other professorType object.
 * @return true if all fields match, false otherwise.
 */
bool professorType::equals(const professorType& other) const {
        return personType::equals(other) &&
                         employeeID == other.employeeID &&
                         department == other.department &&
                         degree == other.degree;
}