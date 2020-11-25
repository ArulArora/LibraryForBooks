#include <iostream>
#include <vector>
#include "a5_library.hpp"

using namespace std;

// PURPOSE: Class that models a library

/*
CONSTRUCTORS
*/

// Default construcor that initializes the vector attribute implicitly
Library::Library() {}

// Parametric construcor that takes a vector of Books and stores the values 
Library::Library(vector <Book> my_library) :
    my_books(my_library) {}

/*
GETTERS
*/

// Outputs all the books stored in the Library instance
void Library::print() {
    for (int i = 0; i < my_books.size(); ++i) {
        my_books[i].print();
    }
}

/*
SETTERS
*/

/*insert FOR STRINGS*/

bool Library::insert(string new_title, string new_authors, string new_dop)
{
    for (int index = 0; index < my_books.size(); index++)
    {
        if (new_title == my_books[index].get_title() && new_authors == my_books[index].get_authors() && new_authors == my_books[index].get_authors())
        {
            return false;
        }
    }
    Book new_book(new_title, new_authors, new_dop);
    my_books.push_back(new_book);
    return true;
}

/*insert FOR OBJECTS*/

bool Library::insert(Book new_book) {
    for (int index = 0; index < my_books.size(); index++)
    {
        if (new_book.get_title() == my_books[index].get_title() &&
            new_book.get_authors() == my_books[index].get_authors() &&
            new_book.get_dop() == my_books[index].get_dop())
        {
            return false;
        }
    }
    my_books.push_back(new_book);
    return true;
}

/*removal FOR STRINGS*/

bool Library::remove(string new_title, string new_authors, string new_dop) {
    for (int index = 0; index < my_books.size(); index++)
    {
        if (new_title == my_books[index].get_title() && new_authors == my_books[index].get_authors() && new_dop == my_books[index].get_dop())
        {
            my_books.erase(my_books.begin() + index);
            return true;
        }
    }
    return false;
}

/*removal FOR OBJECTS*/

bool Library::remove(Book new_book) {
    for (int index = 0; index < my_books.size(); index++)
    {

        if (new_book.get_title() == my_books[index].get_title() && new_book.get_authors() == my_books[index].get_authors() && new_book.get_dop() == my_books[index].get_dop())
        {
            my_books.erase(my_books.begin() + index);
            return true;
        }
    }
    return false;
}