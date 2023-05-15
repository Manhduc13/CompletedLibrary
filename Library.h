#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Collection.h"
using namespace std;
class Library
{
protected:
	vector<Book*> listBook;
	vector<Collection*> listCollection;
public:
	Library();
	~Library();
};

