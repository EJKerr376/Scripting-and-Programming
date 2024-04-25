#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

const string studentData[] = {"A1, John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Elizabeth,Kerr,ekerr14@wgu.edu,29,30,35,32,SOFTWARE"};

int main()
{
	cout<< "C867-Scripting & Programming: Application"<< endl
			<< "Language: C++" << endl
			<< "Student ID: 010413969" << endl
			<< "Name: Elizabeth Kerr" << endl << endl;

	Roster classRoster=Roster();
	for (int i=0;i<5;i++)
	{
		classRoster.parse(studentData[i]);
	}
	cout << "Displaying all students:"<<endl;
	classRoster.printAll();
	cout<< "Displaying invalid emails:"<<endl << endl;
	classRoster. printInvalidEmails();

	for (int i=0;i<5;i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray.at(i).getStudentId());

	}

	 cout << "\nShowing students in degree program: SOFTWARE"<<endl;

	 classRoster.printByDegreeProgram(SOFTWARE);
	 string id = "A3";
	 cout<< "\nRemoving A3\n"<< endl;

	 classRoster.remove(id);
	 classRoster.printAll();
	 cout<< "\nRemoving A3 again\n"<< endl;

	 classRoster.remove(id);
cout <<"DONE." <<endl;
	return 0;
}
