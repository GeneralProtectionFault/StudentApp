#pragma once

#include "roster.h";





Student Roster::GetStudent(int index) 
{ 
	return *classRosterArray[index - 1]; 
}



/// <summary>
/// Sets the instance variables for the student objects in the roster
/// </summary>
/// <param name="studentID"></param>
/// <param name="firstName"></param>
/// <param name="lastName"></param>
/// <param name="emailAddress"></param>
/// <param name="age"></param>
/// <param name="daysInCourse1"></param>
/// <param name="daysInCourse2"></param>
/// <param name="daysInCourse3"></param>
/// <param name="degreeprogram"></param>
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, 
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int courseDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeprogram);

	classRosterArray[studentIteration] = newStudent;
}


/// <summary>
/// Remove student by ID
/// </summary>
/// <param name="studentID"></param>
void Roster::remove(string studentID)
{
	bool removedStudent = false;

	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->GetStudentID())
		{
			classRosterArray[i] = nullptr;
			removedStudent = true;
			cout << studentID << " has been removed." << endl << endl;
			break;
		}		
	}

	if (!removedStudent)
		cout << studentID << " does not exist." << endl << endl;
}

/// <summary>
/// Prints a complete tab-separated list of student data
/// </summary>
void Roster::printAll()
{
	// Call existing print() function for each student
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i]->print();
	}

	cout << endl;
}


/// <summary>
/// Print the average of the days in the 3 courses
/// </summary>
/// <param name="studentID"></param>
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->GetStudentID())
		{
			int daysArray[3] = { 0 };
			for (int j = 0; j < 3; j++)
				daysArray[j] = classRosterArray[i]->GetDaysInCourse()[j];

			float average = ((float)daysArray[0] + (float)daysArray[1] + (float)daysArray[2]) / 3;

			cout << average << endl << endl;
			break;
		}
	}
}



/// <summary>
/// Validate all email addresses, ensure there is an '@' sign and there are no spaces
/// Print any invalids
/// </summary>
void Roster::printInvalidEmails()
{
	cout << "The following email addresses are invalid:" << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		string email = classRosterArray[i]->GetEmail();

		bool atSymbolExists = false;
		bool periodExists = false;
		bool spaceExists = false;

		for (char& c : email)
		{
			if (c == '@')
				atSymbolExists = true;
			if (c == '.')
				periodExists = true;
			if (c == ' ')
				spaceExists = true;
		}

		if (!periodExists || !atSymbolExists || spaceExists)
			cout << classRosterArray[i]->GetEmail() << endl;
	}

	cout << endl;
}


/// <summary>
/// Print out all students that match a given degree
/// </summary>
/// <param name="degreeProgram"></param>
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	string degreeName = "";

	if (degreeProgram == 0)
		degreeName = "SECURITY";
	else if (degreeProgram == 1)
		degreeName = "NETWORK";
	else if (degreeProgram == 2)
		degreeName = "SOFTWARE";

	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->GetDegree() == degreeName)
			classRosterArray[i]->print();
	}

	cout << endl;
}


