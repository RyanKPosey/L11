/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/23/2025
*/

#include <iostream>
#include "studentType.h"
#include <vector>
#include "personType.h"

using namespace std;

int main() {
    vector<personType> people = {
        personType("Justin", "Sandwich", "123 Main St", 30, "01/01/1993", 'M', 30),
        personType("Sally", "SmartyPants", "456 Elm St", 65, "05/26/1951", 'F', 72),
    };

    vector<studentType> students = {
        studentType("John", "Doe", 3.5, "S12345", "Junior"),
        studentType("Jane", "Smith", 3.8, "S67890", "Senior"),
        studentType("Alice", "Johnson", 3.2, "S54321", "Sophomore")
    };
 

    // print people

    for (size_t i = 0; i < people.size(); i++) {
        cout << "Person " << (i + 1) << ":" << endl;
        people[i].print();
        cout << endl;
    }

     //print students

    for (size_t i = 0; i < students.size(); i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        students[i].print();
        cout << endl;
    }
}
