#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
using namespace std;

const string studentData[] =

{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Jose,Mora,jmor4@wgu.edu,25,30,30,45,SOFTWARE"
};

class classRoster {
public:
	classRoster(); //default constructor
	~classRoster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int dcourse1, int dcourse2, int dcourse3, DegreeProgram degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
private:
	Student* classRosterArray[5];
	Student A;
	Student B;
	Student C;
	Student D;
	Student E;


};
#endif // !
