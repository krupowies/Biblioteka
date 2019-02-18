#include "stdafx.h"
#include "listSupport.h"

//METODY TO DO
//-> znajdz po ID w liscie ksiazek zadana ksiazke DONE
//-> znajd usera po id DONE 
//-> metoda readborrowed dziala tak ze w pliku jest "1" wczytuje jeden i ta jedynka to jest ID i szukamy w liscie zwracamy wskaznik na obiekt
//-> to samo z ksaizka co wyzej 
//tworzymy nowy obiekt w liscie borrow plus do tego setery na te obiekty ksaizka i uztkownik 


List::~List()
{
	saveToFile("books.txt", BookList);
	saveToFile("users.txt", UserList);
	saveToFile("borrowed.txt", BorrowedList);
}

List::List() : UserList(std::list<User>()), BookList(std::list<Book>())
{
	readAll();
}

std::list<Book>* List::GetPonterBookList()
{
	return &BookList;
}

std::list<User>* List::GetPointerUserList()
{
	return &UserList;
}

std::list<Borrowed>* List::GetPointerBorrowedList()
{
	return &BorrowedList;
}

void List::readAll()
{
	readData<User>("users.txt", UserList);
	readData<Book>("books.txt", BookList);
	borrowedList("borrowed.txt");
}

void List::consoleAllOut()
{
	std::cout << "SPIS WSZYSTKICH KSIAZEK" << std::endl;
	Book::headLineBook();
	std::list <Book> ::iterator Bookit;
	for (Bookit = BookList.begin(); Bookit != BookList.end(); ++Bookit)
	{
		(*Bookit).bookConsoleOut();
	}
	std::cout << std::endl;
	std::cout << "SPIS WSZYSTKICH CZYTELNIKOW " << std::endl;
	User::headLineUser();
	std::list<User>::iterator Userit;
	for (Userit = UserList.begin(); Userit != UserList.end(); Userit++)
	{
		(*Userit).userConsoleOut();
	}
	std::cout << std::endl;
	std::cout << "SPIS WSZYSTKICH WYPOZYCZEN" << std::endl;
	Borrowed::headLineBorrowed();
	std::list <Borrowed> ::iterator Borrowedit;
	for (Borrowedit = BorrowedList.begin(); Borrowedit != BorrowedList.end(); ++Borrowedit)
	{
		(*Borrowedit).borrowConsoleOut();
	}
	std::cout << std::endl;
}

void List::showList()
{
		Book::headLineBook();
		std::list <Book> ::iterator Bookit;
		for (Bookit = BookList.begin(); Bookit != BookList.end(); ++Bookit)
		{
			std::cout << *Bookit;
		}
		std::cout << std::endl;
		User::headLineUser();
		std::list<User>::iterator Userit;
		for (Userit = UserList.begin(); Userit != UserList.end(); Userit++)
		{
			std::cout << *Userit << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
		Borrowed::headLineBorrowed();
		std::list <Borrowed> ::iterator Borrowedit;
		for (Borrowedit = BorrowedList.begin(); Borrowedit != BorrowedList.end(); ++Borrowedit)
		{
			std::cout << *Borrowedit << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
}

template <class T>
void List::readData(std::string fileName, std::list<T> &list) 
{
	std::fstream readFile;
	readFile.open(fileName, std::ios::in);

	if (readFile.good())
	{
		T listElement;
		while (readFile >> listElement) 
		{
			list.push_back(listElement);
		}

		readFile.close();
	}
}

template<class T>
void List::saveToFile(std::string fileName, std::list<T>& list)
{
	std::fstream file;
	file.open(fileName, std::ios::out);
	if (file.good()) 
	{
		std::list<T>::iterator it;
		for (it = list.begin(); it != list.end(); it++)
		{
			file << *it << " ";
		}
		file.close();
	}
}

User * List::findUser(int ID)
{
	std::list<User>::iterator Userit;
	for (Userit = UserList.begin(); Userit != UserList.end(); ++Userit) {
		if ((*Userit).GetID() == ID)
		{
			return &(*Userit);
		}
	}
	return nullptr;
}

Book * List::findBook(std::string title)
{
	std::list<Book>::iterator Bookit;
	for (Bookit = BookList.begin(); Bookit != BookList.end(); ++Bookit)
	{
		if ((*Bookit).GetTitle()==title) 
		{
			return &(*Bookit);
		}
	}
	return nullptr;
}

Book * List::findBookByID(int bookID)
{
	std::list<Book>::iterator Bookit;
	for (Bookit = BookList.begin(); Bookit != BookList.end(); ++Bookit)
	{
		if ((*Bookit).GetBookID() == bookID)
		{
			return &(*Bookit);
		}
	}
	return nullptr;
}

Borrowed * List::findRent(int ID)
{
	std::list<Borrowed>::iterator Borrowit;
	for (Borrowit = BorrowedList.begin(); Borrowit != BorrowedList.end(); ++Borrowit) 
	{
		if ((*Borrowit).GetBorrowedID() == ID)
		{
			return &(*Borrowit);
		}
	}
	return nullptr;
}


void List::borrowedList(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (file.good())
	{
		int borrowID;
		int userID;
		int bookID;
		Date dateOfRent, dateOfReturn;
		bool status;
		while (file >> borrowID >> userID >> bookID >> dateOfRent >> dateOfReturn >> status) 
		{
			User* user = findUser(userID);
			Book* book = findBookByID(bookID);
			Borrowed borrowed(borrowID, user, book, dateOfRent, dateOfReturn, status);
			BorrowedList.push_back(borrowed);
		}

		file.close();
	}
}

void List::saveAllToFile()
{
	readData<User>("users.txt", UserList);
	readData<Book>("books.txt", BookList);
}

void List::addNewBook(Book book)
{
	BookList.push_back(book);
}

void List::addNewUser(User user)
{
	UserList.push_back(user);
}

void List::addNewBorrowed(Borrowed book)
{
	BorrowedList.push_back(book);
}