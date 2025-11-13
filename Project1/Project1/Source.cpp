/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>


class Student {
private:
	char* name; // name=new char[(strlen(name)+1] adbadhgafa'\0'
	int* grades; 
	int noGrades;
	std::string Faculty; 
public:
	Student() {
		name = nullptr;
		grades = nullptr;
		noGrades = 0;
		Faculty = "";
	}
	Student(const char* name, std::string Faculty) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->Faculty = Faculty;
		noGrades = 0;
		grades = nullptr;
	}
	Student(const char* name, std::string Faculty, const int *grades, const int noGrades) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->Faculty = Faculty;
		if (grades != nullptr && noGrades > 0) {
			this->grades = new int[noGrades];
			for (int i = 0; i < noGrades; i++) {
				this->grades[i] = grades[i];
			}
			this->noGrades = noGrades;
		}
		else {
			this->grades = nullptr;
			this->noGrades = 0;
		}
	}

	const char* getName() {
		return this->name;
	}

	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	std::string getFaculty() {
		return this->Faculty;
	}

	void setFaculty(std::string Faculty) {
		this->Faculty = Faculty;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	void setNoGrades(int noGrades) {
		this->noGrades = noGrades;
	}

	int* getGrades() {
		//if (this->grades == nullptr || this->noGrades == 0) {
		//	return nullptr;
		//}
			int* copy = new int[noGrades];
			for (int i = 0; i < noGrades; i++) {
				copy[i] = this->grades[i];
			}
		return copy;
	}

	void setGrades(int* grades, int noGrades) {
		if (grades != nullptr && noGrades > 0) {
			delete[] this->grades;
			this->grades = nullptr;
			this->grades = new int[noGrades];
			for (int i = 0; i < noGrades; i++) {
				this->grades[i] = grades[i];
			}
		}
		else {
			this->grades = nullptr;
			this->noGrades = 0;
		}
	}
	float computeFinalGrade() {
		if (noGrades == 0) {
			return 0;
		}
		float sum = 0;
		for (int i = 0; i < this->noGrades; i++) {
			sum = sum + this->grades[i];
		}
		return sum / noGrades;
	}

	void display() {
		std::cout << "Name: " << this->name<<std::endl;
		std::cout << "Faculty: " << this->Faculty<<std::endl;
		std::cout << "No. Grades:  " << this->noGrades<<std::endl;
		std::cout << "Grades: ";
		for (int i = 0; i < this->noGrades; i++) {
			std::cout << this->grades[i]<<" ";
		}
		std::cout << std::endl;
		std::cout << "Avg: " << computeFinalGrade();
	}

	void addGrade(int grade) {

		if (this->grades != nullptr && this->noGrades > 0) {
			int* newvec = new int[this->noGrades + 1];
			for (int i = 0; i < this->noGrades; i++) {
				newvec[i] = this->grades[i];
			}
			newvec[this->noGrades] = grade;
			delete[]this->grades;
			this->grades = nullptr;
			this->grades = newvec;
			this->noGrades++;
		}
	}

};


int main() {

	int vec[10] = {1,2,3,4,5};

	Student s1("Andrei", "CSIE");
	s1.display();
	Student s2("Ion", "Fac", vec, 5);
	s2.display();
	std::cout << std::endl;
	s2.display();
	s2.addGrade(5);
	s2.display();
	s2.setGrades(vec, 6);
	s2.display();

	return 0;
}
*/