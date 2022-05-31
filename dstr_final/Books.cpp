#include "Books.h"

bool Books::create() {
	this->bookID = this->createID();
	cout << "Enter Book Name: ";
	getline(cin, name);
	cout << '\n' << "Enter Book Category: ";
	getline(cin, category);
	cout << '\n' << "Enter Book Genre: ";
	getline(cin, genre);
	cout << '\n';
	this->availability = true;
	cout << *this;

	return true;
}

ostream& operator<<(ostream& os, const Books& book)
{
	string avail = "Not Available";
	if (book.availability == 1) {
		avail = "Available";
	}

	os << "Book ID: " << book.bookID << '\n'
		<< "Book Name: " << book.name << '\n'
		<< "Category: " << book.category << '\n'
		<< "Genre: " << book.genre << '\n'
		<< "Availability: " << avail << endl;
	return os;
}

bool Books::isAvailable() {
	return this->availability;
}

int Books::getID() {
	return this->bookID;
}

string Books::getName() {
	return this->name;
}

string Books::getCategory() {
	return this->category;
}

string Books::getGenre() {
	return this->genre;
}

void Books::setName(string name) {
	this->name = name;
}

void Books::setCategory(string category) {
	this->category = category;
}

void Books::setGenre(string genre) {
	this->genre = genre;
}

void Books::setAvailability(bool availability) {
	this->availability = availability;
}

void Books::setReturnDate(string returnDate) {
	this->returnDate = returnDate;
}

int Books::createID() {
	return Books::id++;
}