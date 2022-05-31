#pragma once
#include <string>
#include <iostream>
#include "Books.h"
#include "BookList.h"

using namespace std;

class Patron
{
public:
	int PatronID;
	string name;
	string address;
	string phoneNum;
	BookList<Books>* library;
	BookList<Books> booksBorrowed;
	int numBooksBorrowed;
public:
	static int id;

public:
	bool registerPatron();
	friend ostream& operator<<(ostream& os, const Patron& patron);
	string getName();
	int getID();
	int getNumBooksBorrowed();
	void setName(string name);
	void setAddress(string address);
	void setPhoneNum(string number);
	void displayBooks();
	bool borrow(int bookID);
	bool returnBook(int bookID);
private:
	int createID();
};
