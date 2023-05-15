#pragma once
#include "User.h"
#include <iostream>
#include <string>
using namespace std;
class RegisteredUser : public User
{
private:
	string userName;
	string fullName;
	string password;
	string phoneNumber;
public:
	RegisteredUser();
	RegisteredUser(string, string, string, string, int);
	void setUserName(string);
	string getUserName();
	void setFullName(string);
	string getFullName();
	void setPass(string);
	string getPass();
	void setPhone(string);
	string getPhone();

};
