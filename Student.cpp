// Student class member and friend function definition
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "Student.h" // Student class definition
using namespace std;

int studentID;
string studentName;

// constructor for class Student
Student::Student(int studentIDz, string studentNamez) {
    studentID = studentIDz;
    studentName = studentNamez;
}

// constructor for class Student
Student::Student(int studentIDz) {
    studentID = studentIDz;
    studentName = " ";
}

// constructor for class Student
Student::Student(string studentNamez) {
    studentID = 0;
    studentName = studentNamez;
}

// constructor for class Student
Student::Student() {
    studentID = 0;
    studentName = " ";
}

// returns studentID
const int Student::getStudentID() const {
    return studentID;
}

// returns studentName
const string Student::getStudentName() const {
    return studentName;
}

// sets studentID
void setStudentID(int studentIDz) {
    studentID = studentIDz;
}

// sets studentID
void setStudentName(int studentNamez) {
    //studentName = studentNamez;
}

// sees if two Students have same studentIDs
bool Student::equals(const Student &s) const {
    if (getStudentID() == s.getStudentID()) {
        return true;
    } else {
        return false;
    }
}

// overide of == operator
bool Student::operator==(const Student& s) const {
    bool temp = this->equals(s);
    return temp;
}
