#ifndef SYDE121_A5_LIBRARY_HPP
#define SYDE121_A5_LIBRARY_HPP
#include <vector>
#include "a5_book.hpp"

using namespace std;

class Library {
	vector<Book> my_books;

public:
	// PURPOSE: Default construcor that initializes the vector attribute implicitly
	Library();

	// PURPOSE: Parametric construcor that takes a vector of Books and stores the values into the vector attribute
	Library(vector<Book> my_library);

	// PURPOSE: Setter methods that inserts a unique Book into the vector attribute
	bool insert(string, string, string);
	bool insert(Book);

	// PURPOSE: Setter methods that removes a Book from the vector attribute
	bool remove(string, string, string);
	bool remove(Book);

	// PURPOSE: Outputs all the books stored in the Library instance
	void print();
};
#endif