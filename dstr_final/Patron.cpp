#include "Patron.h"

bool Patron::registerPatron() {
	// Returns the Patron ID from static variable
	this->PatronID = this->createID();
	cout << "Enter Patron Name: ";
	getline(cin, name);
	cout << '\n' << "Enter Address: ";
	getline(cin, address);
	cout << '\n' << "Enter Phone Number: " << '\n';
	getline(cin, phoneNum);
	cout << *this;

	return true;
}

/* Returns and then increments the Static Variable
*  Patron::id
*/
int Patron::createID() {
	return Patron::id++;
}


ostream& operator<<(ostream& os, const Patron& patron)
{
	os << "Patron ID: " << patron.PatronID << '\n'
		<< "Patron Name: " << patron.name << '\n'
		<< "Address: " << patron.address << '\n'
		<< "Phone Number: " << patron.phoneNum << '\n'
		<< "Number of Books Borrowed: " << patron.numBooksBorrowed << endl;
	return os;
}

string Patron::getName() {
	return this->name;
}

int Patron::getID() {
	return this->PatronID;
}

int Patron::getNumBooksBorrowed() {
	return this->numBooksBorrowed;
}

void Patron::setName(string name) {
	this->name = name;
}

void Patron::setAddress(string address) {
	this->address = address;
}

void Patron::setPhoneNum(string number) {
	this->phoneNum = number;
}

void Patron::displayBooks() {
	this->booksBorrowed.displayLastTen();
}

bool Patron::borrow(int bookID) {
	bool notFound = true;
	if (this->numBooksBorrowed < 3) {
		pair<bool, Books> result = this->library->borrow(bookID);
		if (result.first) {
			//Books borrowedBook = 
			this->booksBorrowed.add(&this->library->borrowBook(bookID));
			this->numBooksBorrowed++;
			notFound = false;
			return true;
		}
	}
	if (notFound) {
		cout << "The book does not exist\n";
	}
	return false;
}

bool Patron::returnBook(int bookID) {
	this->library->returnBook(bookID);
	this->booksBorrowed.returnBook(bookID);
	this->numBooksBorrowed--;

	return true;

}