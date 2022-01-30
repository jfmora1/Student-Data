#include "student.h"
#include <vector>
using namespace std;


Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	numDays[0] = { 0 };
	numDays[1] = { 0 };
	numDays[2] = { 0 };
	degree = NONE;

} // default constructor 


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numdays[], DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDays[0] = numdays[0];
	this->numDays[1] = numdays[1];
	this->numDays[2] = numdays[2];
	this->degree = degree;
	


} // default constructor 
void Student::SetStudentID(string ID) {
	studentID = ID;

}
void Student::SetFirstName(string firstname) {
	firstName = firstname;

}
void Student::SetLastName(string lastname) {
	lastName = lastname;

}
void Student::SetEmailAddress(string emailaddress) {
	emailAddress = emailaddress;

}
void Student::SetAge(int age) {
	this->age = age;

}
void Student::SetNumDays(int index, int value) {
	numDays[index] = value;
	
}
void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree;

}


void Student::Print() const {
	string tempdegree;
	switch (degree ) {
	case 0:
		tempdegree = "NONE";
		break;
	case 1:
		tempdegree = "SECURITY";
		break;
	case 2: 
		tempdegree = "NETWORK";
		break;
	case 3: 
		tempdegree = "SOFTWARE";
		break;
		
	}

	cout << studentID << "\t" << firstName << "\t" << lastName << "\t"
		<< emailAddress << "\t" << age << "\t" << numDays[0] << ", " << numDays[1] 
		<< ", " << numDays[2] << "\t" << tempdegree << endl;

}

string Student::GetStudentID() {
	
	return studentID;
}
string  Student::GetFirstName() {
	return firstName;

}
string Student::GetLastName() {

	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;

}
int Student::GetAge() {
	return age;

}
int Student::GetNumDays(int index) {

	return numDays[index];
}
DegreeProgram Student::GetDegree() {

	return degree;

}