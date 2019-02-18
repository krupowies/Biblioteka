#pragma once

#include "stdafx.h"
#include "book.h"
#include "user.h"
#include "date.h"
#include <fstream>
#include <vector>

//forward declaration
class User;
class Book;

class Borrowed
{
private:
	int borrowID;
	User* user;
	Book* book;
	Date dateOfRent;
	Date dateOfReturn;
	bool status;
public:
	//Constructors and destructor
	Borrowed() = default;
	Borrowed(int, User*,Book*,Date,Date,bool);
	~Borrowed();
	//Getters
	int GetBorrowedID() const;
	User* GetUser() const;
	Book* GetBook() const;
	Date GetDateOfRent();
	Date GetDateOfReturn();
	bool GetStatus();
	//Setters
	void SetBorrowID(int);
	void SetUser(User*);
	void SetBook(Book*);
	void SetDateOfRent(Date);
	void SetDateOfReturn(Date);
	void SetStatus(bool);
	//Operators
	friend std::ostream& operator <<(std::ostream &os, Borrowed &borrowed);
	//Methods
	static void headLineBorrowed();
	static Borrowed createNew();
	void borrowConsoleOut();



};



