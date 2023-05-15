#pragma once
#include <iostream>
using namespace std;
class Book
{
private:
	string title;
	string serial;
	string authorName;
	int pageCount;
	int freePageCount;
	bool availabilityStatus = true;
public:
	Book();
	Book(string t, string s, string aN, int pC, int fC, bool aS = true);
	void setTitle(string t);
	string getTitle();
	void setSerial(string s);
	string getSerial();
	void setAuthorName(string aN);
	string getAuthorName();
	void setPageCount(int pC);
	int getPageCount();
	void setFreePageCount(int fC);
	int getFreePageCount();
	void setAvailabilityStatus(bool aS);
	bool getAvailabilityStatus();
};
