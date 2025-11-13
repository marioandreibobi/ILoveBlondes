#include <iostream>
#include <string>
#include "CommandIdentifier.h"
using namespace std;

string UpperCaseTransf(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ('a' - 'A');
		}
	}
	return str;
}

CommandType IdentifyCommand(string input) {

    input = UpperCaseTransf(input);

    if (input.substr(0, 12) == "CREATE TABLE") return CREATE_TABLE;
    else if (input.substr(0, 10) == "DROP TABLE") return DROP_TABLE;
    else if (input.substr(0, 13) == "DISPLAY TABLE") return DISPLAY_TABLE;
    else if (input.substr(0, 12) == "CREATE INDEX") return CREATE_INDEX;
    else if (input.substr(0, 10) == "DROP INDEX") return DROP_INDEX;
    else if (input.substr(0, 6) == "INSERT") return INSERT;
    else if (input.substr(0, 6) == "DELETE") return DELETE;
    else if (input.substr(0, 6) == "SELECT") return SELECT;
    else if (input.substr(0, 6) == "UPDATE") return UPDATE;
    else if (input.substr(0, 4) == "EXIT") return EXIT;

    return UNKNOWN;
}