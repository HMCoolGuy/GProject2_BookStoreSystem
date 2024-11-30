/*
Title: Online Bookstore Inventory System
Authors: Hassan Mohamed. James Ruane
Date: 12/09/24
Description: Allows the user to manage and search through a 
			 Bookstore Inventory System with the use of Binary
			 Search Trees.
*/
#include <iostream>
#include <string>
#include "binarySearchTree.h"

using namespace std;

int main() {
	
	const string SEP_LINE = "-----------------------\n";

	bSearchTreeType<string> bookInv;	// Contains books as nodes in the binary search tree
	int userInt = 0;					// Allows the user to input a number
	string userString[4];				// Allows the user to input strings

	cout << "** BOOKSTORE INVENTORY SYSTEM **" << endl;
	// Begin while loop that will only exit if the user chooses to do so
	while (userInt != 6) { // 5 will be the exit for now

		cout << SEP_LINE; // Seperation line for formatting

		// Print out options for user
		cout << "1) View inventory" << endl;
		cout << "2) Search for an existing book" << endl;
		cout << "3) Add a book" << endl;
		cout << "4) Update an existing book" << endl;
		cout << "5) Analyze Inventory" << endl;
		cout << "6) Exit Program" << endl;
		// TODO: Add the rest of the functions for analyzing the inventory
		// TODO: Add the rest of the functions for processing book sales, updating inventory quantities, and managing customer orders.

		// Prompt user for input
		cout << "Please enter a valid number: ";
		cin >> userInt;

		while (userInt < 1 || userInt > 6) { // Ensure that the users input is within range of valid choices
			cout << SEP_LINE; // Seperation line for formatting
			cout << "ERROR: Invalid Selection" << endl;
			cout << "Please enter a valid number: ";
			cin >> userInt;
		}

		cout << SEP_LINE; // Seperation line for formatting

		// Carry out a choice depending on what the user has selected
		switch (userInt) { // TODO: Check if switch statements are allowed
		case 1: // If user has selected 1
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				cout << "CURRENT INVENTORY" << endl << "=================" << endl;
				bookInv.inorderTraversal();
				
				cout << endl;
			}

			break;
		case 2: // If user has selected 2 (Search for an existing book)
			// Confirm the inventory is not empty
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			// Print out options for user to search for book (either through title, author, genre, or ISBN)
			else {
				cout << "Search for book by..." << endl;
				cout << "1) Title" << endl;
				cout << "2) Author" << endl;
				cout << "3) Genre" << endl;
				cout << "4) ISBN" << endl;
				cout << "5) Go back" << endl;

				// Prompt user for input
				cout << "Please enter a valid number: ";
				cin >> userInt;
		
				while (userInt < 1 || userInt > 5) { // Ensure that the users input is within range of valid choices
					cout << SEP_LINE; // Seperation line for formatting
					cout << "ERROR: Invalid Selection" << endl;
					cout << "Please enter a valid number: ";
					cin >> userInt;
				}
	
				switch (userInt) {
					case 1: // Searching through title
						cout << "Enter title of book to search for: ";
						cin.ignore();
						getline(cin, userString[0]); // Store the title of the Book into index 0 of userString

						specificBook = bookInv.searchByTitle(userString[0]); // Search for the book through its title
	
						bookInv.findBook(bookInv, specificBook); // Check if the books exists or not

						break;
					case 2: // Searching through Author
						cout << "Enter Author of book to search for: ";
						cin.ignore();
						getline(cin, userString[1]); // Store the Author of the book into index 1 of userString
				
						specificBook = bookInv.searchByAuthor(userString[1]); // Search for the book through its Author

						bookInv.findBook(bookInv, specificBook); // Check if the books exists or not

						break;
					case 3: // Searching through Genre
						cout << "Enter Genre of book to search for: ";
						cin.ignore();
						getline(cin, userString[2]); // Store the Genre into index 2 of userString

						specificBook = bookInv.searchByGenre(userString[2]); // Search for the book through its Genre

						bookInv.findBook(bookInv, specificBook); // Check if the books exists or not

						break;
					case 4: // Searching through ISBN
						cout << "Enter ISBN of book to search for: ";
						cin.ignore();
						getline(cin, userString[3]); // Store the ISBN into index 3 of userString
				
						specificBook = bookInv.searchByISBN(userString[3]); // Search for the book through its ISBN

						bookInv.findBook(bookInv, specificBook); // Check if the books exists or not

					case 5: // Going back to the main menu
						break;
					}
				}
			break;
		case 3: // If user has selected 3

			// Create a new book node to insert
			cin.ignore();
			bookInv.addBook();

			break;
		case 4: // If user has selected 4

			// Check if inventory is empty
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				// Get the books isbn
				cout << "Enter ISBN of book to be updated: ";
				cin.ignore();
				getline(cin, userString[3]); // Store the ISBN into index 3 of userString

				while (userString[3].length() != 10 && userString[3].length() != 13) { // Check if the length of the ISBN is valid.
					// Call the helper function searchByISBN
					cout << "ERROR: Invalid ISBN (Must be 10 or 13 characters)" << endl;
					cout << "Enter Book's ISBN: ";
					getline(cin, userString[3]); // Store the ISBN within index 3 of userString
				}

				// Update the book with its new quantity.
				bookInv.updateBook(userString[3]);
			}
			break;
		case 5: // If user has selected 5
			cout << "TODO: Put inventory analysis functions here (identifying popular gneres, tracking book sales, and managing stock levels)" << endl;
			break;
		}
		// If user selects 6, program stops
	}
	cout << "Exiting Program..." << endl;
	return 0;

}
