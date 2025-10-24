/*
    Programmer: Ryan Posey
    Assignment: L10.D
    Purpose: Practice using constructors
    Due date: 10/16/2025
*/
#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <cstdint>
#include <string>
#include <vector>

class personType { 
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    double height_inches_{};
    std::string date_of_birth_;  
    char gender_{}; 
    uint16_t age_{};

public:
    // Constructors
    personType(
        const std::string& firstName, const std::string& lastName, const std::string& address, 
        double height, const std::string& DOB, char gender, uint16_t age
    ); // Full constructor

    personType(const std::string& firstName, const std::string& lastName); // First+Last constructor

    personType(); // Default constructor

    // Destructor
    ~personType();

    void print() const;
    bool equals(const personType& other) const;

    // Setters
    void setName(const std::string& name);               // accepts "First Last" (splits)
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setAddress(const std::string& address);
    void setHeight(double height);
    void setDOB(const std::string& DOB);
    void setGender(char gender);
    void setAge(uint16_t age);

    // Getters
    std::string getName() const;         // returns "First Last"
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    double getHeight() const;
    std::string getDOB() const;
    char getGender() const;
    uint16_t getAge() const;

    static int getTallest(const std::vector<personType>& people);
    static int getOldest(const std::vector<personType>& people);
    static int getYoungest(const std::vector<personType>& people);
};

#endif // PERSON_TYPE_H