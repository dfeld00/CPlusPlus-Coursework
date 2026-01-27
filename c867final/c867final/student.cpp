#include "student.h"

#include <iostream>
#include <string>

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram) {
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    
}
// Variable used in for loop
int i = 0;

//Setter Mutators
void Student::setStudentID(string studentID) {this->studentID = studentID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName)   {this->lastName = lastName;}
void Student::setEmail(string email)         {this->email = email;}
void Student::setAge(int age)                {this->age = age;}
void Student::setDays(int days[]) {          // Initializes days array
    for (i = 0; i < DaysToComplete; ++i) {
        this->days[i] = days[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

// Getter Accessors
string Student::getStudentID() {return studentID;}
string Student::getFirstName() {return firstName;}
string Student::getLastName()  {return lastName;}
string Student::getEmail()     {return email;}
int    Student::getAge()       {return age;}
int*   Student::getDays()      {return this->days;}
DegreeProgram Student::getDegreeProgram() {return degreeProgram;}

void Student::print() { // To print a specific layout per part E.2
    cout << "A1\tFirst Name: " << getFirstName() << "\t";
    cout << "Last Name: "      << getLastName() << "\t";
    cout << "Email: "          << getEmail() << "\t";
    cout << "Age: "            << getAge() << "\t";
    cout << "daysInCourse: {"  << getDays()[0] << ", " << getDays()[1] << ", " << getDays()[2] << "} ";
    cout << "Degree Program: " << getDegreeProgram() << endl;
    
}
