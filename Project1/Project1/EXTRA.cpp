#include <iostream>
#include <cstring>
using namespace std;


class Book {
private:
	char* title = nullptr;
	char* author = nullptr;
	int year = 0;
	float* reviews = nullptr;
	int noReviews = 0;
public:
	Book() {
		title = nullptr;
		author = nullptr;
		year = 0;
		reviews = nullptr;
		noReviews = 0;
	}
	Book(const char* title,const char* author, int year, float* reviews, int noReviews) {

		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);

		this->author = new char[strlen(author) + 1];
		strcpy_s(this->author, strlen(author) + 1, author);

		this->reviews = new float[noReviews];
		for (int i = 0; i < noReviews; i++) {
			this->reviews[i] = reviews[i];
		}

		this->year = year;
		this->noReviews = noReviews;
	}
	char* getTitle() {
		if (title == nullptr) {
			return nullptr;
		}
		else {
			char* copy = new char[strlen(title) + 1];
			strcpy_s(copy, strlen(title) + 1, title);
			return copy;
		}
	}
	char* getAuthor() {
		if (author == nullptr) {
			return nullptr;
		}
		else {
			char* copy = new char[strlen(author) + 1];
			strcpy_s(copy, strlen(title) + 1, author);
			return copy;
		}
	}
	int getYear() {
		return this->year;
	}

	int getNoReviews() {
		return this->noReviews;
	}

	void setTitle(char* title) {
		if (this->title != nullptr) {
			delete[] this->title;
			this->title = nullptr;
		}
		if (title != nullptr) {
			this->title = new char[strlen(title) + 1];
			strcpy_s(this->title, strlen(title) + 1, title);
		}
		else {
			this->title = nullptr;
		}
	}

	void setAuthor(char* author) {
		if (this->author != nullptr) {
			delete[] this->author;
			this->author = nullptr;
		}
		if (author != nullptr) {
			this->author = new char[strlen(author) + 1];
			strcpy_s(this->author, strlen(author) + 1, author);
		}
		else {
			this->author = nullptr;
		}
	}

	void setYear(int year) {
		this->year = year;
	}

	void setNoReviews(int noReviews) {
		this->noReviews = noReviews;
	}

	float* getReviews() {
		if (this->reviews == nullptr) {
			return nullptr;
		}
		else {
			float* copy = new float[noReviews];
			for (int i = 0; i < noReviews; i++) {
				copy[i] = reviews[i];
			}
			return copy;
		}

		
	}

	void setReviews(float* reviews, int noReviews) {
		if (this->reviews != nullptr) {
			delete[] this->reviews;
			this->reviews = nullptr;
		}
		if (reviews == nullptr || noReviews==0) {
			this->reviews = nullptr;
			noReviews = 0;
		}
		else {
			this->reviews = new float[noReviews];
			for (int i = 0; i < noReviews; i++) {
				this->reviews[i] = reviews[i];
			}
		}
	}

	void addReview(float score) {
		float* newvec = new float[noReviews + 1];
		for (int i = 0; i < noReviews; i++) {
			newvec[i] = reviews[i];
		}
		newvec[noReviews] = score;
		delete[]reviews;
		reviews = nullptr;
		noReviews++;
		reviews = newvec;
	}

	float getAverageReviewsValue() {
		if (this->reviews == nullptr || this->noReviews < 1) {
			throw "There are no reviews ";
		}
		else {
			float avg = 0;
			float sum = 0;
			for (int i = 0; i < noReviews; i++) {
				sum = sum + reviews[i];
			}
			avg = sum / noReviews;
			return avg;
		}
	}
	float getMinimumReviewValue() {
		if (this->reviews == nullptr || this->noReviews < 1) {
			throw "There are no reviews ";
		}
		else {
			float min=reviews[0];
			for (int i = 0; i < noReviews; i++) {
				if (reviews[i] < min) {
					min = reviews[i];
				}
			}
			return min;
		}

	}

	int getMinimumReviewCount() {
		if (this->reviews == nullptr || this->noReviews < 1) {
			throw "There are no reviews ";
		}
		else {
			int count = 0;
			float min = getMinimumReviewValue();
			for (int i = 0; i < noReviews; i++) {
				if (reviews[i] == min) {
					count++;
				}
			}
			return count;
		}
	}

};


int main() {

	float* ceva = new float[1] {0};
	float* reviews = new float[5] {1, 2, 3, 1, 5};
	Book b1("Fericirea!", "Eminescu", 1930, reviews, 5);
	cout << b1.getTitle()<<endl;
	float a = b1.getAverageReviewsValue();
	cout << a<<endl;
	cout << b1.getMinimumReviewValue() << endl;
	cout << b1.getMinimumReviewCount()<<endl;
	return 0;
}