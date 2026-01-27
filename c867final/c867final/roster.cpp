#include <iostream>
#include <vector>


#include "roster.h"


using namespace std;

const int rosterSize = 5;

const string studentData[rosterSize] = {
   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
   "A5,Dallas,Feldbush,dfeldb2@wgu.edu,25,30,30,30, SOFTWARE"};

Roster::Roster() {
    
};

void Roster::parse(string studentData)
{
    DegreeProgram degreeProgram = SECURITY; //default value
    if (studentData.back() == 'K') degreeProgram = NETWORK; // Checks what the last word is out of the three.
    else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

    unsigned long int firstComma = studentData.find(",");
    string StudentID = studentData.substr(0, firstComma);

    unsigned long int nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    string FirstName = studentData.substr(nextComma, firstComma - nextComma);

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    string LastName = studentData.substr(nextComma, firstComma - nextComma);

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    string EmailAddress = studentData.substr(nextComma, firstComma - nextComma);

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    int Age = stoi(studentData.substr(nextComma, firstComma - nextComma));

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    int Days1 = stoi(studentData.substr(nextComma, firstComma - nextComma));
                

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    int Days2 = stoi(studentData.substr(nextComma, firstComma - nextComma));

    nextComma = firstComma + 1;
    firstComma = studentData.find(",", nextComma);
    int Days3 = stoi(studentData.substr(nextComma, firstComma - nextComma));

    add(StudentID, FirstName, LastName, EmailAddress, Age, Days1, Days2, Days3, degreeProgram);

}

void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram) {
    
    int Days[3] = { Days1, Days2, Days3};

    classRosterArray[++LastIndex] = new Student(StudentID, FirstName, LastName, Email, Age, Days, degreeProgram);
};

void Roster::remove(string studentID) {
    bool matching = false;
    for (int i = 0; i <= Roster::LastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            matching = true;
            if (i < numberOfStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numberOfStudents - 1];
                classRosterArray[numberOfStudents - 1] = temp;
            }
            Roster::LastIndex--;
        }
    }
};

void Roster::printAll() {
    for (int i = 0; i <= Roster::LastIndex; i++) {
        cout << classRosterArray[i]->getStudentID() << '\t';
        cout << classRosterArray[i]->getFirstName() << '\t';
        cout << classRosterArray[i]->getLastName() << '\t';
        cout << classRosterArray[i]->getEmail() << '\t';
        cout << classRosterArray[i]->getAge() << '\t';
        cout << classRosterArray[i]->getDays()[0] << '\t';
        cout << classRosterArray[i]->getDays()[1] << '\t';
        cout << classRosterArray[i]->getDays()[2] << '\t';
        cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
        }
};

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::LastIndex; i++)
        {
            if (classRosterArray[i]->getStudentID() == studentID) {
                cout << studentID ;
                cout << (classRosterArray[i]->getDays()[0] +
                         classRosterArray[i]->getDays()[1] +
                         classRosterArray[i]->getDays()[2])/3;
            }
        }
};
void Roster::printInvalidEmails() {
    bool invalid = false;

    for (int i = 0; i <= Roster::LastIndex; i++) {
    string EmailAddress = (classRosterArray[i]->getEmail());
        if (EmailAddress.find("@") == string::npos || (EmailAddress.find('.') == string::npos) || (EmailAddress.find(' ') != string::npos)) {
            invalid = true;
            cout << EmailAddress << ": " << classRosterArray[i]->getEmail() << endl;
        }
    }
    if (!invalid) {
        cout << "No Invalid Emails" << endl;
    }
};
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
        for (int i = 0; i <= Roster::LastIndex; i++) {
            if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
        }
        cout << endl;
};

Roster::~Roster() { // To reclaim memory after finished with array
    for (int i = 0; i < numberOfStudents; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};
