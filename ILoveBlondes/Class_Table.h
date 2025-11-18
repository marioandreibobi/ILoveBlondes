#pragma once
#include"Class_Column.h"
#include <iostream>

using namespace std;

class Table {
private:
	string name = "";
	Column* columns = nullptr;
	int noColoumns = 0;
	static int TABLE_COUNT;
	const int MAX_SIZE = 99;
public:
	Table();
	//setters
	void setName();
	void setNoColumns();
	void setColumns();
	//getters
	string getName();
	Column* getColumns();
	int getNoColumns();

	void addColumn();

	~Table();
};

int static Table::TABLE_COUNT = 0;