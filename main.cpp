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

	bSearchTreeType<string> bookInv; // TODO: Edit functions so that more information is gotten from nodes, figure out how to put mroe info into one node
	int userInt = 0;
	string userString[4];


	cout << "** BOOKSTORE INVENTORY SYSTEM **" << endl;
	// Begin while loop that will only exit if the user chooses to do so
	while (userInt != 6) { // 5 will be the exit for now

		cout << SEP_LINE; // Seperation line for formatting

		// Print out options for user
		cout << "1) View inventory" << endl;
		cout << "2) Search for a book" << endl;
		cout << "3) Add a book" << endl;
		cout << "4) Update an existing book" << endl;
		cout << "5) Search for an existing book" << endl;
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
			cout << "TODO: Allow user to view inventory (aside from titles)" << endl;
			bookInv.preorderTraversal();
			cout << endl;
			break;
		case 2: // If user has selected 2
			cout << "TODO: Allow user to search for a specific book" << endl;

			break;
		case 3: // If user has selected 3

			cout << "Enter Title of Book: ";
			cin.ignore();
			getline(cin, userString[0]); // Store the title within index 0 of userString

			cout << "Enter Book Author: ";
			cin.ignore();
			getline(cin, userString[1]); // Store the author within index 1 of userString

			cout << "Enter Book Genre: ";
			cin.ignore();
			getline(cin, userString[2]); // Store the genre within index 2 of userString

			cout << "Enter Book's ISBN: "; 
			cin.ignore();
			getline(cin, userString[3]); // Store the ISBN within index 3 of userString

			cout << "Enter Book Quantity: ";
			cin >> userInt;				 // Store the quantity of the book within userString

			// TODO: insert other things BESIDE the title of the book into each node
			bookInv.insert(userString[0]);

			// Set userInt back to 0 so unexpected choice selection does not occur
			userInt = 0; 
			break;
		case 4: // If user has selected 4
			cout << "TODO: Update an existing book (searching for the book through the books ISBN)" << endl;
			break;
		case 5: // If user has selected 5
			cout << "TODO: Search for an existing book (through the books ISBN)" << endl;
			break;
		}
		// If user selects 6, program stops
	}
	cout << "Exiting Program..." << endl;
	return 0;

}