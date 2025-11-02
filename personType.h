/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/29/2025
*/
#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <cstdint>
#include <string>
#include <vector>

/**
 * \class personType
 * \brief Represents a person with identity and basic demographics.
 * \details Stores name, address, DOB, gender, height (inches), and age.
 */
class personType { 
    /** \brief First name (may be sentinel like "Not Set"). */
    std::string firstName_;

    /** \brief Last name (may be empty). */
    std::string lastName_;

    /** \brief Postal address or sentinel string. */
    std::string address_;

    /** \brief Height in inches (clamped to [0.0, 120.0]). */
    double height_inches_{};

    /** \brief Date of birth string (format application-defined). */
    std::string date_of_birth_;

    /** \brief Gender character (application-defined semantics). */
    char gender_{};

    /** \brief Age in years (clamped to [0,999]). */
    uint16_t age_{};

public:
    /**
     * @brief Full constructor.
     *
     * @param firstName First name string.
     * @param lastName Last name string.
     * @param address Address string.
     * @param height Height in inches (will be clamped to [0,120]).
     * @param DOB Date of birth string.
     * @param gender Gender character.
     * @param age Age (uint16_t, will be clamped to [0,999]).
     * @pre  Strings are valid; height and age are finite numeric values.
     * @post Constructs a personType with the provided values (clamped where applicable).
     * @details
     * Use this constructor when you have all personal fields available at the
     * time of construction.
     *
     * @example
     * @code{.cpp}
     * personType p("Jane","Doe","1 Main St",65.0,"1990-01-01",'F',30);
     * @endcode
     */
    personType(
        const std::string& firstName, const std::string& lastName, const std::string& address, 
        double height, const std::string& DOB, char gender, uint16_t age
    ); // Full constructor

    /**
     * @brief Constructor taking first and last name only.
     *
     * @param firstName First name string.
     * @param lastName Last name string.
     * @pre  Strings are valid.
     * @post Constructs a personType with name and default sentinel values for other fields.
     * @example
     * @code{.cpp}
     * personType p("John","Smith");
     * @endcode
     */
    personType(const std::string& firstName, const std::string& lastName); // First+Last constructor

    /**
     * @brief Default constructor.
     *
     * @pre  None.
     * @post Constructs a personType with sentinel/default values.
     * @example
     * @code{.cpp}
     * personType p;
     * @endcode
     */
    personType(); // Default constructor

    /**
     * @brief Destructor.
     *
     * @pre  Object is valid.
     * @post Performs cleanup (none required for this type).
     */
    ~personType();

    /**
     * @brief Print a formatted representation of the person.
     *
     * @pre  std::cout is available.
     * @post Streams a human-readable representation to stdout.
     * @example
     * @code{.cpp}
     * personType p("A","B");
     * p.print();
     * @endcode
     */
    void print() const;

    /**
     * @brief Compare two personType objects case-insensitively for string fields.
     *
     * @param other Other personType to compare.
     * @return true if fields are equal (case-insensitive for strings).
     * @post No state modification.
     */
    bool equals(const personType& other) const;

    // Setters
    /**
     * @brief Set the full name from a single "First Last" string (splits on whitespace).
     *
     * @param name Full name string.
     * @pre  name is a valid std::string.
     * @post firstName_ and lastName_ are updated accordingly.
     */
    void setName(const std::string& name);               // accepts "First Last" (splits)
    /** \brief Set first name. */
    void setFirstName(const std::string& firstName);
    /**
     * @brief Set the last name.
     */
    void setLastName(const std::string& lastName);
    /**
     * @brief Set the address.
     */
    void setAddress(const std::string& address);
    /**
     * @brief Set the height in inches (clamped to [0,120]).
     */
    void setHeight(double height);
    /**
     * @brief Set the date of birth string.
     */
    void setDOB(const std::string& DOB);
    /**
     * @brief Set the gender character.
     */
    void setGender(char gender);
    /**
     * @brief Set the age (clamped to [0,999]).
     */
    void setAge(uint16_t age);

    // Getters
    /**
     * @brief Return the full name as "First Last" (omits last if empty).
     */
    std::string getName() const;         // returns "First Last"
    /** \brief Get first name. \return First name string. */
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