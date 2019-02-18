#include "stdafx.h"
#include <list>
#include "listSupport.h"
#include "menu.h"

void showMenu()
{
	std::cout << "Wybierz opcje z ponizszych: " << std::endl;
	std::cout << "[1] Zobacz cala baze" << std::endl;
	std::cout << "[2] Wyszukaj uzytkownika" << std::endl;
	std::cout << "[3] Wyszukaj ksiazke" << std::endl;
	std::cout << "[4] Wypozycz ksiazke" << std::endl;
	std::cout << "[5] Oddaj ksiazke" << std::endl;
	std::cout << "[6] Dodaj nowa ksiazke do bazy" << std::endl;
	std::cout << "[7] Dodaj nowego uzytkownika do bazy" << std::endl;
	std::cout << "[8] Opusc program" << std::endl;
}

void clearMenu()
{
	system("cls");
}


void mainMenu()
{
	int option = 0;
	List lista;
	while (option != 8)
	{
		User newUser;
		Book newBook;
		Book* pBook;
		User* pUser;
		Borrowed newBorrowed;
		Borrowed* pBorrow;
		Date dateOfRent;
		Date dateOfReturn;
		int rentID = 0;
		int temp = 0;
		showMenu();
		std::cin >> option;
		int wantedID = 0;
		std::string wantedTitle;
		int userID = 0;
		int bookID = 0;

		switch (option)
		{
		case 1: //wyswietlanie calej bazy
			clearMenu();
			lista.consoleAllOut();
			std::cout << std::endl;
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 2: //szukanie czytelnika w bazie
			clearMenu();
			std::cout << "Podaj ID klienta ktorego szukasz :";
			std::cin >> wantedID;
			if (lista.findUser(wantedID))
			{
				User::headLineUser();
				std::cout << *(lista.findUser(wantedID));
			}
			else
				std::cout << "NIE MA TAKIEGO UZYTKOWNIKA W NASZEJ BAZIE";
			std::cout << std::endl;
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 3: //szukanie ksiazki w bazie
			clearMenu();
			std::cout << "Podaj tytul ksaizki ktorej szukasz : ";
			std::cin >> wantedTitle;
			if (lista.findBook(wantedTitle))
			{
				Book::headLineBook();
				std::cout << *(lista.findBook(wantedTitle));
			}
			else
				std::cout << "NIE MA TAKIEJ KSIAZKI W NASZEJ BAZIE";
			std::cout << std::endl;
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 4: //wypozyczanie ksiazki
			clearMenu();
			std::cout << "Nadaj ID wypozyczeniu :";
			std::cin >> rentID;
			std::cout << "Podaj ID klienta ktory wypozycza :";
			std::cin >> userID;
			std::cout << "Podaj ID ksiazki ktora wypozyczasz :";
			std::cin >> bookID;
			pBook = lista.findBookByID(bookID);
			if (pBook->GetAvailability() == 0)
			{
				std::cout << "KSIAZKA JEST NIEDOSTEPNA" << std::endl;
				std::cout << "____________________________________________________" << std::endl;
				std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
				std::cin.ignore();
				std::cin.get();
				clearMenu();
					break;
			}
			std::cout << "Podaj date wypozeczenia  :";
			std::cin >> dateOfRent;
			std::cout << "Podaj date zwrotu :";
			std::cin >> dateOfReturn;
			pUser = lista.findUser(userID);
			temp = pUser->GetNumberOfBorrowed();
			pUser->SetNumberOfBorrowed(temp + 1);
			newBorrowed.createNew();
			newBorrowed.SetBorrowID(rentID);
			newBorrowed.SetUser(pUser);
			newBorrowed.SetBook(pBook);
			newBorrowed.SetDateOfRent(dateOfRent);
			newBorrowed.SetDateOfReturn(dateOfReturn);
			newBorrowed.SetStatus(1);
			pBook->SetAvailability(0);
			lista.addNewBorrowed(newBorrowed);
			std::cout << std::endl;
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 5: //zwracanie ksiazki
			clearMenu();
			std::cout << "Podaj ID wypozyczenia :";
			std::cin >> rentID;
			if (lista.findRent(rentID))
			{
				pBorrow = lista.findRent(rentID);
				pBorrow->GetBook()->SetAvailability(1);
				pBorrow->SetStatus(0);
				std::cout << std::endl;
			}
			else
			{
				std::cout << "NIE MA TAKIEGO WYPOZYCZENIA W NASZEJ BAZIE";
				std::cout << std::endl;
			}
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 6://dodawanie nowej ksiazki
			clearMenu();
			newBook = Book::createNew();
			if (lista.findBookByID(newBook.GetBookID()))
				std::cout << "TAKIE ID JUZ ISTNIEJE, PODAJ INNE ID" << std::endl;
			else
			{
				lista.addNewBook(newBook);
				std::cout << std::endl;
			}
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
		
			break;

		case 7://dodawanie nowego uzytkownika
			clearMenu();
			newUser = User::createNew();
			if (lista.findUser(newUser.GetID()))
				std::cout << "TAKIE ID JUZ ISTNIEJE, PODAJ INNE ID" << std::endl;
			else
			{
				lista.addNewUser(newUser);
				std::cout << std::endl;
			}
			std::cout << "____________________________________________________" << std::endl;
			std::cout << "NACISNIJ PRZYCISK ENTER ABY WROCIC DO MENU GLOWNEGO" << std::endl;
			std::cin.ignore();
			std::cin.get();
			clearMenu();
			break;
		case 8:
			std::cout << "Progam konczy prace" << std::endl;
			break;

		default:
			clearMenu();
			showMenu();
			break;

		}
	}
}