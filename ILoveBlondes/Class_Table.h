#pragma once
#include"Class_Column.h"
#include <iostream>

using namespace std;

class Table {
private:
	string name = "";
	Column* columns = nullptr;
	int noColumns = 0;
	static int TABLE_COUNT;
	const int MAX_SIZE = 99;
public:
	Table();
	//setters
	void setName(string Name);
	void setNoColumns(int nocol);
	void setColumns(string* col, int nocol);
	//getters
	string getName();
	Column* getColumns();
	int getNoColumns();

	void addColumn();

	~Table();
};