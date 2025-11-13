/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class Student {
	char* name;
	float* grades;
	int numberOfGrades;
	string faculty;

public:
	//constructor default
	Student() {
		this->name = new char[strlen("Anonim") + 1];
		strcpy(this->name, "Anonim");
		this->grades = NULL;
		this->numberOfGrades = 0;
		this->faculty = "Necunoscut";
	}

	//constructor cu nume si facultate
	Student(const char* name, string faculty) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->grades = NULL;
		this->numberOfGrades = 0;
		this->faculty = faculty;
	}

	//constructor cu toti param
	Student(const char* name, float* grades, int numberOfGrades, string faculty) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->numberOfGrades = numberOfGrades;
		this->grades = new float[this->numberOfGrades];
		for (int i = 0; i < numberOfGrades; i++) {
			this->grades[i] = grades[i];
		}
		this->faculty = faculty;
	}


	Student(const Student&) = delete;            // disable copy constructor
	Student& operator=(const Student&) = delete; // disable assignment operator
	//destructor
	~Student() {
		if (this->name != NULL) {
			delete[]this->name;
		}
		if (this->grades != NULL) {
			delete[]this->grades;
		}
	}


	//getter & setter for name
	char* getName() {
		return this->name;
	}

	void setName(const char* name) {
		if (this->name != NULL)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	//getter & setter for the numberOfGrades field
	int getNumberOfGrades() {
		return this->numberOfGrades;
	}

	void setNumberOfGrades(int numberOfGrades) {
		this->numberOfGrades = numberOfGrades;
	}

	//setter for the grades field
	void setGrades(int numberOfGrades, float* grades) {
		if (this->grades != NULL) {
			delete[]this->grades;
		}
		this->numberOfGrades = numberOfGrades;
		this->grades = new float[this->numberOfGrades];
		for (int i = 0; i < numberOfGrades; i++) {
			this->grades[i] = grades[i];
		}
	}

	//getter for the faculty field
	string getFaculty() {
		return this->faculty;
	}

	float computeFinalGrade() {
		if (numberOfGrades == 0)
			return 0;
		float sum = 0;
		for (int i = 0; i < numberOfGrades; i++)
			sum = sum + grades[i];
		return sum / numberOfGrades;
	}

	void display() {
		cout << "Name:" << name << endl;
		cout << "Faculty:" << faculty << endl;
		cout << "Grades:";
		for (int i = 0; i < numberOfGrades; i++) {
			cout << grades[i] << " ,  ";
		}
		cout << endl;
		cout << "Average:" << computeFinalGrade() << endl;
	}



};

int main() {
	Student s;
	cout << s.getName() << endl;
	cout << s.getNumberOfGrades() << endl;
	cout << s.getFaculty() << endl;
	cout << endl << endl;
	s.setName("Andrei");
	float grades[] = { 3.4,4.5,5.6,7.8 };
	s.setGrades(4, grades);
	cout << s.getName() << endl;
	cout << s.getNumberOfGrades() << endl;
	cout << s.getFaculty() << endl;
	cout << endl << endl;

	Student s1("Gicu", "Politehnica");
	cout << s1.getName() << endl;
	cout << s1.getNumberOfGrades() << endl;
	cout << s1.getFaculty() << endl;
	cout << endl << endl;

	float grades2[] = { 3.4,5.6,7.9,9.8 };
	Student s2("Gelu", grades2, 4, "ASE");
	cout << s2.getName() << endl;
	cout << s2.getNumberOfGrades() << endl;
	cout << s2.getFaculty() << endl;
	cout << endl << endl;

	cout << s2.computeFinalGrade() << endl;
	s2.display();
}
*/