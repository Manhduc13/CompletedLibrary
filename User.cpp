#include "User.h"

User::User()
{
	id = 0;
	//listBook.clear();
	//listCollection.clear();
}

User::User(int id)
{
	this->id = id;
}

User::~User()
{
	/*if (!listBook.empty()) {
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
	}*/
}

void User::read(vector<Book*> listBook, string title)
{
	if (searchByTitle(listBook, title) != nullptr && searchByTitle(listBook, title)->getAvailabilityStatus() == true) {
		cout << "Title: " << searchByTitle(listBook, title)->getTitle() << endl;
		cout << "Serial: " << searchByTitle(listBook, title)->getSerial() << endl;
		cout << "Author name: " << searchByTitle(listBook, title)->getAuthorName() << endl;
		cout << "Number of pages: " << searchByTitle(listBook, title)->getPageCount() << endl;
		cout << "Number of free pages: " << searchByTitle(listBook, title)->getFreePageCount() << endl;
	}
	else {
		cout << "Sorry! We don't have that book" << endl;
	}
}

Book* User::searchByTitle(vector<Book*> listBook, string title)
{
	Book* temp=nullptr;
	for (int i = 0; i < listBook.size(); i++) {
		if (title == listBook[i]->getTitle()) {
			temp = listBook[i];
		}
	}
	return temp;
}

Book* User::searchBySerial(vector<Book*> listBook, string serial)
{
	Book* temp = nullptr;
	for (int i = 0; i < listBook.size(); i++) {
		if (serial == listBook[i]->getSerial()) {
			temp = listBook[i];
		}
	}
	return temp;
}
