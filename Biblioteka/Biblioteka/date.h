#pragma once

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <string>

struct Date
{
	int day;
	int month;
	int year;

	Date() = default;
	Date(int, int, int);
	~Date();

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);

	friend std::ostream& operator << (std::ostream &os, Date &date);
	friend std::istream& operator >> (std::istream &is, Date &date);
	void dateConsoleOut();
};
