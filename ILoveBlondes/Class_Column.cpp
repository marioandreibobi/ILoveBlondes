#include <iostream>
#include <string>
#include "Class_Column.h"

using namespace std;

Column::Column() {
	name = "";
	type = "";
	size = 0;
	defaultValue = "";
}

Column::Column(string name, string type, int size, string defaultValue) {
	this->name = name;
	this->type = type;
	this->size = size;
	this->defaultValue = defaultValue;
}

void Column::setName(string name) {
	if (name.empty()) throw invalid_argument("Name invalid");
	this->name = name;
}

void Column::setType(string type) {
	if (type != "TEXT" && type != "FLOAT" && type != "INTEGER") throw invalid_argument("Invalid Type");
	this->type = type;
}

void Column::setSize(int size) {
	if (size <= 0) throw invalid_argument("Invalid size");
	this->size = size;
}

void Column::setDefaultValue(string defaultValue) {
	this->defaultValue = defaultValue;
}

string Column::getName() { return name; }
string Column::getType() { return type; }
int Column::getSize() { return size; }
string Column::getDefaultValue() { return defaultValue; }

Column::~Column() { }