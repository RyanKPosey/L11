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
studentType::studentType()
{
        //cout << "Default StudentType constructor called" << endl;
        setID("NOT SET");
        setClassification("NOT SET");
        setGPA(0.0);
}


/**
 * @brief Constructor initializing first and last name.
 * @brief Style #2
 * @param first First name.
 * @param last Last name.
 */
studentType::studentType(const string first, const string last)
        : personType(first, last)
{/** CODE BLOCK **/
        //cout << getFirstName() << " " << "studentType constructor called" << endl;
        setID("NOT SET");
        setClassification("NOT SET");
        setGPA(0.0);
}


studentType::studentType(const string first, const string last, const double g, const string i, const string c)
        : personType(first, last)
{/** CODE BLOCK **/
        setID(i);
        setClassification(c);
        setGPA(g);
        //cout << "First Name, Last Name, gpa, id, classification studentType constructor called" << endl;
}

 

studentType::~studentType(){
        //cout << "Inside studentType Destructor for: " << getFirstName() << endl;
}


// Setters
void studentType::setGPA(double g) {
        if (g < 0)
                g = 0;
        else
                if (g > 4.0)
                        g = 4.0;

        gpa = g;
}

void studentType::setID(const string ident) {
        id = ident;
}

void studentType::setClassification(const string cls) {
        classification = cls;
}

// Getters
double studentType::getGPA() const {
        return gpa;
}

string studentType::getID() const {
        return id;
}

string studentType::getClassification() const {
        return classification;
}

/**
 * @brief Prints all data members, including those inherited.
 */
void studentType::print() const {
        personType::print();
        cout << "\tID: " << id << endl;
        cout << "\tClassification: " << classification << endl;
        cout << "\tGPA: " << setprecision(2) << showpoint << gpa << endl;
}

/**
 * @brief Compares two studentType objects for equality.
 * @param other The other studentType object.
 * @return true if all fields match, false otherwise.
 */
bool studentType::equals(const studentType& other) const {
        return personType::equals(other) &&
                         id == other.id &&
                         classification == other.classification &&
                         gpa == other.gpa;
}