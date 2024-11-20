/*
Title: Online Bookstore Inventory System
Authors: Hassan Mohamed. James Ruane
Date: 12/09/24
Description: Allows the user to manage and search through a 
			 Bookstore Inventory System with the use of Binary
			 Search Trees.
*/
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main() {

	const string SEP_LINE = "-----------------------\n";

	bSearchTreeType<string> bookInv; // TODO: Edit functions so that more information is gotten from nodes, figure out how to put mroe info into one node
	int userChoice = 0;

	cout << "** BOOKSTORE INVENTORY SYSTEM **" << endl;
	// Begin while loop that will only exit if the user chooses to do so
	while (userChoice != 6) { // 5 will be the exit for now

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
		cin >> userChoice;

		while (userChoice < 1 || userChoice > 6) { // Ensure that the users input is within range of valid choices
			cout << SEP_LINE; // Seperation line for formatting
			cout << "ERROR: Invalid Selection" << endl;
			cout << "Please enter a valid number: ";
			cin >> userChoice;
		}

		cout << SEP_LINE; // Seperation line for formatting

		// Carry out a choice depending on what the user has selected
		switch (userChoice) { // TODO: Check if switch statements are allowed
		case 1: // If user has selected 1
			cout << "TODO: Allow user to view inventory" << endl;
			break;
		case 2: // If user has selected 2
			cout << "TODO: Allow user to search for a specific book" << endl;
			break;
		case 3: // If user has selected 3
			cout << "TODO: Add book to the inventory" << endl;
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