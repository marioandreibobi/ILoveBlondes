#pragma once
#include <iostream>
#include <string>
#include "CommandIdentifier.h"
using namespace std;

string Trim(string s);

bool validateCreateTable(string input, CommandType type);
bool validateDropTable(string input, CommandType type);
bool validateExit(string input, CommandType type);
bool validateInsert(string input, CommandType type);
bool validateSelect(string input, CommandType type);
bool validateUpdate(string input, CommandType type);
bool validateDisplayTable(string input, CommandType type);
bool validateCreateIndex(string input, CommandType type);
bool validateDropIndex(string input, CommandType type);
bool validateDelete(string input, CommandType type);
