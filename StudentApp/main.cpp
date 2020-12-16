#pragma once

#include "student.h";
#include "roster.h";


int main()
{
	string keyboardInput;
	//Student newStudent;

	bool endProgram = false;

	// Print on loading program
	cout << "Scripting and Programming - Applications - C867" << " - C++" << endl;
	cout << "Luke Payne - Student ID: 001105182" << endl << endl;

	cout << "Command List:" << endl;
	cout << "exit:		Exit Application" << endl;
	cout << "print:		Enter a student ID and display that student's record" << endl;
	cout << "printall:	Print all student records" << endl;
	cout << "remove:		Enter a student ID and remove that student" << endl;
	cout << "average:	Enter a student ID to display that student's average number of days in their 3 courses" << endl;
	cout << "invalid:	Display any invalid email addresses" << endl;
	cout << "degree:		Display the student records belonging to a specific degree program" << endl;

	cout << endl;



	// Instantiate roster
	Roster classRoster;


	// Parse the crappy strings into objects :)
	for (size_t i = 0; i < 5; i++)
	{
		classRoster.SetStudentIteration(i);

		string row(studentData[i]);
		int found = row.find_first_of(',');

		int previousIndex;
		previousIndex = 0;

		string ID = row.substr(0, 2);	// First substring found, get rest in switch below
		string lName;
		string fName;
		string eml;
		int age;
		int day1;
		int day2;
		int day3;
		DegreeProgram deg;


		for (size_t j = 0; j < 9; j++)
		{
			previousIndex = found;
			found = row.find_first_of(',', found + 1);


			switch (j)
			{
			case 0:
				fName = row.substr(previousIndex + 1, found - previousIndex - 1);
				break;
			case 1:
				lName = row.substr(previousIndex + 1, found - previousIndex - 1);
				break;
			case 2:
				eml = row.substr(previousIndex + 1, found - previousIndex - 1);
				break;
			case 3:
				age = stoi(row.substr(previousIndex + 1, found - previousIndex - 1));
				break;
			case 4:
				day1 = stoi(row.substr(previousIndex + 1, found - previousIndex - 1));
				break;
			case 5:
				day2 = stoi(row.substr(previousIndex + 1, found - previousIndex - 1));
				break;
			case 6:
				day3 = stoi(row.substr(previousIndex + 1, found - previousIndex - 1));
				break;
			case 7:
				if (row.substr(previousIndex + 1, found - previousIndex - 1) == "SECURITY")
					deg = SECURITY;
				else if (row.substr(previousIndex + 1, found - previousIndex - 1) == "NETWORK")
					deg = NETWORK;
				else if (row.substr(previousIndex + 1, found - previousIndex - 1) == "SOFTWARE")
					deg = SOFTWARE;
				break;
			}
		}


		classRoster.add(ID, fName, lName, eml, age, day1, day2, day3, deg);
	}







	while (!endProgram)
	{
		cout << "Enter command" << endl;
		cin >> keyboardInput;




		// Exit applicaiton!
		if (keyboardInput == "exit") { endProgram = true; }

		// print the current student roster
		else if (keyboardInput == "print")
		{
			cout << "Enter student ID:";
			cin >> keyboardInput;

			if (keyboardInput.substr(0, 1) == "A" || keyboardInput.substr(0, 1) == "a")
			{				
					Student student = classRoster.GetStudent(stoi(keyboardInput.substr(1, 1)));
					student.print();		
			}
		}
		// print all students
		else if (keyboardInput == "printall")
		{
			classRoster.printAll();
		}

		// Remove student
		else if (keyboardInput == "remove")
		{
			cout << "Enter student ID to remove:";
			cin >> keyboardInput;

			classRoster.remove(keyboardInput);
		}

		// Print average days
		else if (keyboardInput == "average")
		{
			cout << "Enter student ID:";
			cin >> keyboardInput;

			classRoster.printAverageDaysInCourse(keyboardInput);
		}

		// Invalid emails
		else if (keyboardInput == "invalid")
		{
			classRoster.printInvalidEmails();
		}

		// Print by degree
		else if (keyboardInput == "degree")
		{
			DegreeProgram degree;

			cout << "Select the desired degree (by number):" << endl;
			cout << "1.  SECURITY" << endl << "2.  NETWORK" << endl << "3.  SOFTWARE" << endl;

			cin >> keyboardInput;

			if (keyboardInput == "1" || keyboardInput == "2" || keyboardInput == "3")
			{
				int degreeIndex = stoi(keyboardInput) - 1;
				degree = (DegreeProgram)degreeIndex;

				classRoster.printByDegreeProgram(degree);
			}
			
		}
		
	}


	


	return 0;
}



Roster::~Roster() {}