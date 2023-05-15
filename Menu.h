#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Menu
{
private:
	string name;
	string description;
	vector<Menu*> subMenu;
	int action;
public:
	Menu();
	Menu(string name, string desc, int action = -1);
	~Menu();
	string getName();
	void setName(string n);
	string getDescription();
	void setDescription(string d);
	int getAction();
	void setAction(int a);
	void addSubMenu(Menu* m);
	Menu* getSubMenu(int index);
	void displayMenu();
	int promptOption();
};
