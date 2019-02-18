#pragma once

#include "stdafx.h"
#include "book.h"
#include <list>
#include "borrowed.h"
#include "user.h"
#include <fstream>

class List {
public:
	List();
	~List();
	std::list<Book> BookList;
	std::list<User> UserList;
	std::list<Borrowed> BorrowedList;
	//Getters
	std::list<Book>* GetPonterBookList();
	std::list<User>* GetPointerUserList();
	std::list<Borrowed>* GetPointerBorrowedList();
	//Methods
	void readAll();
	void consoleAllOut();
	template <class T>
	void readData(std::string fileName, std::list<T> &list);
	void showList();
	User* findUser(int ID);
	Book* findBook(std::string title);
	Book* findBookByID(int bookID);
	Borrowed* findRent(int ID);
	void borrowedList(std::string fileName);
	template <class T>
	void saveToFile(std::string fileName, std::list<T> &list);
	void saveAllToFile();
	void addNewBook(Book book);
	void addNewUser(User user);
	void addNewBorrowed(Borrowed book);

};

