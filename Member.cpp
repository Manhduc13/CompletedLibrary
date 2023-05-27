#include "Member.h"

Member::Member() : RegisteredUser()
{
	startYear = 0;
	endYear = 0;
	borrowList.clear();
	subscribeList.clear();
}

Member::Member(string uN, string fN, string pW, string pN, int id) : RegisteredUser(uN,fN,pW,pN,id)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	startYear = 1900 + ltm.tm_year;
	endYear = startYear + 2;
}

Member::~Member()
{
	if (!borrowList.empty()) {
		for (int i = 0; i < borrowList.size(); i++) {
			delete borrowList[i];
		}
		borrowList.clear();
	}
	if (!subscribeList.empty()) {
		for (int i = 0; i < subscribeList.size(); i++) {
			delete subscribeList[i];
		}
		subscribeList.clear();
	}
}

void Member::setStartYear(int sY)
{
	startYear = sY;
}

int Member::getStartYear()
{
	return startYear;
}

void Member::setEndYear(int eY)
{
	endYear = eY;
}

int Member::getEndYear()
{
	return endYear;
}

void Member::borrowBook(Book* b)
{
	borrowList.push_back(b);
}

Book* Member::searchBorrowedBook(string title)
{
	Book* temp = nullptr;
	for (int i = 0; i < borrowList.size(); i++) {
		if (title == borrowList[i]->getTitle()) {
			temp = borrowList[i];
			break;
		}
	}
	return temp;
}

void Member::returnBook(Book* b)
{
	for (int i = 0; i < borrowList.size(); i++) {
		if (b == borrowList[i]) {
			borrowList.erase(borrowList.begin() + i);
			break;
		}
	}
	cout << "You have returned that book." << endl;
}

void Member::displayBorrowList()
{
	for (int i = 0; i < borrowList.size(); i++) {
		cout << i + 1 << ". " << borrowList[i]->getTitle() << endl;
	}
}

Collection* Member::searchCollection(vector<Collection*> listCollection, string name)
{
	Collection* temp = nullptr;
	for (int i = 0; i < listCollection.size(); i++) {
		if (name == listCollection[i]->getName()) {
			temp = listCollection[i];
		}
	}
	return temp;
}

Collection* Member::searchSubCollection(string name)
{
	Collection* temp = nullptr;
	for (int i = 0; i < subscribeList.size(); i++) {
		if (name == subscribeList[i]->getName()) {
			temp = subscribeList[i];
		}
	}
	return temp;
}

void Member::subscribeCollection(Collection* c)
{
	subscribeList.push_back(c);
}

void Member::unSubscribeCollection(Collection* c)
{
	for (int i = 0; i < subscribeList.size(); i++) {
		if (c == subscribeList[i]) {
			subscribeList.erase(subscribeList.begin() + i);
			break;
		}
	}
	cout << "That collection has been removed from your subscribed collection list." << endl;
}

void Member::displaySubscribeList()
{
	for (int i = 0; i < subscribeList.size(); i++) {
		cout << i + 1 << ". " << subscribeList[i]->getName() << endl;
	}
}
