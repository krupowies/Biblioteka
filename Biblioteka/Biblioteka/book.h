#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
#include "date.h"

class Book
{
private:
	int bookID;
	std::string title;
	std::string author;
	std::string genre;
	int numberOfPages;
	Date dateOfPublication;
	bool availability;

public:
	//Constructors and destructor
	Book() = default;
	Book(int, std::string, std::string, std::string, int, Date,bool);
	~Book();
	//Operators
	friend std::ostream& operator<<(std::ostream &os, Book &book);
	friend std::istream& operator >> (std::istream &in, Book &book);
	friend std::istream& operator >> (std::istream &in, Book &genre);
	bool operator ==(Book book);
	//Getters
	int GetBookID() const;
	std::string GetTitle() const;
	std::string GetAuthor() const;
	std::string GetGenre() const;
	int GetNumberOfPages() const;
	Date GetDateOfPublication() const;
	bool GetAvailability() const;
	//Setters
	void SetBookID(int ID);
	void SetTitle(std::string title);
	void SetAuthor(std::string author);
	void SetGenre(std::string genre);
	void SetNumberOfPages(int numberOfPages);
	void SetDateOfPublication(Date dateOfPublication);
	void SetAvailability(bool avilability);
	//Methods
	static Book createNew();
	static void headLineBook();
	void bookConsoleOut();

};




