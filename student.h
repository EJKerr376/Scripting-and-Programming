#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student
{
public:
	Student(string studentId,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int daysInCourse[3],
			DegreeProgram degreeProgram);

	virtual ~Student();

	int getAge() const;

	void setAge(int age);

	DegreeProgram getDegreeProgram() const;

	void setDegreeProgram(DegreeProgram degreeProgram);

	string getEmailAddress() const;

	void setEmailAddress(const string &emailAddress);

	string getFirstName() const;

	void setFirstName(const string &firstName);

	string getLastName() const;

	void setLastName(const string &lastName);

	int getNumberofdaystocomplete3courses(const int courseNum) const;

	void setNumberofdaystocomplete3courses(const int daysToComplete, const int courseNum);

	string getStudentId() const;

	void setStudentId(const string StudentId);

	virtual void print();

private:
	string mStudentID;
	string mFirstName;
	string mLastName;
	string mEmailAddress;
	int mAge;
	DegreeProgram mDegreeProgram;
	int* mNumberofdaystocomplete3courses;

};

#endif
