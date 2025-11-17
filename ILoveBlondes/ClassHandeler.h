#pragma once
#include <string>
#include <iostream>
#include "ValidationFunctions.h"
#include "CommandIdentifier.h"


class CommandHandeler{

private:

public:
	CommandHandeler(){}

	void Process(string command) {
		if (validateCreateTable(command, CREATE_TABLE)) {}
		else if (validateDropTable(command, DROP_TABLE)) {}
		else if (validateExit(command, EXIT)) {}
		else if (validateInsert(command, INSERT)) {}
		else if (validateSelect(command, SELECT)) {}
		else if (validateUpdate(command, UPDATE)) {}
		else if (validateDisplayTable(command, DISPLAY_TABLE)) {}
		else if (validateCreateIndex(command, CREATE_INDEX)) {}
		else if (validateDropIndex(command, DROP_INDEX)) {}
		else if (validateDelete(command, DELETE)) {}
	}

	~CommandHandeler();

};

