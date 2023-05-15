#pragma once
#include <iostream>
#include "Book.h"
#include "Collection.h"
using namespace std;
class User
{
protected:
	int id;
	vector<Book*> listBook;
	vector<Collection*> listCollection;
public:
	User();
	User(int);
	~User();
	void read();
	Book* searchByTitle(string);
	Book* searchBySerial(string);
};

