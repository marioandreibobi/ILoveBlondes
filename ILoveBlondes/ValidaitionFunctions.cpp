#include <iostream>
#include <string>
#include "Class_Column.h"
#include "ValidationFunctions.h"
using namespace std;

string Trim(string s) {
	while (!s.empty() && isspace(s.front()))
		s.erase(s.begin());

	while (!s.empty() && isspace(s.back()))
		s.pop_back();

	return s;
}


bool validateCreateTable(string input, CommandType type) {
	string cmd = UpperCaseTransf(input); //for case insensitive
	//check where the string is
	int start = 0;
	while (start < cmd.length() && 
		(cmd[start] == ' ' || cmd[start] == '\t' || cmd[start] == '\n')) {
		start++;
	}
	//if empty delete
	if (start == cmd.length())return false;


	cmd = cmd.substr(start);
	//check if it is CREATE TABLE
	if (cmd.rfind("CREATE TABLE", 0) != 0) {
		return false;
	}

	int pos = 13; //Start of the table name
	int parenthesisPos = cmd.find('(', pos);//end of the name
	string tableName = Trim(cmd.substr(pos, parenthesisPos - pos));//get the name

	if (tableName.empty())return false;
	if (!isalpha(tableName[0])) return false;

	for (int i = 0; i < tableName.length(); i++) {
		char c = tableName[i];
		if (!isalnum(c) && c != '_') return false;
	}

	int parenthesisStart = cmd.find('(', pos);
	int parenthesisEnd = cmd.rfind(')');
	if (parenthesisStart == string::npos || parenthesisEnd == string::npos || parenthesisEnd <= parenthesisStart)
		return false;

	string columnsStr = cmd.substr(parenthesisStart + 1, parenthesisEnd - parenthesisStart - 1);

	const int MAX_COLUMNS = 100;
	string columns[MAX_COLUMNS];
	int numColumns = 0;

	int nivel = 0;
	int colStart = -1;

	for (int i = 0; i < columnsStr.length(); i++) {
		char c = columnsStr[i];

		if (c == '(') {
			nivel++;
			if (nivel == 1) colStart = i;
		}
		else if (c == ')') {
			if (nivel == 1) {
				string colDef = Trim(columnsStr.substr(colStart + 1, i - colStart - 1));

				int comma1 = colDef.find(',');
				int comma2 = colDef.find(',', comma1+1);
				int comma3 = colDef.find(',', comma2 + 1);

				string name = Trim(colDef.substr(0, comma1));
				string type = Trim(colDef.substr(comma1 + 1, comma2 - comma1 - 1));
				int size = stoi(Trim(colDef.substr(comma2 + 1, comma3 - comma2 - 1)));
				string defVal = Trim(colDef.substr(comma3 + 1));

				try {
					Column tmp;
					tmp.setName(name);
					tmp.setType(type);
					tmp.setSize(size);
					tmp.setDefaultValue(defVal);
				}
				catch (invalid_argument& e) {
					return false; 
				}
				numColumns++;
			}
			nivel--;
		}
	}


	return numColumns > 0;
}

bool validateDropTable(string input, CommandType type) {
	string cmd = UpperCaseTransf(input);
	
	//check where the string is
	int start = 0;
	while (start < cmd.length() &&
		(cmd[start] == ' ' || cmd[start] == '\t' || cmd[start] == '\n')) {
		start++;
	}
	//if empty delete
	if (start == cmd.length())return false;


	cmd = cmd.substr(start);
	//check if it is CREATE TABLE
	if (cmd.rfind("DROP TABLE", 0) != 0) {
		return false;
	}

	int pos = 10; //start of the table name
	string tableName = Trim(cmd.substr(pos));

	if (!tableName.empty()) return false;
	
	if (!isalpha(tableName[0])) return false;


	for (int i = 0; i < tableName.length(); i++) {
		char c = tableName[i];
		if (!isalnum(c) && c != '_') return false;
	}


	return true;
}

bool ValidateExit(string s, CommandType type) {
	string cmd = UpperCaseTransf(s);

	cmd = Trim(cmd);

	//check if it is EXIT
	if (cmd.rfind("EXIT", 0) != 0) {
		return false;
	}

	string rest = cmd.substr(4);

	if (Trim(rest) != "")
		return false;

	return true;
}