#include "stdafx.h"
#include "date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::~Date()
{
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}

void Date::SetDay(int day) 
{
	this->day = day;
}

void Date::SetMonth(int month)
{
	this->month = month;
}

void Date::SetYear(int year)
{
	this->year = year;
}

void Date::dateConsoleOut()
{
   std::cout << day << "." << month << "." << year << "r";
}

std::ostream & operator<<(std::ostream & os, Date & date)
{
	os << date.day << " " << date.month << " " << date.year;
	return os;
}

std::istream & operator>>(std::istream & is, Date & date)
{
	is >> date.day;
	is >> date.month;
	is >> date.year;

	return is;
}

