#pragma once
#include <string>
#include <iostream>

using namespace std;

class Books
{
	int bookID;
	string name;
	string category;
	string genre;
	bool availability;
	string returnDate;

public:
	static int id;

public:
	bool create();
	bool isAvailable();
	int getID();
	string getName();
	string getCategory();
	string getGenre();
	void setName(string name);
	void setCategory(string category);
	void setGenre(string genre);
	void setAvailability(bool availability);
	void setReturnDate(string returnDate);
	friend ostream& operator<<(ostream& os, const Books& book);
private:
	int createID();
};


