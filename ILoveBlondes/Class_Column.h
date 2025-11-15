#pragma once
#include <string>
#include <iostream>

using namespace std;

class Column {
private:
	string name=" ";
	string type=" ";
	int size=0;
	string defaultValue=" ";
public:
	Column();
	Column(string name, string type, int size, string defaultValue);

	//setters
	
	void setName(string name);
	void setType(string type);
	void setSize(int size);
	void setDefaultValue(string defaultValue);
	
	//getters

	string getName();
	string getType();
	int getSize();
	string getDefaultValue();

	~Column();

};