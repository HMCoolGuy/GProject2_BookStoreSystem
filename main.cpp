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
		switch (userInt) {
		case 1: // If user has selected 1 (View Inventory)
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
					cout << "TODO: search through title" << endl;
					break;
				case 2: // Searching through Author
					cout << "TODO: search through author" << endl;
					break;
				case 3: // Searching through Genre
					cout << "TODO: search through genre" << endl;
					break;
				case 4: // Searching through ISBN
					cout << "Enter ISBN of book to search for: ";
					cin.ignore();
					getline(cin, userString[3]); // Store the ISBN into index 3 of userString

					specificBook = bookInv.searchByISBN(userString[3]); // Search for the book through its ISBN

					cout << endl;
					if (specificBook == nullptr) {	// Confirm that the book exists
						cout << "This book is not in inventory." << endl;
					}
					else {  // Display the book's information
						cout << "Book Found!" << endl << "=================" << endl;
						bookInv.printBook(specificBook);
					}
					cout << endl;

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
			cout << "TODO: Put inventory analysis functions here (identifying popular gneres, tracking book sales, and managing stock levels)" << endl;
			break;
		}
		// If user selects 6, program stops
	}
	cout << "Exiting Program..." << endl;
	return 0;

}
