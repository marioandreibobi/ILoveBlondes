#include <iostream>
#include "Class_Table.h"
using namespace std;

Table::Table() {
	name = "";
	columns = nullptr;
	noColumns = 0;
}

void Table::setColumns(string* col, int noCol) {
	// free existing buffer
	if (columns != nullptr || noColumns >0) {
		delete[] columns;
		columns = nullptr;
		noColumns = 0;
	}

	// allocate and copy if input provided
	if (col != nullptr && noCol > 0) {
		columns = new Column[noCol];
		for (int i = 0; i < noCol; i++) {
			columns[i].setName(col[i]);
		}
		noColumns = noCol;
	} else {
		// ensure consistent state
		columns = nullptr;
		noColumns = 0;
	}
}
void Table::setName(string name) {
	if (this->name != "") {
		this->name = "";
	}
	else {
		this->name = name;
	}
}
void Table::setNoColumns(int noColumns) {
	if (this->noColumns != 0) {
		this->noColumns = 0;
	}
	else {
		this->noColumns = noColumns;
	}
}