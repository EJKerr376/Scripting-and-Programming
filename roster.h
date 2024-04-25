#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <vector>

using namespace std;

class Roster
{
public:

	Roster();
	virtual ~Roster();

	virtual void parse (string row);

	virtual void add(string studentID, string firstName, string lastName, string emailAddress,
						int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	virtual void remove(string studentID);

	virtual void printAll();

	virtual void printAverageDaysInCourse(string studentID);

	virtual void printInvalidEmails();

	virtual void printByDegreeProgram (DegreeProgram degreeProgram);

	vector<Student> classRosterArray;
};

#endif
