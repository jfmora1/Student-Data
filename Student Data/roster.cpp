#include "roster.h"
#include <vector>
using namespace std;


classRoster::classRoster() {
	classRosterArray[0] = &A;
	classRosterArray[1] = &B;
	classRosterArray[2] = &C;
	classRosterArray[3] = &D;
	classRosterArray[4] = &E;
} //default 

classRoster::~classRoster() {
	cout << "Destructor called";
} //destructor

void classRoster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int dcourse1, int dcourse2, int dcourse3, DegreeProgram degree) {
	int tmp = 0;
	
	for (int i = 0; i < 5; i++) {
		if (tmp == 0) {
			if (classRosterArray[i]->GetStudentID() == "") {
				classRosterArray[i]->SetStudentID(studentID);
				classRosterArray[i]->SetFirstName(firstName);
				classRosterArray[i]->SetLastName(lastName);
				classRosterArray[i]->SetEmailAddress(emailAddress);
				classRosterArray[i]->SetAge(age);
				classRosterArray[i]->SetNumDays(0, dcourse1);
				classRosterArray[i]->SetNumDays(1, dcourse2);
				classRosterArray[i]->SetNumDays(2, dcourse3);
				classRosterArray[i]->SetDegree(degree);
				tmp++;
			}
		}

	}
}
void classRoster::remove(string studentID) {
	cout << endl;
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID && classRosterArray[i]->GetStudentID() != "") {
			classRosterArray[i]->SetStudentID("");
			classRosterArray[i]->SetFirstName("");
			classRosterArray[i]->SetLastName("");
			classRosterArray[i]->SetEmailAddress("");
			classRosterArray[i]->SetAge(0);
			classRosterArray[i]->SetNumDays(0, 0);
			classRosterArray[i]->SetNumDays(1, 0);
			classRosterArray[i]->SetNumDays(2, 0);
			classRosterArray[i]->SetDegree(NONE);
			found = true;
			cout << "Student ID found and removed\n";
		}
	}
	if (!found) {
		cout << "ERROR: STUDENT ID NOT FOUND\n";
	}
		cout << endl;
}
void classRoster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() != "") {
			classRosterArray[i]->Print();
		}
	}

}
void classRoster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		string ID = classRosterArray[i]->GetStudentID();
		if (ID == studentID) {
			cout << "Student ID: " << ID << endl;
			cout << "\tThe average days in courses: " << (classRosterArray[i]->GetNumDays(0) +classRosterArray[i]->GetNumDays(1) +classRosterArray[i]->GetNumDays(2)) / 3 << endl;
			return;
		}

	}

}
void classRoster::printInvalidEmails() {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		string invalidemail = classRosterArray[i]->GetEmailAddress();
		if (invalidemail.find('.') == string::npos) {
		cout << "Invalid email: " << invalidemail << endl;
		cout << "Missing period.\n";
		}

		else if (invalidemail.find('@') == string::npos) {
			cout << "Invalid email: " << invalidemail << endl;
			cout << "Missing @.\n";
		}
		else if (invalidemail.find(' ') != string::npos) {
			cout << "Invalid email: " << invalidemail << endl;
			cout << "Space found in email.\n";
		}

		
		
	}
	cout << endl;
}
	
void classRoster::printByDegreeProgram(DegreeProgram degree) {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegree() == degree) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;
}

