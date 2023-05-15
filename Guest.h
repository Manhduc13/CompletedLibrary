#pragma once
#include "User.h"
#include "Member.h"
#include <iostream>
#include <ctime>
using namespace std;
class Guest : public User
{
private:
	int tempId;
public:
	Guest();
	~Guest();
	Member* regist();
};

