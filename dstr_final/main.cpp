#include <iostream>
#include "List.h"
#include "Books.h"
#include "Patron.h"
#include "BookList.h"
#include "PatronList.h"

using namespace std;

//initializing the PatronID and BookID
int Patron::id{ 1 };
int Books::id{ 1 };

PatronList<Patron> patronList;
BookList<Books> bookList;


void searchBooks() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\nSearch Options:";
		cout << "\n1. Name \n2. Category \n3. Genre \n";
		cout << "4. Availibility \n5. Back \n6. Exit to Main Menu \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		cout << "\nEnter search term: ";
		string searchTerm;
		getline(cin, searchTerm);
		switch (option)
		{
		case 1:
		{
			bookList.search(searchTerm, 1);
			break;
		}
		case 2:
		{
			bookList.search(searchTerm, 2);
			break;
		}
		case 3:
		{
			bookList.search(searchTerm, 3);
			break;
		}
		case 4:
		{
			bookList.search(searchTerm, 4);
			break;
		}
		case 5:
			void manageBooks();
			break;
		case 6:
			cout << "\n";
			int main();
			break;
		default:
			cout << "Invalid option.\n";
			continueProgram = true;
			break;
		}
		continueProgram = false;
	}
}


void updateBook() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\nUpdate Options:";
		cout << "\n1. Name \n2. Category \n3. Genre \n";
		cout << "\n4. Back \n5. Exit to Main Menu \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		cout << "\nEnter update term: ";
		string updateTerm;
		getline(cin, updateTerm);
		int bookID;
		cout << "Please enter book ID: ";
		cin >> bookID;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		bool flag = false;
		switch (option)
		{
		case 1:
		{
			flag = bookList.update(bookID, updateTerm, 1);
			bookList.printBook(bookID);
			break;
		}
		case 2:
		{
			flag = bookList.update(bookID, updateTerm, 2);
			bookList.printBook(bookID);
			break;
		}
		case 3:
		{
			flag = bookList.update(bookID, updateTerm, 3);
			bookList.printBook(bookID);
			break;
		}
		case 4:
			void manageBooks();
			break;
		case 5:
			cout << "\n";
			int main();
			break;
		default:
			cout << "Invalid option.\n";
			continueProgram = true;
			break;
		}
		if (flag) {
			cout << "Update successful";
		}
		else {
			cout << "Update Failed";
			continueProgram = true;
		}
		continueProgram = false;
	}
}


void updatePatron(int patronID) {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\nUpdate Options:";
		cout << "\n1. Name \n2. Address \n3. Phone Number \n";
		cout << "\4. Back \n5. Exit to Main Menu \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		cout << "\nEnter update term: ";
		string updateTerm;
		getline(cin, updateTerm);
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		bool flag = false;
		switch (option)
		{
		case 1:
		{
			flag = patronList.update(patronID, updateTerm, 1);
			patronList.printPatron(patronID);
			break;
		}
		case 2:
		{
			flag = patronList.update(patronID, updateTerm, 2);
			patronList.printPatron(patronID);
			break;
		}
		case 3:
		{
			flag = patronList.update(patronID, updateTerm, 3);
			patronList.printPatron(patronID);
			break;
		}
		case 4:
			void managePatrons();
			break;
		case 5:
			cout << "\n";
			int main();
			break;
		default:
			cout << "Invalid option.\n";
			continueProgram = true;
			break;
		}
		if (flag) {
			cout << "Update successful";
		}
		else {
			cout << "Update Failed";
			continueProgram = true;
		}
		continueProgram = false;
	}
}


void searchPatrons() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\nSearch Options:";
		cout << "\n1. Patron ID \n2. Name \n3. Back \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		switch (option)
		{
		case 1:
		{
			int patronID;
			cout << "Please enter Patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			patronList.search(patronID);
			break;
		}
		case 2:
		{
			cout << "\nEnter Patron Name: ";
			string name;
			getline(cin, name);
			patronList.search(name);
			break;
		}
		case 3:
			cout << "\n";
			void managePatrons();
			break;
		default:
			cout << "Invalid option.\n";
			continueProgram = true;
			break;
		}
		continueProgram = false;
	}
}


