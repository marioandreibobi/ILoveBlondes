#include <iostream>
#include <string>
#include "ValidationFunctions.h"
using namespace std;

string Trim(string s) {

	while (!s.empty() && s.front() == ' ') s.erase(s.begin());
	while (!s.empty() && s.back() == ' ')s.pop_back();
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



	return true;
}