#pragma once

#include <iostream>
#include <string>

#include "degree.h";

using namespace std;

class Student
{
public:
	// Accessors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysInCourse();
	string GetDegree();

	// Mutators
	void SetStudentID(string ID);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysInCourse(int day1, int day2, int day3);
	void SetDegree(DegreeProgram deg);

	void print();

	Student();
	Student(string ID, string firstName, string lastName, string email, int age, int days[], DegreeProgram type);


private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse [3];
	DegreeProgram degree;
};
