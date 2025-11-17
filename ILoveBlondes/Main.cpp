/*
#include <iostream>
#include <string.h>

using namespace std;
//THIS IS A SCHEME FOR NOW 

void Separator() {

    cout << "------------------------------------" << endl;
    //sa fie mai pretty saracia am pus si spatiu ca de ce nu.

}


void CreateTable() {


}


void DropTable() {


}


void DisplayTable() {


}


void CreateIndex() {


}


void DropIndex() {


}

void InsertData() {


}



void SelectData() {


}


void Update() {
    //update the data at any given time ca sa fie si omul ala la curent cu schimbarile

}


void Delete() {

    //ceva delete command i suppose pentru ca o sa greseasca oamenii

}


void Assistance() {
    cout << "SQL HELP PANEL" << endl;
    cout << "Supported commands:" << endl;

    //create table,
    //drop table
    //display table
    // create index
    //drop index
    //insert values
    //select columns or whatever idk yet
    //  select all maybe?
    //delete a table 
    //etc.... whatever is needed
    //
    //
    //
    Separator();
}


void DisplayStatus() {

    Separator();
}


int main() {
    cout << "------------------------------------" << endl;
    cout << "SQL COMMAND PROCESSOR" << endl;
    cout << "------------------------------------" << endl;
    cout << "\nWelcome to the SQL Command Processor!" << endl;
    cout << "Type 'help' for available commands." << endl;
    cout << "Type 'demo' to see a demonstration." << endl;
    cout << "Type 'exit' to quit.\n" << endl;
    Separator();

    char command[1000];

    while (true) {
        cout << "\nSQL> ";
        cin.getline(command, 1000);
        
        if (strlen(command) > 0) {
            Command(command);
        }
        
    }

    return 0;
}
*/

#include <iostream>
#include <string>
#include "Class_Column.h"
#include "ValidationFunctions.h"

using namespace std;

int main() {
    string test1 = "CREATE TABLE myTable ((id, INTEGER, 10, 0), (name, TEXT, 50, ''), (score, FLOAT, 5, 0.0))";
    string test2 = "CREATE TABLE 123Invalid ((id, INTEGER, 10, 0))"; // nume invalid
    string test3 = "CREATE TABLE tableWithoutColumns ()"; // fara coloane

    if (validateCreateTable(test1, CREATE_TABLE))
        cout << "Test1 OK\n";
    else
        cout << "Test1 FAIL\n";

    if (validateCreateTable(test2, CREATE_TABLE))
        cout << "Test2 OK\n";
    else
        cout << "Test2 FAIL\n";

    if (validateCreateTable(test3, CREATE_TABLE))
        cout << "Test3 OK\n";
    else
        cout << "Test3 FAIL\n";


    string tests[] = {
        "INSERT INTO users VALUES(1)",
        "INSERT INTO table1 VALUES(10,20,30)",
        "   INSERT INTO    clients    VALUES   (   1 , 2 , 3   )",
        "INSERT INTO student VALUES(\"Alex\", 10)",
        "INSERT INTO users (1,2)",
        "INSERT INTO VALUES(1,2)",
        "INSERT INTO x VALUES 1,2,3)",
        "INSERT INTO x VALUES()"
    };

    for (string t : tests) {
        cout << "\"" << t << "\"  =>  "
            << (validateInsert(t, CommandType::INSERT) ? "VALID" : "INVALID")
            << endl;
    }

    return 0;
}
