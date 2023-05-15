#pragma once
#include "RegisteredUser.h"

class Admin : public RegisteredUser
{
public:
	Admin();
	Admin(string, string, string, string, int);
	~Admin();
	void bookInfo(Book*);
	void addBook(Book*);
	void removeBook(Book*);
	void editBook(Book*);
	Admin* createAdmin();
	Collection* searchCollection(string); // use to delete Collection
	void createCollection(Collection*);
	void deleteCollection(Collection*);
	void hideBook(Book*);
	void showBook(Book*);
};