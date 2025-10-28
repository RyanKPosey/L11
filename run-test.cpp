/*
    Programmer: Ryan Posey
    Assignment: L11
    Purpose: Practice class inheritance
    Due date: 10/29/2025
*/

#include <iostream>
#include "studentType.h"
#include <vector>
#include "personType.h"
#include "professorType.h"

using namespace std;

int main() {
    vector<personType> people = {
        personType("Justin", "Sandwich", "123 Main St", 30, "01/01/1993", 'M', 30),
    };

    vector<studentType> students = {
        studentType("John", "Doe", 3.5, "S12345", "Junior"),
        studentType("Jane", "Smith", 3.8, "S67890", "Senior"),
    };

    vector<professorType> professors = {
        professorType("Alan", "Turing", "1 Computation Way", 72.0, "1912-06-23", 'M', 41, "123456789", "Computer Science", "PhD"),
        professorType("Grace", "Hopper", "2 Programming Rd", 65.0, "1906-12-09", 'F', 85, "246810124", "Computer Science", "PhD")
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

    for (size_t i = 0; i < professors.size(); i++) {
        cout << "Professor " << (i + 1) << ":" << endl;
        professors[i].print();
        cout << endl;
    }

    cout << "Professor 0 = Professor 1? " 
         << std::boolalpha << professors[0].equals(professors[1]) << endl;
}
