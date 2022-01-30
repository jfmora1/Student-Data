
#include "roster.h"
#include "degree.h"
#include <vector>
using namespace std;



DegreeProgram convert(string str) {

	if (str == "NONE") return NONE;
	if (str == "SECURITY") return SECURITY;
	if (str == "NETWORK") return NETWORK;
	if (str == "SOFTWARE") return SOFTWARE;
}


int main(){
	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: " << endl;
	cout << "Jose Mora" << endl << endl;


	//parsing data
	//string vector holds the seperated data from studentData array
	vector<string>data;
	//temporary string that appends the characters before a comma (,)
	string tempString = "";

	for (int i = 0; i < 5; i++) {
		//first loop grabs the elements from the studentData array which are strings


		for (int j = 0; j < studentData[i].size(); j++) {
			//second loop grabs each character from the string element in the current iteration

			//if the current character is not a comma(,) then append that character to the string variable tempString
			//EX:		tempString = "1"		tempString += ", 2"		tempString = "1, 2" 
			//when the current character is a comma(,) then push_back tempString into string vector data
			//also set tempString to empty so the next characters are appended till the comma again.
			if (studentData[i][j] != ',') {
				tempString += studentData[i][j];
	
			}
			else {
				data.push_back(tempString);
				tempString = "";
			}

		}

		//since we never get to the else statement in the second for-loop at the last iteration 
		//because there are no commas(,) at the end of each string element
		//we push_back tempString into string vector data (tempString contains the last variable)
		//we also set tempString to empty so when the next element string is called tempString is ready
		data.push_back(tempString);
		tempString = "";
	
	}

	string id, fname, lname, email;
	int age, dcourse1, dcourse2, dcourse3;
	string degree1;
	DegreeProgram degree;

	classRoster Roster;

	int indexID = 0;
	int indexF = 1;
	int indexL = 2;
	int indexEmail = 3;
	int indexAge = 4;
	int indexCourse1 = 5;
	int indexCourse2 = 6;
	int indexCourse3 = 7;
	int indexDegree = 8;

	int numDays[] = { 0, 0, 0 };

	int check = 0;
	int x = 0;

	for (int i = 0; i < 5; i++) {

		if (check < 1) {
			id = data[indexID];
			fname = data[indexF];
			lname = data[indexL];
			email = data[indexEmail];

			age = stoi(data[indexAge]);
			dcourse1 = stoi(data[indexCourse1]);
			dcourse2 = stoi(data[indexCourse2]);
			dcourse3 = stoi(data[indexCourse3]);

			degree1 = data[indexDegree];

			degree = convert(degree1);

			Roster.add(id, fname, lname, email, age, dcourse1, dcourse2, dcourse3, degree);

			check++;
		}

		else {

			indexID += 9;
			indexF += 9;
			indexL += 9;
			indexEmail += 9;
			indexAge += 9;
			indexCourse1 += 9;
			indexCourse2 += 9;
			indexCourse3 += 9;
			indexDegree += 9;

			id = data[indexID];
			fname = data[indexF];
			lname = data[indexL];
			email = data[indexEmail];

			age = stoi(data[indexAge]);
			dcourse1 = stoi(data[indexCourse1]);
			dcourse2 = stoi(data[indexCourse2]);
			dcourse3 = stoi(data[indexCourse3]);


			degree1 = data[indexDegree];

			degree = convert(degree1);

			degree1 = data[indexDegree];

			degree = convert(degree1);

			Roster.add(id, fname, lname, email, age, dcourse1, dcourse2, dcourse3, degree);

		}

	}
	Roster.printAll();



	Roster.printInvalidEmails();

	Roster.printAverageDaysInCourse("A1");
	Roster.printAverageDaysInCourse("A2");
	Roster.printAverageDaysInCourse("A3");
	Roster.printAverageDaysInCourse("A4");
	Roster.printAverageDaysInCourse("A5");

	cout << endl << "Students in Software degree program:";
	Roster.printByDegreeProgram(SOFTWARE);

	cout << "Students in Network degree program:";
	Roster.printByDegreeProgram(NETWORK);

	cout << "Students in Security degree program:";
	Roster.printByDegreeProgram(SECURITY);

	
	Roster.remove("A3"); // deletes student

	Roster.printAll();

	Roster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.

	//Destructor is called.

	return 0;
}



