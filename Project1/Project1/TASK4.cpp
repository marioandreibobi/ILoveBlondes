/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Book {
private:
	const string ISBN="";
	char* title = nullptr;
	int* raitings = nullptr;
	int noRaitings = 0;
	int pages = 0;
public:
	int static TOTAL_BOOKS;
	Book(): ISBN("") {
		this->title = nullptr;
		this->raitings = nullptr;
		this->noRaitings = 0;
		this->pages = 0;

		Book::TOTAL_BOOKS++;

	}
	Book(const string _ISBN,const char* title, int* raitings, int noRaitings, int pages)
		: ISBN(_ISBN)
	{
		this->noRaitings = noRaitings;
		this->pages = pages;
		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		this->raitings = new int[noRaitings];
		for (int i = 0; i < noRaitings; i++) {
			this->raitings[i] = raitings[i];
		}
		Book::TOTAL_BOOKS++;
	}

	void setTitle(char* title) {
		if (this->title != nullptr) {
			delete[] this->title;
			this->title = nullptr;
		}
		if (title == nullptr) {
			this->title = nullptr;
		}
		else {
			this->title = new char[strlen(title)+1];
				strcpy_s(this->title, strlen(title)+1, title);
		}
	}

	char* getTitle(){
		char* copy = new char[strlen(title) + 1];
		strcpy_s(copy, strlen(title) + 1, title);
		return copy;
	}

	void setRaitings(int* raintings, int noRaitings) {
		if (this->raitings != nullptr) {
			delete[]this->raitings;
			this->raitings = nullptr;
		}
		if (raintings == nullptr || noRaitings < 1) {
			this->raitings = nullptr;
			this->noRaitings = 0;
		}
		else {
			this->raitings = new int[noRaitings];
			for (int i = 0; i < noRaitings; i++) {
				this->raitings[i] = raintings[i];
			}
		}
	}

	int* getRaitings() {
		int* copy = new int[noRaitings];
		for (int i = 0; i < noRaitings; i++) {
			copy[i] = raitings[i];
		}
		return copy;
	}

	void setNoRaitings(int noRaitings) {
		this->noRaitings = noRaitings;
	}
	int getNoRaitings() {
		return this->noRaitings;
	}

	void setPages(int pages) {
		this->pages = pages;
	}
	int getPages() {
		return this->pages;
	}


	void display() {
		cout << "------------------------------------------------------------"<<endl;
		cout << ISBN << endl;
		if (title == nullptr) {
			cout << "Title is empty" << endl;
		}
		else {
			for (int i = 0; i < strlen(title); i++) {
				cout << title[i];
			}
			cout << endl;
		}
		if (raitings == nullptr) {
			cout << "There are no raitings"<<endl;
		}
		else {
			for (int i = 0; i < noRaitings; i++) {
				cout << raitings[i]<<" ";
			}
			cout << endl;
		}
		cout <<"Pages:  "<< pages << endl;
		cout << "The total books are: " << Book::TOTAL_BOOKS << endl;
	
	}

	void addRaiting(int newraiting) {
		int* newvec = new int[noRaitings + 1];
		for (int i = 0; i < noRaitings; i++) {
			newvec[i] = raitings[i];
		}
		newvec[noRaitings] = newraiting;
		delete[]raitings;
		raitings = nullptr;
		noRaitings++;
		raitings = newvec;
	}

	
	~Book() {
		if (title != nullptr) {
			delete[] title;
			title = nullptr;
		}
		if (raitings != nullptr) {
			delete[] raitings;
			raitings = nullptr;
		}
		Book::TOTAL_BOOKS--;
		cout << "Books eliminated, total current books are: " << Book::TOTAL_BOOKS<<endl;
	}

};
int Book::TOTAL_BOOKS = 0;

int main() {

	Book b1;
	b1.display();
	Book b2("5-238-132555-5", "Ion", new int[5] {1, 2, 3, 4, 5}, 5, 10);
	int* raitings = new int[7] { 1, 2, 4, 5, 6, 7, 2};
	b2.display();
	Book b3("0-306-40615-2", "Fericirea!", raitings, 7, 25);
	b3.addRaiting(3);
	b3.display();


	cout << "--------------------------------------------------------------"<<endl;
	int* copy = b3.getRaitings();
	for (int i = 0; i < 7; i++) {
		cout << copy[i] << " ";
	}
	cout << endl;
	delete[]copy;

	char* copy_ = b3.getTitle();
	for (int i = 0; i < strlen(copy_); i++) {
		cout << copy_[i];
	}
	cout << endl;
	delete[]copy_;
	cout << "--------------------------------------------------------------"<<endl;


	return 0;
}
*/

