#pragma once
#include <string>
using namespace std;

enum CommandType {
	CREATE_TABLE,
	DROP_TABLE,
	DISPLAY_TABLE,
	CREATE_INDEX,
	DROP_INDEX,
	INSERT,
	DELETE,
	SELECT,
	UPDATE,
	EXIT,
	UNKNOWN
};

string UpperCaseTransf(string str);
CommandType IdentifyCommand(string input);