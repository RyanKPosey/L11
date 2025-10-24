#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H

#include "personType.h"
#include <string>

class studentType : public personType {
public:
    // constructors
    studentType();
    studentType(std::string fName, std::string lName);
    studentType(std::string fName, std::string lName, 
                 double gpa, std::string classification, 
                 std::string id);

    // setters
    void setGPA(double);
    void setID(std::string);
    void setClassification(std::string);

    // getters
    double getGPA() const;
    std::string getID() const;
    std::string getClassification() const;

    // overridden methods
    void print() const;
    bool equals(const studentType&) const;

private:
    std::string id;
    double gpa;
    std::string classification;
};
#endif // STUDENT_TYPE_H