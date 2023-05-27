#include <iostream>
#include <string>
#include <vector>
//#include "Library.h"
#include "User.h"
#include "Guest.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "Member.h"
#include "Book.h"
#include "Collection.h"
#include "Menu.h"
using namespace std;
enum ACTION {
	READ, TITLE, SERIAL, REGIST, EXIT,
	ADMIN_LOGIN, MEMBER_LOGIN,
	BORROW, RETURN, SUB, UNSUB, CLIST, BLIST,
	ADD_L, REMOVE, SHOW, HIDE, EDIT, NEW_ADMIN, NEW_COLLECTION, DEL_COLLECTION, ADD_C
};

bool checkAdmin(string username, string password, vector<Admin*> adList, int& index);
bool checkMember(string username, string password, vector<Member*> memList, int& index);

int main() {
	// Main menu
	Menu* mainMenu = new Menu("Library Menu","");
	Menu* read = new Menu("Read books","", READ);
	Menu* searchTitle = new Menu("Search book by title","", TITLE);
	Menu* searchSerial = new Menu("Search book by serial","", SERIAL);
	Menu* loginMenu = new Menu("Login Menu","");
	Menu* regist = new Menu("Register","", REGIST);
	Menu* exit = new Menu("Exit", "See you next time", EXIT);

	mainMenu->addSubMenu(read);
	mainMenu->addSubMenu(searchTitle);
	mainMenu->addSubMenu(searchSerial);
	mainMenu->addSubMenu(loginMenu);
	mainMenu->addSubMenu(regist);
	mainMenu->addSubMenu(exit);
	// Login menu
	Menu* adminLogin = new Menu("Admin Login", "", ADMIN_LOGIN);
	Menu* memberLogin = new Menu("Member Login", "", MEMBER_LOGIN);

	loginMenu->addSubMenu(adminLogin);
	loginMenu->addSubMenu(memberLogin);
	loginMenu->addSubMenu(mainMenu);
	// Member menu
	Menu* memberMenu = new Menu("Member Section", "");
	Menu* borrowBook = new Menu("Borrow Section", "", BORROW);
	Menu* returnBook = new Menu("Return Book", "", RETURN);
	Menu* subCollection = new Menu("Subcribe Collection", "", SUB);
	Menu* unSubCollection = new Menu("Unsubscribe Collection", "", UNSUB);
	Menu* CollectionList = new Menu("Subscribed collection list", "", CLIST);
	Menu* BorrowList = new Menu("Borrowed List", "", BLIST);

	memberMenu->addSubMenu(borrowBook);
	memberMenu->addSubMenu(returnBook);
	memberMenu->addSubMenu(subCollection);
	memberMenu->addSubMenu(unSubCollection);
	memberMenu->addSubMenu(CollectionList);
	memberMenu->addSubMenu(BorrowList);
	memberMenu->addSubMenu(mainMenu);
	// Admin menu
	Menu* adminMenu = new Menu("Admin Section", "");
	Menu* addBook = new Menu("Add new book to library", "", ADD_L);
	Menu* removeBook = new Menu("Remove book", "", REMOVE);
	Menu* showBook = new Menu("Show book", "", SHOW);
	Menu* hideBook = new Menu("Hide book", "", HIDE);
	Menu* editBook = new Menu("Edit book", "", EDIT);
	Menu* editCollection = new Menu("Edit Collection list", "");
	Menu* createAdmin = new Menu("Admin Register", "", NEW_ADMIN);
	Menu* createCollection = new Menu("New Collection", "", NEW_COLLECTION);
	Menu* deleteCollection = new Menu("Delete Collection", "", DEL_COLLECTION);
	Menu* addBookToCollection = new Menu("Add book to collection", "", ADD_C);
	  
	adminMenu->addSubMenu(addBook);
	adminMenu->addSubMenu(removeBook);
	adminMenu->addSubMenu(showBook);
	adminMenu->addSubMenu(hideBook);
	adminMenu->addSubMenu(editBook);
	adminMenu->addSubMenu(editCollection);
	adminMenu->addSubMenu(createAdmin);
	adminMenu->addSubMenu(mainMenu);

	editCollection->addSubMenu(createCollection);
	editCollection->addSubMenu(deleteCollection);
	editCollection->addSubMenu(addBookToCollection);
	editCollection->addSubMenu(adminMenu);

	Guest* guest = new Guest();
	User* user01 = new Admin();
	string username;
	string password;
	int index=0;

	vector<Admin*> adminList;
	Admin* admin01 = new Admin("manhduc", "Nguyen Duc Manh", "130702", "0327859829", 1613578);
	adminList.push_back(admin01);
	Admin* currentAdmin = admin01;

	vector<Member*> memberList;
	Member* member01 = new Member("manhnguyen", "Nguyen Duc Manh", "123456", "0327859829", 20207962);
	Member* member02 = new Member("manh", "manh", "1234", "1234", 1234);
	memberList.push_back(member01);
	memberList.push_back(member02);
	Member* currentMember = member01;

	vector<Collection*> listCollection;
	Collection* c = new Collection();
	Collection* collection01 = new Collection(123456, "good");
	Collection* collection02 = new Collection(234567, "bad");
	listCollection.push_back(collection01);
	listCollection.push_back(collection02);

	string name;
	int cID;

	vector<Book*> listBook;
	Book* b = new Book();
	Book* book01 = new Book("math", "123456", "manh", 120, 30);
	Book* book02 = new Book("physic", "234567", "manh", 110, 20);
	Book* book03 = new Book("chemistry", "345678", "manh", 100, 10);
	listBook.push_back(book01);
	listBook.push_back(book02);
	listBook.push_back(book03);

	collection01->addBook(book01);
	collection01->addBook(book02);
	string title;
	string serial;
	string author;
	int pC, fC;
	
	Menu* currentMenu = mainMenu;
	while (true) {
		currentMenu->displayMenu();
		int opt = currentMenu->promptOption();
		currentMenu = currentMenu->getSubMenu(opt);
		switch (currentMenu->getAction()) {
		case -1:
			break;
		case EXIT:
			break;
		case READ:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter title of the book you want to read: "; getline(cin, title);
			guest->read(listBook, title);
			currentMenu = mainMenu;
			break;
		case TITLE:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter the book's title to search: "; getline(cin, title);
			if (admin01->searchByTitle(listBook, title) != nullptr && admin01->searchByTitle(listBook, title)->getAvailabilityStatus() == true) {
				cout << "This book exists in our library" << endl;
				cout << "Title: " << admin01->searchByTitle(listBook, title)->getTitle() << endl;
				cout << "Serial: " << admin01->searchByTitle(listBook, title)->getSerial() << endl;
				cout << "Author name: " << admin01->searchByTitle(listBook, title)->getAuthorName() << endl;
				cout << "Number of pages: " << admin01->searchByTitle(listBook, title)->getPageCount() << endl;
			}
			else {
				cout << "Sorry! We don't have that book" << endl;
			}
			currentMenu = mainMenu;
			break;
		case SERIAL:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter the book'serial: "; getline(cin, serial);
			if (admin01->searchBySerial(listBook, serial) != nullptr && admin01->searchBySerial(listBook, serial)->getAvailabilityStatus() == true) {
				cout << "This book exists in our library" << endl;
				cout << "Title: " << admin01->searchBySerial(listBook, serial)->getTitle() << endl;
				cout << "Serial: " << admin01->searchBySerial(listBook, serial)->getSerial() << endl;
				cout << "Author name: " << admin01->searchBySerial(listBook, serial)->getAuthorName() << endl;
				cout << "Number of pages: " << admin01->searchBySerial(listBook, serial)->getPageCount() << endl;
			}
			else {
				cout << "Sorry! We don't have that book" << endl;
			}
			currentMenu = mainMenu;
			break;
		case REGIST:
			currentMenu->displayMenu();
			memberList.push_back(guest->regist());
			cout << "Register successfully." << endl;
			currentMenu = memberMenu;		
			break;
		case ADMIN_LOGIN:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Username: "; getline(cin, username);
			cout << "Password: "; getline(cin, password);
			if (checkAdmin(username, password, adminList, index)) {
				cout << "Welcome " << adminList[index]->getFullName() << endl;
				currentAdmin = adminList[index];
				currentMenu = adminMenu;
			}
			else {
				cout << "Login failed." << endl;
				currentMenu = loginMenu;
			}
			break;
		case MEMBER_LOGIN:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Username: "; getline(cin, username);
			cout << "Password: "; getline(cin, password);
			if (checkMember(username, password, memberList, index)) {
				cout << "Welcome " << memberList[index]->getFullName() << endl;
				currentMember = memberList[index];
				currentMenu = memberMenu;
			}
			else {
				cout << "Login failed." << endl;
				currentMenu = loginMenu;
			}
			break;
		case ADD_L:
			currentMenu->displayMenu();
			cout << "Enter new book information:\n";
			cin.ignore();
			cout << "Title: "; getline(cin, title);
			cout << "Author name: "; getline(cin, author);
			cout << "Serial number (6 digits): "; getline(cin, serial);
			cout << "Number of pages: "; cin >> pC;
			cout << "Number of free pages: "; cin >> fC;
			b->setTitle(title);
			b->setSerial(serial);
			b->setAuthorName(author);
			b->setPageCount(pC);
			b->setFreePageCount(fC);
			//currentAdmin->addBook(listBook,b);
			listBook.push_back(b);
			cout << "Add book successfully." << endl;
			currentMenu = adminMenu;
			break;
		case REMOVE:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter the book's title you want to remove: "; getline(cin, title);
			//currentAdmin->removeBook(listBook, currentAdmin->searchByTitle(listBook, title));
			for (int i = 0; i < listBook.size(); i++) {
				if (title == listBook[i]->getTitle()) {
					listBook.erase(listBook.begin() + i);
					break;
				}
			}
			cout << "That book has been removed" << endl;
			currentMenu = adminMenu;
			break;
		case EDIT:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter the book's title you want to edit: "; getline(cin, title);
			if (currentAdmin->searchByTitle(listBook, title) != nullptr) {
				currentAdmin->editBook(currentAdmin->searchByTitle(listBook, title));
			}
			else {
				cout << "Sorry! We don't have that book" << endl;
			}
			
			currentMenu = adminMenu;
			break;
		case NEW_ADMIN:
			currentMenu->displayMenu();
			adminList.push_back(currentAdmin->createAdmin());
			cout << "Register successfully." << endl;
			currentMenu = adminMenu;
			break;
		case ADD_C:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter name of collection you want to add book: "; getline(cin, name);
			if (currentAdmin->searchCollection(listCollection, name) != nullptr) {
				cout << "Enter name of book you want to add to that collection: "; getline(cin, title);
				if (currentAdmin->searchByTitle(listBook, title) != nullptr) {
					currentAdmin->addBookToCollection(currentAdmin->searchCollection(listCollection, name), currentAdmin->searchByTitle(listBook, title));
					cout << "Add book successfully." << endl;
				}
				else {
					cout << "That book doesn't exist!\n";
				}
			}
			else {
				cout << "The collection doesn't exist!\n";
			}
			currentMenu = adminMenu;
			break;
		case NEW_COLLECTION:
			currentMenu->displayMenu();
			cout << "Enter new book information:\n";
			cin.ignore();
			cout << "Collection name: "; getline(cin, name);
			cout << "Collection ID (6 digits): "; cin >> cID;
			c->setName(name);
			c->setID(cID);
			currentAdmin->createCollection(listCollection, c);
			cout << "Create collection successfully." << endl;
			currentMenu = adminMenu;
			break;
		case DEL_COLLECTION:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter name of collection you  want to delete: "; getline(cin, name);
			currentAdmin->deleteCollection(listCollection,currentAdmin->searchCollection(listCollection,name));
			currentMenu = adminMenu;
			break;
		case HIDE:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter book's title you want to hide: "; getline(cin, title);
			currentAdmin->hideBook(listBook, currentAdmin->searchByTitle(listBook, title));
			currentMenu = adminMenu;
			break;
		case SHOW:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter book's title you want to show publicly: "; getline(cin, title);
			currentAdmin->showBook(listBook, admin01->searchByTitle(listBook, title));
			currentMenu = adminMenu;
			break;
		case BORROW:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter book's title you want to borrow: "; getline(cin, title);
			if (currentMember->searchByTitle(listBook, title)) {
				currentMember->borrowBook(currentMember->searchByTitle(listBook, title));
				cout << "Borrow book successfully." << endl;
			}
			else {
				cout << "We don't have that book" << endl;
			}
			currentMenu = memberMenu;
			break;
		case RETURN:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter book's title you want to borrow: "; getline(cin, title);
			currentMember->returnBook(currentMember->searchBorrowedBook(title));
			currentMenu = memberMenu;
			break;
		case BLIST:
			currentMenu->displayMenu();
			currentMember->displayBorrowList();
			currentMenu = memberMenu;
			break;
		case SUB:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter name of collection you  want to subscribe: "; getline(cin, name);
			currentMember->subscribeCollection(currentMember->searchCollection(listCollection,name));
			cout << "That collection has been add to your subscribed list." << endl;
			currentMenu = memberMenu;
			break;
		case UNSUB:
			currentMenu->displayMenu();
			cin.ignore();
			cout << "Enter name of collection you  want to unsubscribe: "; getline(cin, name);
			currentMember->unSubscribeCollection(currentMember->searchSubCollection(name));
			currentMenu = memberMenu;
			break;
		case CLIST:
			currentMenu->displayMenu();
			currentMember->displaySubscribeList();
			currentMenu = memberMenu;
			break;
		default:
			cout << "Default action." << endl;
			break;
		}
	}

	for (int i = 0; i < adminList.size(); i++) {
		delete adminList[i];
	}
	adminList.clear();
	delete currentAdmin;

	for (int i = 0; i < memberList.size(); i++) {
		delete memberList[i];
	}
	memberList.clear();
	delete currentMember;

	for (int i = 0; i < listCollection.size(); i++) {
		delete listCollection[i];
	}
	listCollection.clear();

	for (int i = 0; i < listBook.size(); i++) {
		delete listBook[i];
	}
	listBook.clear();
	return 0;
}
bool checkAdmin(string username, string password, vector<Admin*> adList, int& index) {
	for (int i = 0; i < adList.size(); i++) {
		if (username == adList[i]->getUserName() && password == adList[i]->getPass()) {
			index = i;
			return true;
		}
	}
	return false;
}

bool checkMember(string username, string password, vector<Member*> memList, int& index)
{
	for (int i = 0; i < memList.size(); i++) {
		if (username == memList[i]->getUserName() && password == memList[i]->getPass()) {
			index = i;
			return true;
		}
	}
	return false;
}
