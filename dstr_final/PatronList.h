#pragma once
#include <iostream>
#include "List.h"
#include "Books.h"

using namespace std;

template <typename T>
class PatronList : public List<T> {
	using node_pointer = Node<T>*;
public:
	void search(string searchTerm);
	void search(int searchTerm);
	bool verifyID(int ID);
	void booksBorrowed();
	void displayLastTen(int patronID);
	bool update(int patronID, string newData, int updateType);
	Patron* getInfo(int patronID);
	bool changeReturnDate(int patronID);
	void printPatron(int patronID);
};

template <typename T>
void PatronList<T>::search(string searchTerm) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		if (searchTerm == current->data.getName()) {
			cout << current->data;
			notFound = false;
		}
		current = current->next;
	}
	if (notFound) {
		cout << "Patron was not found\n";
	}
}

template <typename T>
void PatronList<T>::search(int searchTerm) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		if (searchTerm == current->data.getID()) {
			cout << current->data;
			notFound = false;
		}
		current = current->next;
	}
	if (notFound) {
		cout << "Patron was not found\n";
	}
}

template <typename T>
bool PatronList<T>::verifyID(int ID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (ID == current->data.getID()) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
void PatronList<T>::booksBorrowed() {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		if (current->data.getNumBooksBorrowed() > 0) {
			cout << current->data;
			notFound = false;
		}
		current = current->next;
	}
	if (notFound) {
		cout << "No Patrons with Active Books Borrowed.\n";
	}
}

template <typename T>
void PatronList<T>::displayLastTen(int patronID) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		if (patronID == current->data.getID()) {
			notFound = false;
			if (current->data.getNumBooksBorrowed() == 0) {
				cout << "No Books Borrowed.\n";
			}
			else
			{
				current->data.displayBooks();
				break;
			}
			
		} 
		current = current->next;
	}
	if (notFound) {
		cout << "No Patron Found with that ID\n";
	}
}

template <typename T>
bool PatronList<T>::update(int patronID, string newData, int updateType) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		notFound = true;
		if (patronID == current->data.getID()) {
			notFound = false;
			switch (updateType) {
			case 1:
				current->data.setName(newData);
				break;
			case 2:
				current->data.setAddress(newData);
				break;
			case 3:
				current->data.setPhoneNum(newData);
				break;
			}
		}
		current = current->next;
	}
	if (notFound) {
		cout << "Patron was not found\n";
	}

	return true;
}

template <typename T>
Patron* PatronList<T>::getInfo(int PatronID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (PatronID == current->data.getID()) {
			return &current->data;
		}
	}
}

template <typename T>
bool PatronList<T>::changeReturnDate(int patronID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (patronID == current->data.getID()) {
			cout << "Enter the Book ID: ";
			int id;
			cin >> id;
			cin.ignore();
			cout << "Enter new return date: ";
			string date;
			getline(cin, date);
			current->data.booksBorrowed.setReturnDate(date, id);
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
void PatronList<T>::printPatron(int patronID) {
	node_pointer current = new Node<T>;
	current = List<T>::head;

	while (current != nullptr) {
		if (patronID == current->data.getID()) {
			cout << current->data << '\n';
			break;
		}
		current = current->next;
	}
}