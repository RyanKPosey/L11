#include <iostream>
#include "studentType.h"
#include <vector>
#include "personType.h"

using namespace std;

int main() {
    vector<studentType> students = {
        studentType("John", "Doe", 3.5, "Junior", "S12345"),
        studentType("Jane", "Smith", 3.8, "Senior", "S67890"),
        studentType("Alice", "Johnson", 3.2, "Sophomore", "S54321")
    };

    vector<personType> people = {
        personType("Justin", "Sandwich", "123 Main St", 30, "01/01/1993", 'M', 30),
        personType("Sally", "SmartyPants", "456 Elm St", 65, "05/26/1951", 'F', 72),
        personType("Bob", "Sponge", "789 Oak St", 70, "02/15/1953", 'M', 70)
    };

    //print students

    for (size_t i = 0; i < students.size(); i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        students[i].print();
        cout << endl;
    }

    // print people
    
    for (size_t i = 0; i < people.size(); i++) {
        cout << "Person " << (i + 1) << ":" << endl;
        people[i].print();
        cout << endl;
    }
}
