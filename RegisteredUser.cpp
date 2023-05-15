#include "RegisteredUser.h"

RegisteredUser::RegisteredUser() : User()
{
	userName = "";
	fullName = "";
	password = "";
	phoneNumber = "";
}

RegisteredUser::RegisteredUser(string uN, string fN, string pW, string pN, int id) : User(id)
{
	userName = uN;
	fullName = fN;
	password = pW;
	phoneNumber = pN;
}

void RegisteredUser::setUserName(string uN)
{
	userName = uN;
}

string RegisteredUser::getUserName()
{
	return userName;
}

void RegisteredUser::setFullName(string fN)
{
	fullName = fN;
}

string RegisteredUser::getFullName()
{
	return fullName;
}

void RegisteredUser::setPass(string pW)
{
	password = pW;
}

string RegisteredUser::getPass()
{
	return password;
}

void RegisteredUser::setPhone(string pN)
{
	phoneNumber = pN;
}

string RegisteredUser::getPhone()
{
	return phoneNumber;
}
