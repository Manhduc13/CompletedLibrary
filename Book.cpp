#include "Book.h"

Book::Book()
{
	title = "";
	serial = "";
	authorName = "";
	pageCount = 0;
	freePageCount = 0;
	availabilityStatus = true;
}

Book::Book(string t, string s, string aN, int pC, int fC, bool aS)
{
	title = t;
	serial = s;
	authorName = aN;
	pageCount = pC;
	freePageCount = fC;
	availabilityStatus = aS;
}

void Book::setTitle(string t)
{
	title = t;
}

string Book::getTitle()
{
	return title;
}

void Book::setSerial(string s)
{
	serial = s;
}

string Book::getSerial()
{
	return serial;
}

void Book::setAuthorName(string aN)
{
	authorName = aN;
}

string Book::getAuthorName()
{
	return authorName;
}

void Book::setPageCount(int pC)
{
	pageCount = pC;
}

int Book::getPageCount()
{
	return pageCount;
}

void Book::setFreePageCount(int fC)
{
	freePageCount = fC;
}

int Book::getFreePageCount()
{
	return freePageCount;
}

void Book::setAvailabilityStatus(bool aS)
{
	availabilityStatus = aS;
}

bool Book::getAvailabilityStatus()
{
	return availabilityStatus;
}
