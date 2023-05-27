#pragma once
#include "RegisteredUser.h"

class Admin : public RegisteredUser
{
public:
	Admin();
	Admin(string, string, string, string, int);
	~Admin();
	void bookInfo(vector<Book*> listBook, string);
	//void addBook(vector<Book*> listBook, Book*);
	//void removeBook(vector<Book*> listBook, Book*);
	void editBook( Book*);
	Admin* createAdmin();
	Collection* searchCollection(vector<Collection*> listCollection,string); // use to delete Collection
	void addBookToCollection(Collection*, Book*);
	void createCollection(vector<Collection*> listCollection, Collection*);
	void deleteCollection(vector<Collection*> listCollection, Collection*);
	void hideBook(vector<Book*> listBook, Book*);
	void showBook(vector<Book*> listBook, Book*);
};