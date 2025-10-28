/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/23/2025
*/

#include "professorType.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @file professorType.cpp
 * @brief Implementation of the professorType class declared in professorType.h
 *
 * Class Invariants
 * - The `personType` invariants apply for the inherited personal fields
 *   (see `personType.h`), e.g. height is non-negative and age is within a
 *   reasonable range.
 * - `employeeID`, `department`, and `degree` are valid `std::string`
 *   values and will contain either a meaningful value or the sentinel
 *   "NOT SET"; they are never indeterminate.
 * - Public member functions preserve these invariants: constructors
 *   establish them and setters maintain or sanitize inputs so invariants
 *   continue to hold after calls.
 */

/**
 * @brief Default constructor.
 *
 * @pre  None.
 * @post Constructs a professorType where employee fields are set to "NOT SET".
 * @details
 * Constructs a `professorType` using the default `personType` state and
 * initializes `employeeID`, `department`, and `degree` to the literal
 * "NOT SET". This constructor is intended for use when employment details
 * are not yet known.
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * p.print(); // prints fields; employee fields show "NOT SET"
 * @endcode
 */
professorType::professorType()
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

/**
 * @brief Constructor with first and last name.
 *
 * @param first First name (read-only reference).
 * @param last Last name (read-only reference).
 * @pre  first and last are valid std::string objects.
 * @post Constructs a professorType with the supplied name and employee
 *       fields set to "NOT SET".
 * @details
 * Initializes the base `personType` with `first`/`last` and leaves
 * employee-specific fields set to the placeholder "NOT SET". Use this
 * constructor when you only have name information at construction time.
 *
 * @example
 * @code{.cpp}
 * professorType prof("Ada","Lovelace");
 * prof.print();
 * @endcode
 */
professorType::professorType(const std::string& first, const std::string& last)
    : personType(first, last)
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

/**
 * @brief Full constructor.
 *
 * Initializes both personType and professorType fields.
 *
 * @pre  String arguments are valid; heightIn should be non-negative; age
 *       should be a reasonable unsigned value.
 * @post Constructs a fully-initialized professorType with provided values.
 * @details
 * Forwards personal fields to the `personType` constructor and assigns the
 * provided employee strings to the local members. No further validation is
 * performed (caller responsibility).
 *
 * @example
 * @code{.cpp}
 * professorType full("Alan","Turing","Somewhere",72.0,"1912-06-23",'M',41,
 *                    "E42","CS","PhD");
 * std::cout << full.getEmployeeID(); // E42
 * @endcode
 */
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
/**
 * @brief Set the employee ID.
 *
 * @param id New employee ID.
 * @pre  id is a valid std::string.
 * @post getEmployeeID() will return id.
 * @details
 * Copies the provided `id` into the internal `employeeID` member. This
 * operation performs a copy; if you want to avoid copying consider moving
 * from a temporary when appropriate.
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * p.setEmployeeID("E100");
 * assert(p.getEmployeeID() == "E100");
 * @endcode
 */
void professorType::setEmployeeID(const std::string& id) {
    employeeID = id;
}

/**
 * @brief Set the department string.
 *
 * @param dept New department.
 * @pre  dept is a valid std::string.
 * @post getDepartment() will return dept.
 * @details
 * Assigns the department string. No validation is performed — callers
 * should ensure the string is appropriate for their use.
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * p.setDepartment("Mathematics");
 * @endcode
 */
void professorType::setDepartment(const std::string& dept) {
    department = dept;
}

/**
 * @brief Set the degree string.
 *
 * @param deg New degree.
 * @pre  deg is a valid std::string.
 * @post getDegree() will return deg.
 * @details
 * Stores the professor's highest degree (for display and equality checks).
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * p.setDegree("PhD");
 * @endcode
 */
void professorType::setDegree(const std::string& deg) {
    degree = deg;
}

// Getters
/**
 * @brief Get the employee ID.
 *
 * @return Stored employee ID.
 * @pre  Object is a valid professorType.
 * @post No state modification.
 * @details
 * Returns a copy of the stored employee ID. This avoids exposing internal
 * storage for modification.
 *
 * @example
 * @code{.cpp}
 * professorType p("Grace","Hopper");
 * std::string id = p.getEmployeeID();
 * @endcode
 */
std::string professorType::getEmployeeID() const {
    return employeeID;
}

/**
 * @brief Get the department string.
 *
 * @return Stored department.
 * @pre  Object is valid.
 * @post No state modification.
 * @details
 * Returns the department string by value.
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * auto dept = p.getDepartment();
 * @endcode
 */
std::string professorType::getDepartment() const {
    return department;
}

/**
 * @brief Get the degree string.
 *
 * @return Stored degree.
 * @pre  Object is valid.
 * @post No state modification.
 * @details
 * Returns the stored degree string by value.
 *
 * @example
 * @code{.cpp}
 * professorType p;
 * auto degree = p.getDegree();
 * @endcode
 */
std::string professorType::getDegree() const {
    return degree;
}

// Print
/**
 * @brief Print the professor data to stdout.
 *
 * Delegates printing of name/address/etc to personType::print then prints
 * employee-specific fields.
 *
 * @pre  std::cout is available.
 * @post Streams a human-readable representation of the object to stdout.
 * @details
 * Calls `personType::print()` to output name/address/etc., then prints
 * the `employeeID`, `department` and `degree` fields on separate lines.
 * This function is intended for human-readable console output, not for
 * serialization. For machine-readable output implement a separate method.
 *
 * @example
 * @code{.cpp}
 * professorType p("Katherine","Johnson");
 * p.setEmployeeID("E777");
 * p.print();
 * @endcode
 */
void professorType::print() const {
    personType::print();
    cout << "\tEmployee ID: " << employeeID << endl;
    cout << "\tDepartment: " << department << endl;
    cout << "\tDegree: " << degree << endl;
}

// Equals
/**
 * @brief Compares two professorType objects for equality.
 *
 * @param other The other professorType object.
 * @return true if all fields match, false otherwise.
 * @pre  other is a valid professorType.
 * @post No state modification.
 * @details
 * Performs a field-by-field comparison of the `personType` portion
 * (via `personType::equals`) and the three employee-specific strings.
 *
 * @example
 * @code{.cpp}
 * professorType a("A","B"), b("A","B");
 * a.setEmployeeID("X"); b.setEmployeeID("X");
 * bool same = a.equals(b); // true
 * @endcode
 */
bool professorType::equals(const professorType& other) const {
    return personType::equals(other) &&
           employeeID == other.employeeID &&
           department == other.department &&
           degree == other.degree;
}