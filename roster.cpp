#include <iostream>
#include <string>
#include <stdlib.h>

#include "roster.h"

using namespace std;

Roster::Roster()
{
}
Roster::~Roster()
{
}

void Roster::parse(string row)
{
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	DegreeProgram degreeprogram;

	string comma = ",";
	studentID=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	firstName=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	lastName=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	emailAddress=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	string temp1, temp2, temp3,temp4;

	temp1 = row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	int age = stoi(temp1);

	temp2=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	temp3=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	temp4=row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	int daysInCourse1=stoi(temp2);
	int daysInCourse2=stoi(temp3);
	int daysInCourse3=stoi(temp4);

	string temp = row.substr(0,row.find(comma));
	row.erase(0, row.find(comma) + comma.length());

	if(temp=="SECURITY")
	{
		degreeprogram = SECURITY;
	}
	else if(temp=="NETWORK")
	{
		degreeprogram = NETWORK;
	}
	else if(temp=="SOFTWARE")
	{
		degreeprogram = SOFTWARE;
	}
	else
	{
		degreeprogram = SOFTWARE;
	}

	add(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3,degreeprogram);
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysInCourse[] = {daysInCourse1,daysInCourse2,daysInCourse3};

	Student student = Student(studentID,
					firstName,
					lastName,
					emailAddress,
					age,
					daysInCourse,
					degreeprogram);
	classRosterArray.push_back(student);
}
void Roster::remove(string studentID)
{
	bool isErased = false;
	for (int i=0;i<classRosterArray.size();i++)
	{
		if (classRosterArray.at(i).getStudentId()==studentID)
		{
			isErased = true;
			classRosterArray.erase(classRosterArray.begin() + i);
		}
	}
	if (isErased == false)
	{
		cout << "No student found with ID: " << studentID << endl;
	}
}

void Roster::printAll()
{
	for (int i=0;i<classRosterArray.size();i++)
	{
		classRosterArray.at(i).print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	int course1, course2, course3;
	for (int i=0;i<classRosterArray.size();i++)
	{
		if (classRosterArray.at(i).getStudentId()==studentID)
		{
			course1=classRosterArray.at(i).getNumberofdaystocomplete3courses(0);
			course2=classRosterArray.at(i).getNumberofdaystocomplete3courses(1);
			course3=classRosterArray.at(i).getNumberofdaystocomplete3courses(2);
		}
	}
	int averageDays=(course1+course2+course3)/3;

	cout << "Student ID: " << studentID << ", average days in course is: " << averageDays << endl;
	}

void Roster::printInvalidEmails()
{
	for (int i=0; i<classRosterArray.size();i++)
	{
		if (classRosterArray.at(i).getEmailAddress().find('@')==string::npos
				&& classRosterArray.at(i).getEmailAddress().find(".com")==string::npos)
		{
			cout << classRosterArray.at(i).getEmailAddress()<< "- is invalid." << endl;

		}
	}
}
 void Roster::printByDegreeProgram (DegreeProgram degreeProgram)
 {
	 for (int i=0;i<classRosterArray.size();i++)
	 {
		 if (classRosterArray.at(i).getDegreeProgram()== degreeProgram)
		 {
			 classRosterArray.at(i).print();
		 }
	 }
 }
