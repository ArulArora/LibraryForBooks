#include <iostream>
#include "a5_book.hpp"

using namespace std;

// PURPOSE: Class that models a book

/*
CONSTRUCTORS
*/

// Parametric constructor with all attributes specified
Book::Book(string new_title, string new_authors, string new_dop) :
	book_title(new_title),
	book_authors(new_authors),
	date_of_publication(new_dop) {}

// PURPOSE: Parametric constructor with title and authors only
Book::Book(string new_title, string new_authors) :
	book_title(new_title),
	book_authors(new_authors),
	date_of_publication("N/A") {}

// PURPOSE: Parametric constructor with title only
Book::Book(string new_title) :
	book_title(new_title),
	book_authors("N/A"),
	date_of_publication("N/A") {}

// PURPOSE: Default constructor
Book::Book() :
	book_title("N/A"),
	book_authors("N/A"),
	date_of_publication("N/A") {}

/*
GETTERS
*/

// Service function that outputs all attribute value
void Book::print() {
	cout << book_title << " "
		<< book_authors << " "
		<< date_of_publication << endl;
}

// accessor methods for member attributes
string Book::get_title() {
	return book_title;
}

string Book::get_authors() {
	return book_authors;
}
string Book::get_dop() {
	return date_of_publication;
}