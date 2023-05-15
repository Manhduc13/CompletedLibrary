#include "User.h"

User::User()
{
	id = 0;
	listBook.clear();
	listCollection.clear();
}

User::User(int id)
{
	this->id = id;
}

User::~User()
{
	if (!listBook.empty()) {
		for (int i = 0; i < listBook.size(); i++) {
			delete listBook[i];
		}
		listBook.clear();
	}
	if (!listCollection.empty()) {
		for (int i = 0; i < listCollection.size(); i++) {
			delete listCollection[i];
		}
		listCollection.clear();
	}
}

void User::read()
{
	for (int i = 0; i < listBook.size(); i++) {
		if (listBook[i]) {
			cout << "Title: " << listBook[i]->getTitle() << " === " << "Number of free pages: " << listBook[i]->getFreePageCount() << endl;
		}
	}
}

Book* User::searchByTitle(string title)
{
	Book* temp=nullptr;
	for (int i = 0; i < listBook.size(); i++) {
		if (title == listBook[i]->getTitle()) {
			temp = listBook[i];
		}
	}
	return temp;
}

Book* User::searchBySerial(string serial)
{
	Book* temp = nullptr;
	for (int i = 0; i < listBook.size(); i++) {
		if (serial == listBook[i]->getSerial()) {
			temp = listBook[i];
		}
	}
	return temp;
}
