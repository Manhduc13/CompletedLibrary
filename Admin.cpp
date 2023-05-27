#include "Admin.h"

Admin::Admin() : RegisteredUser()
{
}

Admin::Admin(string uN, string fN, string pW, string pN, int id) : RegisteredUser(uN,fN,pW,pN,id)
{
}

Admin::~Admin()
{
}

void Admin::bookInfo(vector<Book*> listBook, string title)
{
	for (int i = 0; i < listBook.size(); i++) {
		if (title == listBook[i]->getTitle()) {
			cout << listBook[i]->getSerial() << endl;
		}
	}
}

/*void Admin::addBook(vector<Book*> listBook, Book* b)
{
	listBook.push_back(b);
}*/

/*void Admin::removeBook(vector<Book*> listBook, Book* b)
{
	for (int i = 0; i < listBook.size(); i++) {
		if (b == listBook[i]) {
			listBook.erase(listBook.begin() + i);
			break;
		}
	}
	cout << "That book has been removed" << endl;
}*/

void Admin::editBook(Book* b)
{
	int choice;
	string title, serial, author;
	int pC, fC;
	char opt;
	do {
		cout << "Which part you want to edit:" << endl;
		cout << "1. Title\n";
		cout << "2. Serial\n";
		cout << "3. Author name\n";
		cout << "4. Number of pages\n";
		cout << "5. Number of free pages\n";
		cout << "Your choice: "; cin >> choice;
		cin.ignore();
		if (choice == 1) {
			cout << "Enter new title: "; getline(cin, title);
			b->setTitle(title);
		}
		else if (choice == 2) {
			cout << "Enter new serial: "; getline(cin, serial);
			b->setSerial(serial);
		}
		else if (choice == 3) {
			cout << "Enter new author name: "; getline(cin, author);
			b->setAuthorName(author);
		}
		else if (choice == 4) {
			cout << "Enter new number of pages: "; cin >> pC;
			b->setPageCount(pC);
		}
		else if (choice == 5) {
			cout << "Enter new number of free pages: "; cin >> fC;
			b->setFreePageCount(fC);
		}
		cout << "Do you want to change other parts (y for Yes, n for No): "; cin >> opt;
	} while (opt != 'n');
}

Admin* Admin::createAdmin()
{
	string username, fullname, password, phone;
	int id;
	cin.ignore();
	cout << "Your full name: "; getline(cin, fullname);
	cout << "Username: "; getline(cin, username);
	cout << "Password: "; getline(cin, password);
	cout << "Phone number: "; getline(cin, phone);
	cout << "Id: "; cin >> id;
	Admin* newAdmin = new Admin(username, fullname, password, phone, id);
	return newAdmin;
}

Collection* Admin::searchCollection(vector<Collection*> listCollection, string name)
{
	Collection* temp = nullptr;
	for (int i = 0; i < listCollection.size(); i++) {
		if (name == listCollection[i]->getName()) {
			temp = listCollection[i];
		}
	}
	return temp;
}

void Admin::addBookToCollection(Collection* collection, Book* addedBook)
{
	collection->addBook(addedBook);
}

void Admin::createCollection(vector<Collection*> listCollection, Collection* c)
{
	listCollection.push_back(c);
}

void Admin::deleteCollection(vector<Collection*> listCollection, Collection* c)
{
	for (int i = 0; i < listCollection.size(); i++) {
		if (c == listCollection[i]) {
			listCollection.erase(listCollection.begin() + i);
			break;
		}
	}
	cout << "That collection has been removed." << endl;
}

void Admin::hideBook(vector<Book*> listBook, Book* b)
{
	for (int i = 0; i < listBook.size(); i++) {
		if (b == listBook[i]) {
			listBook[i]->setAvailabilityStatus(false);
			break;
		}
	}
	cout << "That book has been hiden." << endl;
}

void Admin::showBook(vector<Book*> listBook, Book* b)
{
	for (int i = 0; i < listBook.size(); i++) {
		if (b == listBook[i]) {
			listBook[i]->setAvailabilityStatus(true);
			break;
		}
	}
	cout << "That book has been shown publicly." << endl;
}
