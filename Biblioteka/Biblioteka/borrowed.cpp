#include "stdafx.h"
#include "borrowed.h"



Borrowed::Borrowed(int borrowID, User *user, Book *book, Date dateOfRent, Date dateOfReturn, bool status) : borrowID(borrowID), user(user), book(book), dateOfRent(dateOfRent),
dateOfReturn(dateOfReturn), status(status)
{
}

Borrowed::~Borrowed()
{
}


int Borrowed::GetBorrowedID() const
{
	return borrowID;
}

User* Borrowed::GetUser() const
{
	return user;
}

Book * Borrowed::GetBook() const
{
	return book;
}

Date Borrowed::GetDateOfRent()
{
	return dateOfRent;
}

Date Borrowed::GetDateOfReturn()
{
	return dateOfReturn;
}

bool Borrowed::GetStatus()
{
	return status;
}

void Borrowed::SetBorrowID(int borrowID)
{
	this->borrowID = borrowID;
}

void Borrowed::SetUser(User *user)
{
	this->user = user;
}

void Borrowed::SetBook(Book *book)
{
	this->book = book;
}

void Borrowed::SetDateOfRent(Date dateOfRent)
{
	this->dateOfRent = dateOfRent;
}

void Borrowed::SetDateOfReturn(Date dateOfReturn)
{
	this->dateOfReturn = dateOfReturn;
}

void Borrowed::SetStatus(bool status)
{
	this->status = status;
}

void Borrowed::headLineBorrowed()
{
	std::cout << "ID|imie|nazwisko|data WY|data ZW| STATUS" << std::endl;
}

Borrowed Borrowed::createNew()
{
	return Borrowed();
}

void Borrowed::borrowConsoleOut()
{
	std::cout << borrowID << " " << user->GetName() << " " << user->GetLastName() << " " << book->GetTitle() << " ";
	dateOfRent.dateConsoleOut();
	std::cout << " ";
	dateOfReturn.dateConsoleOut();
	std::cout << " ";
	if (status == 1)
		std::cout << "WYPOZYCZONA";
	else
		std::cout << "ODDANA";

	std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, Borrowed & borrowed)
{
	os << borrowed.borrowID << " " << borrowed.user->GetID() << " " << borrowed.book->GetBookID() << " " << borrowed.dateOfRent << " " << borrowed.dateOfReturn << " "
		<< borrowed.status << " ";
	return os;
}



