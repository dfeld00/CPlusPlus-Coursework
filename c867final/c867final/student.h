#pragma once

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
    int age;
    int days[DaysToComplete];
    DegreeProgram degreeProgram;
    
};
