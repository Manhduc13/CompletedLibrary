#pragma once
#include "RegisteredUser.h"
#include "Book.h"
#include <vector>
#include <ctime>
class Member : public RegisteredUser
{
private:
	int startYear;
	int endYear;
	vector<Book*> borrowList;
	vector<Collection*> subscribeList;
public:
	Member();
	Member(string, string, string, string, int);
	~Member();
	void setStartYear(int sY);
	int getStartYear();
	void setEndYear(int eY);
	int getEndYear();
	void borrowBook(Book* b);
	Book* searchBorrowedBook(string title);
	void returnBook(Book* b);
	void displayBorrowList();
	Collection* searchCollection(string name); // use to subscribe Collection
	Collection* searchSubCollection(string name);
	void subscribeCollection(Collection* c);
	void unSubscribeCollection(Collection* c);
	void displaySubscribeList();
};

