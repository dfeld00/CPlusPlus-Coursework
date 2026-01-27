#pragma once

#include "degree.h"
#include <string>

using namespace std;

class Student { // Student class with all variables only accessed by accessor or mutator functions
public:
    const static int DaysToComplete = 3; // Total number of different classes students are taking
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int    age;
    int    days[DaysToComplete];
    DegreeProgram degreeProgram;
    
public:
    // Constructor declaration to assign all variables
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
    //Accessors to get variables for part E.2
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int    getAge();
    int*   getDays();
    DegreeProgram getDegreeProgram();
    
    //Mutators to set variables
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Print() funtion to print specific student data in the formmat specified in E.2
    void print();
};
