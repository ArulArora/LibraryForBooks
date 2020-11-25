/*

// Testing

To test the usability of our program we implemented numerous test scenarios that
users could do while using our code. To confirm these test scenarios are correct
we either printed the books/libraries to the console or checked if known post-conditions
matched the program by using assertions. Shown below are the test functions we
created that confirms the program works correctly. In these functions we included
scenarios such as different constructors to initialize Books and Libraries,
insertion of a Book into a Library, removal of a Book in a Library, and the print
method included in each class.

// Limitations

Some limitations of our program is that it does not yet have a constructor that allows
you to insert a book into the library with 2 or 3 parameters. It currently just supports
the insertion of a book with 3 provided parameters. However it is possible for us to
impelement this feature in the future. Additionally, we do not have constructors that
allow for more than 3 parameters for the creation of books or the insertion of books into
the library. It is also possible for us to create these types of constructors in the future.

There is a maximum limit of 256 arguments for the parameters in one function. However,
this number might not be reached as the stack size might be too large for the system's
memory to handel before the parameters reach 256. Practically, this is not a concern
as you would not need so many parameters for books.

A limitation in regards of the Library is that the maximum number of Books that can
be stored cannot exceed 4GB (2^30 char values) of storage. This is the maximum storage
of a vector, however, this limitation is not going to be a practical issue since users
won't enter that many books in the library.

Using the string.max_size() function, we found that a limitation in regards to the value
stored in the strings is 9223372036854775807 characters for this compiler or the point at which
the system fails to allocate enough storage. This limitation is not going to be a practical
issue, as names, titles, and date of publications will not reiqure that length of characters.
*/

#include <iostream>
#include "a5_book.hpp"
#include "a5_library.hpp"
#include <cassert>

using namespace std;

// PURPOSE: Tests all the constructors used for Book
void test_book_constructors() {
	// test three paramater constructor
	Book hp("Harry Potter", "JK Rowling", "September 1 1998");
	// verify correctness
	hp.print();

	// test two paramater constructor
	Book lotr("Lord of the Rings", "J. R. R. Tolkein");
	// verify correctness
	assert(lotr.get_title() == "Lord of the Rings");
	assert(lotr.get_authors() == "J. R. R. Tolkein");
	assert(lotr.get_dop() == "N/A");

	// test one paramater constructor
	Book lop("Life of Pi");
	// verify correctness
	lop.print();

	// test empty paramater/default constructor
	Book no_book;
	// verify correctness
	no_book.print();
}

// PURPOSE: Tests all the constructors used for Library
void test_library_constructors()
{
	// test empty paramater constructor
	Library empty_library;
	// verify correctness
	empty_library.print();

	// test vector paramater constructor
	vector<Book> test_books;
	Book hp("Harry Potter", "JK Rowling", "September 1 1998");
	Book lotr("Lord of the Rings", "J. R. R. Tolkein");
	test_books.push_back(hp);
	test_books.push_back(lotr);
	Library test_library(test_books);

	// verify correctness
	test_library.print();
}

// PURPOSE: Tests scenarios for inserting a Book into a Library
void test_book_insert() {
	// insert strings
	Library my_new_lib1;
	assert(my_new_lib1.insert("title1", "author1", "date1"));
	assert(!my_new_lib1.insert("title1", "author1", "date1")); // cannot add duplicate item

	// insert objects
	Book my_book1("title", "author", "date");
	Book my_book2("title2", "author2");
	Book my_book3("title3");
	Book empty_book;

	Library my_new_lib2;
	assert(my_new_lib2.insert(my_book1));
	assert(my_new_lib2.insert(my_book2));
	assert(my_new_lib2.insert(my_book3));
	assert(my_new_lib2.insert(empty_book));

	// title and author is the is the same as book2
	Book my_book4("title2", "author2", "date4");
	assert(my_new_lib2.insert(my_book4));
	assert(!my_new_lib2.insert(my_book2)); // duplicate item, no book added
	my_new_lib2.print();
}

// PURPOSE: Tests scenarios for removing a Book from a Library
void test_book_remove() {
	// remove string, set up
	Library my_new_lib1;
	my_new_lib1.insert("title1", "author1", "date1");
	my_new_lib1.insert("title2", "author2", "date2");
	my_new_lib1.insert("title3", "author2", "date2");

	// test removal scenarios for strings
	assert(!my_new_lib1.remove("title1", "author1", "date2")); // no book is found, removes nothing
	assert(my_new_lib1.remove("title2", "author2", "date2")); // removes the second book
	assert(my_new_lib1.remove("title1", "author1", "date1")); // removes the first book
	my_new_lib1.print();

	// remove for objects, set up
	Book my_book("title", "author", "date");
	Book my_book2("title2", "author2");
	Book my_book3("title3");

	vector<Book> my_book_vector1 = { my_book, my_book2, my_book3 };
	Library my_new_lib2(my_book_vector1);

	// test removal scenarios for objects
	Book my_book4("title4", "author4", "date4");
	assert(!my_new_lib2.remove(my_book4)); // no book is found, removes nothing
	assert(my_new_lib2.remove(my_book2)); // removes the second book
	assert(my_new_lib2.remove(my_book3)); // removes the last book
	my_new_lib2.print();
}

// PURPOSE: Test scenarios for printing Book attributes and Books in a Library
void test_print() {
	// test book print 
	Book hp("Harry Potter", "JK Rowling", "September 1 1998");
	hp.print();
	Book lotr("Lord of the Rings", "J. R. R. Tolkein");
	lotr.print();
	Book lop("Life of Pi");
	lop.print();
	Book empty_book;
	empty_book.print();

	// test library print
	vector<Book> my_books = { hp, lotr, lop, empty_book };
	Library my_library(my_books);
	cout << endl;
	my_library.print();
}

void execute_tests() {
	//test_book_constructors();
	//test_library_constructors();
	//test_book_insert();
	//test_book_remove();
	test_print();
}

int main() {
	execute_tests();
}
