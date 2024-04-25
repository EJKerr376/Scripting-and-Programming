#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student(string studentId,
				string firstName,
				string lastName,
				string emailAddress,
				int age,
				int daysInCourse[3],
				DegreeProgram degreeProgram):
	mStudentID(studentId),
	mFirstName(firstName),
	mLastName(lastName),
	mEmailAddress(emailAddress),
	mAge(age),
	mDegreeProgram(degreeProgram)
{
	mNumberofdaystocomplete3courses = (int*)malloc(3);
	mNumberofdaystocomplete3courses[0] = daysInCourse[0];
	mNumberofdaystocomplete3courses[1] = daysInCourse[1];
	mNumberofdaystocomplete3courses[2] = daysInCourse[2];
}

Student::~Student()
{
}

int Student::getAge() const
{
	return mAge;
}

void Student::setAge(int age)
{
	mAge = age;
}

string Student::getFirstName() const
{
	return mFirstName;
}

void Student::setFirstName(const string& firstName)
{
	mFirstName = firstName;
}

string Student::getLastName()const
{
	return mLastName;
}

void Student::setLastName(const string& lastName)
{
	mLastName = lastName;
}

string Student::getEmailAddress() const
{
	return mEmailAddress;
}
void Student::setEmailAddress(const string& emailAddress)
{
	mEmailAddress = emailAddress;
}

string Student::getStudentId()const
{
	return mStudentID;
}

void Student::setStudentId (const string StudentID)
{
	mStudentID = StudentID;
}

int Student::getNumberofdaystocomplete3courses(const int courseNum)const
{
	return mNumberofdaystocomplete3courses[courseNum];
}

void Student::setNumberofdaystocomplete3courses(const int daysToComplete, const int courseNum)
{
	mNumberofdaystocomplete3courses[courseNum] = daysToComplete;
}

DegreeProgram Student::getDegreeProgram()const
{
	return mDegreeProgram;
}

void Student::setDegreeProgram(const DegreeProgram degreeProgram)
{
	mDegreeProgram = degreeProgram;
}

void Student::print()
{
	string degreeType;
	if (mDegreeProgram == SOFTWARE)
	{
		degreeType = "SOFTWARE";
	}
	else if (mDegreeProgram == NETWORK)
	{
		degreeType = "NETWORK";
	}
	else
	{
		degreeType = "SECURITY";
	}
	cout<< mStudentID<<"\t"<<mFirstName<<"\t"
			<<mLastName<<"\t"<<mAge<<
			"\t{"<<mNumberofdaystocomplete3courses[0]<<","
			<<mNumberofdaystocomplete3courses[1]<<","
			<<mNumberofdaystocomplete3courses[2]<<"}\t"
			<<degreeType<< endl;

}
