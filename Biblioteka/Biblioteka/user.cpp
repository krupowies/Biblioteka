#include "stdafx.h"
#include "user.h"

User::User(std::string name, std::string lastName, int userID, int numberOfBorrowed) : name(name), lastName(lastName),
userID(userID), numberOfBorrowed(numberOfBorrowed)
{
}

User User::createNew()
{
	std::string name;
	std::string lastName;
	int ID;
	int numberOfBorrowed = 0;

	std::cout << std::endl;
	std::cout << "PODAJ IMIE NOWEGO UZYTKOWNIKA : ";
	std::cin >> name;
	std::cout << "PODAJ NAZWISKO NOWEGO UZYTKOWNIKA : ";
	std::cin >> lastName;
	std::cout << "PODAJ NUMER INDENTYFIKACYJNY UZYTKOWNIKA : ";
	std::cin >> ID;
	return User(name, lastName, ID, numberOfBorrowed);

}

void User::headLineUser()
{
	std::cout << "IMIE|NAZWISKO|ID|ILOSC WYPOZYCZEN" << std::endl;
}

void User::userConsoleOut()
{
	std::cout << name << " " << lastName << " " << userID << " "<< numberOfBorrowed << std::endl;
}


std::string User::GetName() const
{
	return name;
}

std::string User::GetLastName() const
{
	return lastName;
}

int User::GetID() const
{
	return userID;
}

int User::GetNumberOfBorrowed() const
{
	return numberOfBorrowed;
}

void User::SetName(std::string)
{
	this->name = name;
}

void User::SetLastName(std::string)
{
	this->lastName = lastName;
}

void User::SetID(int)
{
	this->userID = userID;
}

void User::SetNumberOfBorrowed(int numberOfBorrowed)
{
	this->numberOfBorrowed = numberOfBorrowed;
}


bool User::operator==(User user)
{
	if (this->GetID() == user.GetID())
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & os, User & user)
{
	os << user.name << " " << user.lastName << " " << user.userID << " "
		<< user.numberOfBorrowed;
	return os;
}

std::istream & operator>>(std::istream & is, User & user)
{
	is >> user.name;
	is >> user.lastName;
	is >> user.userID;
	is >> user.numberOfBorrowed;
	return is;
}
