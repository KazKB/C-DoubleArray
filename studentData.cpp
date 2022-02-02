#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int i;

//Declares And Defines Struct studentType And Assigns An Array To It
struct studentType {
	string studentFName, studentLName;
	int testScore;
	char grade;
} student[20];

//Declares And Defines Function getStudentData
void getStudentData (studentType student[]) {
	//Gets students names and test scores
	for (i = 0; i < 20; i++) {
		cout << "Enter the name of the student(First Name Last Name): ";
		cin >> student[i].studentFName >> student[i].studentLName;
		cout << "Enter " << student[i].studentLName << "\'s test score(0-100): ";
		cin >> student[i].testScore;
		
		//Checks acceptability of test score
		while ((student[i].testScore > 100) || (student[i].testScore < 0)) {
			i--;
			cout << "Re-enter the student\'s information.\n";
		}
	}
}

//Declares And Defines Function determineGrade
void determineGrade (studentType student[]) {
	//Cycles through each student and assigns them a grade depending on their test score
	for (i = 0; i < 20; i++) {
		if(student[i].testScore >= 90)
			student[i].grade = 'A';
		else if(student[i].testScore >= 80)
			student[i].grade = 'B';
		else if(student[i].testScore >= 70)
			student[i].grade = 'C';
		else if(student[i].testScore >= 60)
			student[i].grade = 'D';
		else if(student[i].testScore < 60)
			student[i].grade = 'F';
	}
}

//Declares And Defines Function determineHighestScore
void determineHighestScore (studentType student[], int &max) {
	//Cycles through each student to see what was the highestest score on the test
	for (i = 0; i < 20; i++){
		if (student[i].testScore > max)
			max = student[i].testScore;
	}
}

//Declares And Defines Function printHigestScoredStudents
void printHighestScoredStudents (studentType student[], int max) {
	//Displays The Highest Score
	cout << "\nThe highest test score achieved: " << max << endl;
	
	//Heading For List Of Students Who Got The Highest Score
	cout << "Student(s) who got the highest on the test is/are:" << endl;
	
	//Cycles through to see who are the highest scoring students and display their information
	for (i = 0; i < 20; i++){
		if (student[i].testScore == max) {
			cout << student[i].studentLName << ", " << student[i].studentFName << endl;
		}
	}
}

int main () {
	int max = 0;
	
	//Calls Functions
	getStudentData (student);
	determineGrade (student);
	determineHighestScore (student, max);
	printHighestScoredStudents (student, max);
	
	return 0;
}
