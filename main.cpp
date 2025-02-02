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
	nodeType<string>* specificBook;     // Singular book node used for searching for a book
	int userInt = 0;				// Allows the user to input a number
	string userString[4];				// Allows the user to input strings
	int count = 0;					// Counts how many books that have either same title, author, or genre in the inventory.

	cout << "** BOOKSTORE INVENTORY SYSTEM **" << endl;
	// Begin while loop that will only exit if the user chooses to do so
	while (userInt != 7) { // 7 is the exit

		cout << SEP_LINE; // Seperation line for formatting

		// Print out options for user
		cout << "1) View inventory" << endl;
		cout << "2) Search for an existing book" << endl;
		cout << "3) Add a book" << endl;
		cout << "4) Update an existing book" << endl;
		cout << "5) Analyze Inventory" << endl;
		cout << "6) Place a Book Order" << endl;
		cout << "7) Exit Program" << endl;
		// TODO: Add the rest of the functions for analyzing the inventory
		// TODO: Add the rest of the functions for processing book sales, updating inventory quantities, and managing customer orders.

		// Prompt user for input
		cout << "Please enter a valid number: ";
		cin >> userInt;

		while (userInt < 1 || userInt > 7) { // Ensure that the users input is within range of valid choices
			cout << SEP_LINE; // Seperation line for formatting
			cout << "ERROR: Invalid Selection" << endl;
			cout << "Please enter a valid number: ";
			cin >> userInt;
		}

		cout << SEP_LINE; // Seperation line for formatting

		// Carry out a choice depending on what the user has selected
		switch (userInt) {
		case 1: // If user has selected 1 (View Inventory)
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				cout << "CURRENT INVENTORY" << endl << "=================" << endl;
				bookInv.displayInventory();
				
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

						cout << endl;
						bookInv.printByTitle(userString[0], count); // Search and print for book(s) under the same title.

						bookInv.isBookFound(userString[0], userInt, count); // Check how many books under the same title.

						break;
					case 2: // Searching through Author
						cout << "Enter Author of book to search for: ";
						cin.ignore();
						getline(cin, userString[1]); // Store the Author of the book into index 1 of userString
				
						cout << endl;
						bookInv.printByAuthor(userString[1], count); // Search and print for book(s) under the same author(s).

						bookInv.isBookFound(userString[1], userInt, count); // Check how many books under the same author(s).

						break;
					case 3: // Searching through Genre
						cout << "Enter Genre of book to search for: ";
						cin.ignore();
						getline(cin, userString[2]); // Store the Genre into index 2 of userString

						cout << endl;
						bookInv.printByGenre(userString[2], count); // Search and print for book(s) under the same genre.

						bookInv.isBookFound(userString[2], userInt, count); // Check how many books under the same genre.

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

		case 3: // If user has selected 3 (Add a book)

			// Create a new book node to insert
			cin.ignore();
			bookInv.addBook();
			break;

		case 4: // If user has selected 4 (Update an existing book)

			// Check if inventory is empty
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				// Get the books isbn
				cout << "Enter ISBN of book to be updated: ";
				cin.ignore();
				getline(cin, userString[3]); // Store the ISBN into index 3 of userString

				// Update the book with its new quantity.
				bookInv.updateBook(userString[3]);
			}
			break;

		case 5: // If user has selected 5 (Analyze Inventory)

			// Check if inventory is empty
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				// Display genre's sorted by popularity (how often they appear in the inventory)
				cout << "\nGenres Sorted by Popularity:" << endl;
				bookInv.showPopularGenres();
				cout << endl;

				// Display order history from most to least recent
				cout << "Order History (From Most to Least Recent): " << endl;
				bookInv.displayHistory();

				// Display the total amount of books and sales
				cout << "Total Book Amount: " << bookInv.getBookTotal() << endl;
				cout << "Total Sales: " << bookInv.getAllSalesTotal() << "\n\n";
			}

			break;

		case 6: // If user has selected 6 (Place a book order)
			// Check if inventory is empty
			if (bookInv.isEmpty()) {
				cout << "There are no books in the inventory." << endl;
			}
			else {
				// Prompt the user to order the book
				bookInv.orderBook();
			}
			break;
		}
		// If user selects 7, program stops
	}
	cout << "Exiting Program..." << endl;
	return 0;

}
