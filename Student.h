#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {

//    friend Student operator==(const Student & m, const Student & s);

public:
    Student(int studentIDz, string studentNamez); // constructer
    Student(int studentIDz); // constructer
    Student(string studentNamez); // constructer
    Student(); // constructer

    const int getStudentID() const; // returns studentID
    const string getStudentName() const; // returns studentName

    bool equals(const Student & s) const; // see if the two Students have same IDs

    void setStudentID(int studentIDz); // sets studentID
    void setStudentName(string studentNamez); // sets studentName

    bool operator==(const Student &s) const;

private:
    int studentID;
    string studentName;
};

#endif
