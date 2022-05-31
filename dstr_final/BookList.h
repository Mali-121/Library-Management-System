#pragma once
#include <iostream>
#include <utility> 
#include "List.h"
#include "Books.h"

using namespace std;

template <typename T>
class BookList : public List<T> {
	using node_pointer = Node<T>*;
public:
	void printAvailable();
	void search(string searchTerm, int searchType);
	pair<bool, Books> borrow(int bookID);
	void returnBook(int bookID);
	bool update(int bookid, string newData, int updateType);
	void displayLastTen();
	Books& borrowBook(int bookID);
	void setReturnDate(string date, int bookID);
	void printBook(int bookID);
};

template <typename T>
void BookList<T>::printAvailable() {
	node_pointer current = List<T>::head;
	bool notFound = true;
	while (current != nullptr) {
		if (current->data.isAvailable()) {
			notFound = false;
			cout << current->data;
		}
		current = current->next;
	}
	if (notFound) {
		cout << "No Available Books\n";
	}
}

template <typename T>
void BookList<T>::search(string searchTerm, int searchType) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		notFound = true;
		switch (searchType) {
		case 1:
			if (searchTerm == current->data.getName()) {
				notFound = false;
			}
			break;
		case 2:
			if (searchTerm == current->data.getCategory()) {
				notFound = false;
			}
			break;
		case 3:
			if (searchTerm == current->data.getGenre()) {
				notFound = false;
			}
			break;
		case 4:
			if (current->data.isAvailable()) {
				notFound = false;
			}
			break;
		}
		if (!notFound) {
			cout << current->data;
		}
		current = current->next;
	}
	if (notFound) {
		cout << "Book was not found\n";
	}
}

template <typename T>
pair<bool, Books> BookList<T>::borrow(int bookID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (bookID == current->data.getID()) {
			current->data.setAvailability(false);
			cout << "Enter Return Date: ";
			string date;
			getline(cin, date);
			current->data.setReturnDate(date);
			return make_pair(true, current->data);
		}
		current = current->next;
	}
	
	Books* book = new Books;

	return make_pair(false, *book);
}

template <typename T>
Books& BookList<T>::borrowBook(int bookID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (bookID == current->data.getID()) {
			return current->data;
		}
		current = current->next;
	}
}

template <typename T>
void BookList<T>::returnBook(int bookID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (bookID == current->data.getID()) {
			current->data.setAvailability(true);
		}
		current = current->next;
	}
}


template <typename T>
bool BookList<T>::update(int bookid, string newData, int updateType) {
	node_pointer current = List<T>::head;
	bool notFound = true;

	while (current != nullptr) {
		notFound = true;
		if (bookid == current->data.getID()) {
			notFound = false;
			switch (updateType) {
			case 1:
				current->data.setName(newData);
				break;
			case 2:
				current->data.setCategory(newData);
				break;
			case 3:
				current->data.setGenre(newData);
				break;
			}
		}
		current = current->next;
	}
	if (notFound) {
		cout << "Book was not found\n";
	}

	return true;
}

template <typename T>
void BookList<T>::displayLastTen() {
	node_pointer current = List<T>::tail;
	int count = 0;

	while (current != nullptr) {
		cout << current->data;
		current = current->prev;
		++count;
		if (count == 10) {
			break;
		}
	}
}

template <typename T>
void BookList<T>::setReturnDate(string date, int bookID) {
	node_pointer current = List<T>::head;

	while (current != nullptr) {
		if (bookID == current->data.getID()) {
			current->data.setReturnDate(date);
		}
	}
}

template <typename T>
void BookList<T>::printBook(int bookID) {
	node_pointer current = new Node<T>;
	current = List<T>::head;

	while (current != nullptr) {
		if (bookID == current->data.getID()) {
			cout << current->data << '\n';
			break;
		}
		current = current->next;
	}
}
