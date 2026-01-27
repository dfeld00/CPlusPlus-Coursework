#pragma once

#include "student.h"
#include <vector>

using namespace std;

class Roster {
public:
    Roster(); //Constructor
    ~Roster(); //Destructor
    const static int numberOfStudents = 5; // Number of student in the provided data table
    int LastIndex = -1;
    
    Student* classRosterArray[numberOfStudents]; // Array with points for part F
    
    // Sets the instance variables from part D1 and updates the roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    
    // Removes students by ID and shows error if non existent
    void remove(string studentID);
    
    // loops through all students and calls print() for each student
    void printAll();
    
    // Prints the average number of days in the three courses for the student whose studentID is passed in as the parameter
    void printAverageDaysInCourse(string studentID);
    
    //  Verifies student email addresses and displays all invalid email addresses to the user
    void printInvalidEmails();
    
    // Prints out student information for a degree program specified by an enumerated type
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    void parse(string studentData);
};
