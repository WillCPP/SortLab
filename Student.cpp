#include "Student.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student()
{

}

Student::Student(string first, string last, string mNum, Date date, double gpa = 0.0)
{
	this->FirstName = first;
	this->LastName = last;
	this->MNumber = mNum;
	this->Birthday = date;
	this->GPA = gpa;
}

Student::~Student()
{
}

string Student::GetName()
{
	return this->FirstName + " " + this->LastName;
}

string Student::GetMNumber()
{
	return this->MNumber;
}

int Student::GetAge()
{
	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);
	struct tm parts;
	localtime_s(&parts, &now_c);

	int cur_year = parts.tm_year + 1990;
	int cur_month = parts.tm_mon;
	int cur_day = parts.tm_mday;

	int age = cur_year - this->Birthday.year;
	if (cur_month >= this->Birthday.month)
	{
		if (cur_day >= this->Birthday.day)
		{
			age += 1;
		}
	}

	return age;
}

bool Student::operator<(Student s)
{
	string first_m = this->MNumber.substr(1, string::npos);
	string second_m = s.MNumber.substr(1, string::npos);
	bool bolReturn = false;
	if (stoi(first_m) < stoi(second_m))
	{
		bolReturn = true;
	}
	return bolReturn;
}

bool Student::operator>(Student s)
{
	string first_m = this->MNumber.substr(1, string::npos);
	string second_m = s.MNumber.substr(1, string::npos);
	bool bolReturn = false;
	if (stoi(first_m) > stoi(second_m))
	{
		bolReturn = true;
	}
	return bolReturn;
}

bool Student::operator==(Student s)
{
	string first_m = this->MNumber.substr(1, string::npos);
	string second_m = s.MNumber.substr(1, string::npos);
	bool bolReturn = false;
	if (stoi(first_m) == stoi(second_m))
	{
		bolReturn = true;
	}
	return bolReturn;
}

void Student::DisplayData()
{
	cout << "Name: " << this->LastName << ", " << this->FirstName << endl;
	cout << "M-Number: " << this->MNumber << endl;
	cout << "GPA: " << setprecision(2) << fixed << this->GPA << endl;
}
