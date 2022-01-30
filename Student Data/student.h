#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numdays[], DegreeProgram degree); // default constructor 

	void SetStudentID(string ID);
	void SetFirstName(string firstname);
	void SetLastName(string lastname);
	void SetEmailAddress(string emailaddress);
	void SetAge(int age);
	void SetNumDays(int index, int value);
	void SetDegree(DegreeProgram degree);

	void Print() const;

	string GetStudentID();
	string  GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int GetNumDays(int index);
	DegreeProgram GetDegree();

	


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
	//string degree;
	DegreeProgram degree;

};


#endif
