#pragma once

#include "stdafx.h"
#include "borrowed.h"
#include <string>

class User
{
private:
	std::string name;
	std::string lastName;
	int userID;
	int numberOfBorrowed;

public:
	//Constructors and destructor
	User() = default;
	User(std::string, std::string, int, int);
	~User() = default;
	//Methods
	static User createNew();
	static void headLineUser();
	void userConsoleOut();

	//Setters
	std::string GetName() const;
	std::string GetLastName() const;
	int GetID() const;
	int  GetNumberOfBorrowed() const;

	//Setters
	void SetName(std::string);
	void SetLastName(std::string);
	void SetID(int);
	void SetNumberOfBorrowed(int);

	//Operators
	friend std::ostream& operator<<(std::ostream &os, User &user);
	friend std::istream& operator>>(std::istream &is, User &user);
	bool operator == (User user);
};
