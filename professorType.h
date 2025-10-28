/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/23/2025
*/

#ifndef PROFESSOR_TYPE_H
#define PROFESSOR_TYPE_H
#include "personType.h"
#include <string>

class professorType : public personType {
public:
    professorType();
    professorType(const std::string& f, const std::string& l);
    professorType(const std::string& f, const std::string& l,
                  const std::string& addr, double heightIn,
                  const std::string& dob, char gender, unsigned age,
                  const std::string& employeeID,
                  const std::string& department,
                  const std::string& degree);

    void setEmployeeID(const std::string&);
    void setDepartment(const std::string&);
    void setDegree(const std::string&);

    std::string getEmployeeID() const;
    std::string getDepartment() const;
    std::string getDegree() const;

    void print() const;
    bool equals(const professorType&) const;

private:
    std::string employeeID, department, degree;
};
#endif // PROFESSOR_TYPE_H