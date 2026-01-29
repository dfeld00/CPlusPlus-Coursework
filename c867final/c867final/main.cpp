//
//  main.cpp
//  c867final
//
//  Created by Dallas Feldbush on 1/24/26.
//
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
    cout << "C867 Scripting and Programming Applications | ";
    cout << "C++ | ";
    cout << "Student ID: 012621094 | ";
    cout << "Dallas Feldbush" << "\n" << endl;
    
    const string studentData[] = {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Dallas,Feldbush,dfeldb2@wgu.edu,25,30,30,30, SOFTWARE"};
    
    const int numStudents = 5;
    Roster classRoster;

    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

    cout << "Class Roster: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying invalid Emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Average days in course for each student is: " << endl;
    
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        cout << " ";
    }
    
    cout << endl;

    cout << "\n";
    cout << "Displaying by degree program: " << degreeProgramStrings[2] << endl;
    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << endl;
    
    cout << "Removing Student A3" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Removing Student A3 again" << endl;
    classRoster.remove("A3");
    cout << endl;

    return 0;
}
