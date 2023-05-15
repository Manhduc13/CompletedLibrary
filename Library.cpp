#include "Library.h"

Library::Library()
{
	listBook.clear();
	listCollection.clear();
}

Library::~Library()
{
	if (!listBook.empty()) {
		for (int i = 0; i < listBook.size(); i++) {
			delete listBook[i];
		}
		listBook.clear();
	}
	if (!listCollection.empty()) {
		for (int i = 0; i < listCollection.size(); i++) {
			delete listCollection[i];
		}
		listCollection.clear();
	}
}