void manageBooks() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\n1. Add Book \n2. Display Available Books \n";
		cout << "3. Search Books \n4. Update Book \n5. Exit to Main Menu \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n

		switch (option)
		{
		case 1: 
		{
			Books* book = new Books;
			book->create();
			bookList.add(book);
			break;
		}
		case 2:
		{
			bookList.printAvailable();
			break;
		}
		case 3:
		{
			searchBooks();
			break;
		}
		case 4:
		{
			updateBook();
			break;
		}
		case 5:
		{
			cout << "\n";
			int main();
			continueProgram = false;
			break;
		}
		default:
			cout << "Invalid option.\n";
			break;
		}
	}
}


void managePatrons() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\n1. Register Patron \n2. View Patrons with Active Books Borrowed \n";
		cout << "3. Search Patron \n4. Update Patron \n5. Display Last 10 Books Borrowed \n";
		cout << "6. Exit to Main Menu\n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		switch (option)
		{
		case 1:
		{
			Patron* patron = new Patron;
			patron->registerPatron();
			patron->library = &bookList;
			patronList.add(patron);
			break;
		}
		case 2:
		{
			patronList.booksBorrowed();
			break;
		}
		case 3:
		{
			searchPatrons();
			break;
		}
		case 4:
		{
			int patronID;
			cout << "\nPlease enter patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			if (patronList.verifyID(patronID)) {
				updatePatron(patronID);
			}
			else {
				cout << "Invalid patron ID";
				continueProgram = true;
			}
			break;
		}
		case 5:
		{
			int patronID;
			cout << "\nPlease enter patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			if (patronList.verifyID(patronID)) {
				patronList.displayLastTen(patronID);
			}
			else {
				cout << "Invalid patron ID";
				continueProgram = true;
			}
			break;
		}
		case 6:
			cout << "\n";
			int main();
			continueProgram = false;
			break;
		default:
			cout << "Invalid option.\n";
			break;
		}
	}
}


void manageLibrary() {
	bool continueProgram = true;
	while (continueProgram) {
		cout << "\n1. Borrow Book \n2. Return Book \n3. Extend Return Date \n";
		cout << "4. Exit to Main Menu \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		switch (option)
		{
		case 1: 
		{
			int patronID;
			cout << "\nPlease enter patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			if (patronList.verifyID(patronID)) {
				Patron* patron = patronList.getInfo(patronID);
				int bookID;
				cout << "\nPlease enter book ID: ";
				cin >> bookID;
				cin.clear(); //clear bad inputs
				cin.ignore(); //ignores the \n
				patron->borrow(bookID);
			}
			else {
				cout << "Invalid patron ID";
				continueProgram = true;
			}
			break;
		}
		case 2:
		{
			int patronID;
			cout << "\nPlease enter patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			if (patronList.verifyID(patronID)) {
				Patron* patron = patronList.getInfo(patronID);
				int bookID;
				cout << "\nPlease enter book ID: ";
				cin >> bookID;
				cin.clear(); //clear bad inputs
				cin.ignore(); //ignores the \n
				patron->returnBook(bookID);
			}
			else {
				cout << "Invalid patron ID";
				continueProgram = true;
			}
			break;
		}
		case 3:
		{
			int patronID;
			cout << "\nPlease enter patron ID: ";
			cin >> patronID;
			cin.clear(); //clear bad inputs
			cin.ignore(); //ignores the \n
			bool flag = false;
			if (patronList.verifyID(patronID)) {
				bool flag = patronList.changeReturnDate(patronID);
			}
			else {
				cout << "Invalid patron ID";
				continueProgram = true;
			}
			if (flag) {
				cout << "Update successful";
			}
			else {
				cout << "Update Failed";
				continueProgram = true;
			}
			break;
		}
		case 4:
			cout << "\n";
			int main();
			continueProgram = false;
			break;
		default:
			cout << "Invalid option.\n";
			break;
		}
	}
}


int main() {
	bool continueProgram = true;
	cout << "Welcome to the Library Management System. \n";
	while (continueProgram) {
		cout << "\n1. Manage Books \n2. Manage Patrons \n";
		cout << "3. Borrow or Return Book \n4. Exit \n";
		int option;
		cout << "Please select an option: ";
		cin >> option;
		cin.clear(); //clear bad inputs
		cin.ignore(); //ignores the \n
		switch (option)
		{
		case 1:
			manageBooks();
			break;
		case 2:
			managePatrons();
			break;
		case 3:
			manageLibrary();
			break;
		case 4:
			cout << "Goodbye.\n";
			continueProgram = false;
			break;
		default:
			cout << "Invalid option.\n";
			break;
		}
	}
}