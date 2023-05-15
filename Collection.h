#pragma once
#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;

class Collection
{
private:
	int id;
	string name;
	vector<Book*> listBook;
public:
	Collection();
	Collection(int, string);
	~Collection();
	void setName(string name);
	string getName();
	void setID(int id);
	int getID();
	void addBook(Book* b);
};

