#pragma once

#include <string>
#include "Date.h"
using namespace std;

class Student
{
private:
	string FirstName = "";
	string LastName = "";
	string MNumber = "";
	double GPA = 0.0;
	Date Birthday = Date();
public:
	Student();
	Student(string, string, string, Date, double);
	~Student();

	string GetName();
	string GetMNumber();
	int GetAge();
	bool operator<(Student);
	bool operator>(Student);
	bool operator==(Student);

	void DisplayData();
};
