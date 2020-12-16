#pragma once

using namespace std;

#include "student.h";
#include "roster.h";


// Accessors
string Student::GetStudentID() { return studentID; }
string Student::GetFirstName() { return firstName; }
string Student::GetLastName() { return lastName; }
string Student::GetEmail() { return email; }
int Student::GetAge() { return age; }
int* Student::GetDaysInCourse() { return daysInCourse; }
string Student::GetDegree() 
{ 
	if (degree == 0)
		return "SECURITY";
	else if (degree == 1)
		return "NETWORK";
	else if (degree == 2)
		return "SOFTWARE";

}

// Mutators
void Student::SetStudentID(string ID) { this->studentID = ID; }
void Student::SetFirstName(string fName) { this->firstName = fName; }
void Student::SetLastName(string lName) { this->lastName = lName; }
void Student::SetEmail(string emailAddress) { this->email = emailAddress; }
void Student::SetAge(int years) { this->age = years; }
void Student::SetDaysInCourse(int day1, int day2, int day3) 
{ 
	this->daysInCourse[0] = day1;
	this->daysInCourse[1] = day2;
	this->daysInCourse[2] = day3;
}
void Student::SetDegree(DegreeProgram deg) { this->degree = deg; }




// Constructor
Student::Student(string ID, string firstName, string lastName, string email, int age, int days[], DegreeProgram type)
{
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = days[i];
	this->degree = type;
}

Student::Student()
{
	;
}


// Needs to print specific students!
void Student::print()
{
	if (this != nullptr)
	{
		int daysArray[3] = { 0 };
		for (int i = 0; i < 3; i++)
			daysArray[i] = this->GetDaysInCourse()[i];

		cout << this->GetStudentID() << "\t" << this->GetFirstName() << "\t" << this->GetLastName() << "\t" << this->GetEmail() << "\t" << this->GetAge() << "\t"
			<< daysArray[0] << ", " << daysArray[1] << ", " << daysArray[2] << "\t" << this->GetDegree() << endl;
	}
}

