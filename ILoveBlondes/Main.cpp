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
        /*
        if (strlen(command) > 0) {
            Command(command);
        }
        */
    }

    return 0;
}