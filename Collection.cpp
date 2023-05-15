#include "Collection.h"

Collection::Collection()
{
	id = 0;
	name = "";
	listBook.clear();
}

Collection::Collection(int id, string name)
{
	this->id = id;
	this->name = name;
}

Collection::~Collection()
{
	if (!listBook.empty()) {
		for (int i = 0; i < listBook.size(); i++) {
			delete listBook[i];
		}
		listBook.clear();
	}
}

void Collection::setName(string name)
{
	this->name = name;
}

string Collection::getName()
{
	return this->name;
}

void Collection::setID(int id)
{
	this->id = id;
}

int Collection::getID()
{
	return this->id;
}

void Collection::addBook(Book* b)
{
	listBook.push_back(b);
}
