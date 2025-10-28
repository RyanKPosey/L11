/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/29/2025
*/

#include <iostream>
#include <cctype>
#include <cstdint>
#include <iomanip>
#include "personType.h"

using namespace std;

personType::personType( // Full constructor
    const string& firstName, const string& lastName, const string& address, 
    double height, const string& DOB, char gender, uint16_t age
) {
    firstName_ = firstName;
    lastName_ = lastName;
    address_ = address;
    height_inches_ = height;
    date_of_birth_ = DOB;
    gender_ = gender;
    age_ = age;
}


personType::personType(const string& firstName, const string& lastName) { // First+Last constructor
    firstName_ = firstName;
    lastName_ = lastName;
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

personType::personType() { // Default constructor
    firstName_ = "Not Set";
    lastName_ = "";
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

personType::~personType() { // Destructor
    //cout << "Destructor has been called" << endl;
}


bool compareStringCaseInsensitive(const string& string1, const string& string2) { // Stretch 3 (Case Insensitive Comparison)
    if (string1.size() != string2.size()) { // string1 and string2 aren't the same size
        return false;
    }

    for (size_t i = 0; i < string1.size(); i++) {
        if (
            static_cast<unsigned char>(tolower(static_cast<unsigned char>(string1[i]))) !=
            static_cast<unsigned char>(tolower(static_cast<unsigned char>(string2[i])))
        ) {
            return false;
        }
    }
    return true;
}

void personType::print() const { // Stretch 2 (Formatted output)
    std::cout <<  left << setw(10) << " | Name: " << left << this->getName() << 
        left << setw(10) << " | Address: " << left << this->getAddress() << endl <<
        left << setw(10) << " | Height: " << left << std::fixed << std::setprecision(1) << this->getHeight() << " in" <<
        left << setw(10) << " | DOB: " << left << this->getDOB() << endl <<
        left << setw(10) << " | Gender: " << left << this->getGender() <<
        left << setw(10) << " | Age: " << left << static_cast<int>(this->getAge()) << endl;
}

bool personType::equals(const personType& other) const {
    // Circuited comparison
    if (!compareStringCaseInsensitive(this->getName(), other.getName())) {
        return false;
    }

    if (!compareStringCaseInsensitive(this->getAddress(), other.getAddress())) {
        return false;
    }

    if (this->getHeight() != other.getHeight())  {
        return false;
    }

    if (!compareStringCaseInsensitive(this->getDOB(), other.getDOB())) {
        return false;
    }

    if (
        static_cast<unsigned char>(tolower(static_cast<unsigned char>(this->getGender()))) != // Case insensitive
        static_cast<unsigned char>(tolower(static_cast<unsigned char>(other.getGender())))
    ) {
        return false;
    }

    if (this->getAge() != other.getAge()) {
        return false;
    }

    return true;
}

    // Setters

    void personType::setName(const string& name) {
        // Split into first and last at first whitespace. If none, store as first name.
        size_t pos = name.find_first_of(" \t");
        if (pos == string::npos) {
            firstName_ = name;
            lastName_.clear();
        } else {
            firstName_ = name.substr(0, pos);
            // skip multiple spaces/tabs
            size_t startLast = name.find_first_not_of(" \t", pos);
            if (startLast == string::npos) {
                lastName_.clear();
            } else {
                lastName_ = name.substr(startLast);
            }
        }
    }

    void personType::setFirstName(const string& firstName) {
        firstName_ = firstName;
    }

    void personType::setLastName(const string& lastName) {
        lastName_ = lastName;
    }

    void personType::setAddress(const string& address) {
        address_ = address;
    }

    void personType::setHeight(double height) {
        if (height < 0 || height > 120) {
            height = 0;
        }

        height_inches_ = height;
    }

    void personType::setDOB(const string& DOB) {
        date_of_birth_ = DOB;
    }

    void personType::setGender(char gender) {
        gender_ = gender;
    }

    void personType::setAge(uint16_t age) {
        if (age > 999) {
            age = 0;
        }

        age_ = static_cast<uint16_t>(age);
    }

    // Getters

    string personType::getName() const { 
        if (lastName_.empty()) return firstName_;
        return firstName_ + " " + lastName_; 
    }
    string personType::getFirstName() const { return firstName_; }
    string personType::getLastName() const { return lastName_; }
    string personType::getAddress() const { return address_; }
    double personType::getHeight() const { return height_inches_; }
    string personType::getDOB() const { return date_of_birth_; }
    char personType::getGender() const { return gender_; }
    uint16_t personType::getAge() const { return age_; }

int personType::getTallest(const vector<personType>& people) {
    if (people.empty()) return -1; // Return -1 if vector is empty
    size_t tallestIndex = 0;
    // Find tallest index
    for (size_t i = 1; i < people.size(); i++) { 
        if (people[i].getHeight() > people[tallestIndex].getHeight()) {
            tallestIndex = i;
        }
    }
    return static_cast<int>(tallestIndex); // Return int so compatible with iostream
}

int personType::getOldest(const vector<personType>& people) {
    if (people.empty()) return -1; // Return -1 if vector is empty
    size_t oldestIndex = 0;
    // Find oldest index
    for (size_t i = 1; i < people.size(); i++) {
        if (people[i].getAge() > people[oldestIndex].getAge()) {
            oldestIndex = i;
        }
    }
    return static_cast<int>(oldestIndex); // Return int so compatible with iostream
}

int personType::getYoungest(const vector<personType>& people) {
    if (people.empty()) return -1; // Return -1 if vector is empty
    size_t youngestIndex = 0;
    // Find youngest index
    for (size_t i = 1; i < people.size(); i++) {
        if (people[i].getAge() < people[youngestIndex].getAge()) {
            youngestIndex = i;
        }
    }
    return static_cast<int>(youngestIndex); // Return int so compatible with iostream
}