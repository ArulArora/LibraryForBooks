#ifndef SYDE121_A5_BOOK_HPP
#define SYDE121_A5_BOOK_HPP
#include <iostream>

using namespace std;

// PURPOSE: Models a book instance with corresponding attributes
class Book {
	string book_title, book_authors, date_of_publication;
public:
	// PURPOSE: Parametric constructor with all attributes specified
	Book(string new_title, string new_authors, string new_dop);

	// PURPOSE: Parametric constructor with title and authors only
	Book(string new_title, string new_authors);

	// PURPOSE: Parametric constructor with title only
	Book(string new_title);

	// PURPOSE: Default constructor
	Book();

	// PURPOSE: Service function that outputs all attribute values
	void print();

	// PURPOSE: Simple accessor methods for member attributes
	string get_title();
	string get_authors();
	string get_dop();
};
#endif 

