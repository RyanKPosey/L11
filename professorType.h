/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/29/2025
*/

/**
 * @file professorType.h
 * @brief Declaration of the professorType class, a specialization of personType
 *        that adds employee-related fields.
 *
 * This header declares the professorType class used for the assignment
 * practicing C++ class inheritance. Each public member is documented with
 * its purpose, preconditions and postconditions.
 */

#ifndef PROFESSOR_TYPE_H
#define PROFESSOR_TYPE_H

#include "personType.h"
#include <string>

/**
 * @class professorType
 * @brief Represents a professor with employee metadata in addition to
 *        personType fields.
 *
 * Preconditions: The embedded personType invariants apply for name and
 *                other person attributes (see personType documentation).
 * Postconditions: Objects of this type provide accessors and mutators for
 *                 employee-specific data: employeeID, department, degree.
 *
 * Class Invariants
 * - The personType class invariants must hold for the inherited person
 *   fields (see `personType` documentation), e.g. height in a sensible
 *   range and age clamped to a reasonable upper bound.
 * - `employeeID`, `department`, and `degree` are valid `std::string`
 *   instances (they may hold sentinel values such as "NOT SET" but are
 *   never left indeterminate).
 * - Public methods do not leave the object in a state violating the above
 *   invariants: constructors establish them and setters preserve them.
 */
class professorType : public personType {
public:
    /**
     * @brief Default constructor.
     *
     * @pre  None.
     * @post Constructs a professorType with employee fields set to "NOT SET".
    * @details
    * Constructs a professorType using the default personType constructor
    * (which sets name to empty/defaults) and initializes the employee
    * specific fields (`employeeID`, `department`, `degree`) to the
    * placeholder string "NOT SET".
    *
    * @example
    * @code{.cpp}
    * professorType p; // p.getEmployeeID() == "NOT SET"
    * p.print();
    * @endcode
     */
    professorType();

    /**
     * @brief Construct a professorType with first and last name.
     *
     * @param f First name (read-only reference).
     * @param l Last name (read-only reference).
     * @pre  Strings f and l are valid std::string objects.
     * @post Constructs a professorType with the supplied name and employee
     *       fields set to "NOT SET".
    * @details
    * Initializes the base `personType` with the provided `f` and `l` and
    * sets the employee-specific fields to "NOT SET". This constructor is
    * appropriate when you only have a name and don't yet know employment
    * details.
    *
    * @example
    * @code{.cpp}
    * professorType prof("Ada", "Lovelace");
    * // prof.getEmployeeID() == "NOT SET"
    * @endcode
     */
    professorType(const std::string& f, const std::string& l);

    /**
     * @brief Full constructor initializing all personType and professorType
     *        fields.
     *
     * @param f First name.
     * @param l Last name.
     * @param addr Address string passed to personType.
     * @param heightIn Height in inches passed to personType.
     * @param dob Date of birth string passed to personType.
     * @param gender Gender char passed to personType.
     * @param age Age passed to personType.
     * @param employeeID Employee ID to store.
     * @param department Department string to store.
     * @param degree Highest degree string to store.
     * @pre  All std::string parameters are valid; heightIn should be a
     *       non-negative double; age should be a reasonable unsigned value.
     * @post Constructs a fully-initialized professorType with provided values.
    * @details
    * Forwards name/address/height/DOB/gender/age to the `personType`
    * constructor, then stores the employee-specific strings in the local
    * members. No validation beyond basic expectations is performed.
    *
    * @example
    * @code{.cpp}
    * professorType prof("Alan", "Turing", "1 Computation Way", 72.0,
    *                    "1912-06-23", 'M', 41,
    *                    "E123", "CS", "PhD");
    * std::cout << prof.getEmployeeID(); // prints E123
    * @endcode
     */
    professorType(const std::string& f, const std::string& l,
                  const std::string& addr, double heightIn,
                  const std::string& dob, char gender, unsigned age,
                  const std::string& employeeID,
                  const std::string& department,
                  const std::string& degree);

    /**
     * @brief Set the employee ID.
     *
     * @param[in] id New employee ID string.
     * @pre  id is a valid std::string.
     * @post employeeID() will return the new id.
    * @details
    * Copies the provided string into the object's `employeeID` member.
    *
    * @example
    * @code{.cpp}
    * professorType p;
    * p.setEmployeeID("E100");
    * assert(p.getEmployeeID() == "E100");
    * @endcode
     */
    void setEmployeeID(const std::string&);

    /**
     * @brief Set the department string.
     *
     * @param[in] dept New department.
     * @pre  dept is a valid std::string.
     * @post getDepartment() will return the new dept string.
    * @details
    * Replaces the stored department string with the provided value.
    *
    * @example
    * @code{.cpp}
    * professorType p;
    * p.setDepartment("Mathematics");
    * @endcode
     */
    void setDepartment(const std::string&);

    /**
     * @brief Set the degree string.
     *
     * @param[in] deg New degree.
     * @pre  deg is a valid std::string.
     * @post getDegree() will return the new degree string.
    * @details
    * Replaces the stored degree string. Use this to record the professor's
    * highest earned degree (e.g., "MSc", "PhD").
    *
    * @example
    * @code{.cpp}
    * professorType p;
    * p.setDegree("PhD");
    * @endcode
     */
    void setDegree(const std::string&);

    /**
     * @brief Return the stored employee ID.
     *
     * @return employee ID string.
     * @pre  Object is a valid, constructed professorType.
     * @post No state modification.
    * @details
    * Returns a copy of the stored employee ID. This function does not
    * return a reference to the internal string to avoid exposing internal
    * state for modification.
    *
    * @example
    * @code{.cpp}
    * professorType p("Grace","Hopper");
    * std::string id = p.getEmployeeID();
    * @endcode
     */
    std::string getEmployeeID() const;

    /**
     * @brief Return the stored department string.
     *
     * @return department string.
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
    std::string getDepartment() const;

    /**
     * @brief Return the stored degree string.
     *
     * @return degree string.
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
    std::string getDegree() const;

    /**
     * @brief Print the professor's data to stdout (delegates to personType::print).
     *
     * @pre  std::cout is available.
     * @post Streams a human-readable representation of the object to stdout.
    * @details
    * Calls `personType::print()` to output name/address/etc., then prints
    * the `employeeID`, `department` and `degree` fields on separate lines.
    *
    * @example
    * @code{.cpp}
    * professorType p("Katherine","Johnson");
    * p.setEmployeeID("E777");
    * p.print();
    * @endcode
     */
    void print() const;

    /**
     * @brief Compare two professorType objects for equality.
     *
     * @param other Other professorType to compare against.
     * @return true when all fields (including personType fields) are equal.
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
    bool equals(const professorType&) const;

private:
    std::string employeeID, department, degree;
};

#endif // PROFESSOR_TYPE_H