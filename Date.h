#pragma once
class Date
{
public:
	Date();
	Date(int, int, int);
	~Date();

	int day = 0;
	int month = 0;
	int year = 0;
};