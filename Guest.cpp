#include "Guest.h"

Guest::Guest()
{
	tempId = rand();
}

Guest::~Guest()
{
}

Member* Guest::regist()
{
	string username, fullname, password, phone;
	int id;
	cin.ignore();
	cout << "Your full name: "; getline(cin, fullname);
	cout << "Username: "; getline(cin, username);
	cout << "Password: "; getline(cin, password);
	cout << "Phone number: "; getline(cin, phone);
	cout << "Id: "; cin >> id;
	Member* newMember = new Member(username, fullname, password,phone, id);
	return newMember;
}

