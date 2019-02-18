#include "stdafx.h"
#include "book.h"


Book::Book(int bookID,std::string title, std::string author, std::string genre, int numberOfPages, Date dateOfPublication, bool availability) : bookID(bookID), title(title), author(author), genre(genre),
numberOfPages(numberOfPages), dateOfPublication(dateOfPublication), availability(availability)
{
}

Book::~Book()
{
}


bool Book::operator==(Book book)
{
	if (this->GetBookID() == book.GetBookID())
		return true;
	else
		return false;
}

int Book::GetBookID() const
{
	return bookID;
}

std::string Book::GetTitle() const
{
	return title;
}

std::string Book::GetAuthor() const
{
	return author;
}

std::string Book::GetGenre() const
{
	return genre;
}

int Book::GetNumberOfPages() const
{
	return numberOfPages;
}

Date Book::GetDateOfPublication() const
{
	return dateOfPublication;
}

bool Book::GetAvailability() const
{
	return availability;
}

void Book::SetBookID(int bookID)
{
	this->bookID = bookID;
}

void Book::SetTitle(std::string title)
{
	this->title = title;
}

void Book::SetAuthor(std::string author) 
{
	this->author = author;
}

void Book::SetGenre(std::string genre) 
{
	this->genre = genre;
}

void Book::SetNumberOfPages(int numberOfPages)
{
	this->numberOfPages = numberOfPages;
}

void Book::SetDateOfPublication(Date dateOfPublication) 
{
	this->dateOfPublication = dateOfPublication;

}

void Book::SetAvailability(bool availability) 
{
	this->availability = availability;
}

Book Book::createNew()
{
	int ID;
	std::string title;
	std::string author;
	std::string genre;
	int numberOfPages;
	Date dateOfPublication;
	bool availability = 1;

		std::cout << std::endl;
		std::cout << "PODAJ NUMER INDENTYFIKACYJNY KSIAZKI : ";
		std::cin >> ID;
		std::cout << "PODAJ TYTUL KSIAZKI : ";
		std::cin >> title;
		std::cout << "PODAJ NAZWIKO AUTORA : ";
		std::cin >> author;
		std::cout << "PODAJ GATUNEK KSIAZKI : ";
		std::cin >> genre;
		std::cout << "PODAJ ILOSC STRON : ";
		std::cin >> numberOfPages;
		std::cout << "PODAJ DATE WYDANIA : ";
		std::cin >> dateOfPublication;

		return Book(ID,title, author, genre, numberOfPages, dateOfPublication, availability);
}

void Book::headLineBook()
{
	std::cout << "ID|tytul|autor|gatunek|strony|data wydania|STATUS" << std::endl;
}

void Book::bookConsoleOut()
{
	std::cout << bookID << " " << title << " " << author << " " << genre << " " << numberOfPages << " ";
	dateOfPublication.dateConsoleOut();
	std::cout << " ";
	if (availability == 1)
		std::cout << "DOSTEPNA";
	else
		std::cout << "NIEDOSTEPNA";

	std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, Book & book)
{
	os << book.bookID << " " << book.title << " " << book.author << " " << book.genre << " " << book.numberOfPages << " "
		<< book.dateOfPublication << " " << book.availability << std::endl;
	return os;
}

//ewentualnie oddzielna metoda do wypisywania na konsoli

std::istream & operator>>(std::istream & is, Book & book)
{
	is >> book.bookID;
	is >> book.title;
	is >> book.author;
	is >> book.genre;
	is >> book.numberOfPages;
	is >> book.dateOfPublication;
	is >> book.availability;

	return is;
}

