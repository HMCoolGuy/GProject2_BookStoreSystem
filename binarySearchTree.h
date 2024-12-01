//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <string>
#include <vector> // TODO: check if vectors are allowed
#include "binaryTree.h"

using namespace std;

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
    //Function to determine if searchItem is in the binary
    //search tree.
    //Postcondition: Returns true if searchItem is found in
    //               the binary search tree; otherwise,
    //               returns false.

    void addBook();
    // A function add a new book node

    void updateBook(const string& bookISBN);
    // A function to update a book's values (searching through the book's ISBN).

    void insert
    (const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity);
    //Function to insert insertItem in the binary search tree.
    //Postcondition: If there is no node in the binary search
    //               tree that has the same info as
    //               insertItem, a node with the info
    //               insertItem is created and inserted in the
    //               binary search tree.

    void deleteNode(const elemType& deleteItem);
    //Function to delete deleteItem from the binary search tree
    //Postcondition: If a node with the same info as deleteItem
    //               is found, it is deleted from the binary
    //               search tree.
    //               If the binary tree is empty or deleteItem
    //               is not in the binary tree, an appropriate
    //               message is printed.


    nodeType<elemType>* searchByISBN(const elemType& searchItem) const;
    // A function to search for a book through the book's ISBN.


    void showPopularGenres();
    // A function to show genres within the inventory based off of their popularity

    void orderBook();
    // A function  that let the user order a book

    nodeType<elemType>* searchByTitle(const elemType& searchItem) const;
    // A function to locate a book through the book's title.

    nodeType<elemType>* searchByAuthor(const elemType& searchItem) const;
    // A function to search the tree for the author of the book.

    nodeType<elemType>* searchByGenre(const elemType& searchItem) const;
    // A function used to find the located genre of the book in the tree.

    void findBook(const bSearchTreeType<elemType>& p, nodeType<elemType>* specificBook);
    // Checks if the books exists in the inventory

private:

    void deleteFromTree(nodeType<elemType>*& p);
    //Function to delete the node to which p points is
    //deleted from the binary search tree.
    //Postcondition: The node to which p points is deleted
    //               from the binary search tree.

    bool checkLesser(string str1, string str2);
    // Function to check for which string is lesser than the other
    // for alphabetical sorting purposes.
    
    nodeType<elemType>* searchISBN (nodeType<elemType>* p, const elemType& searchItem) const;
    // A helper function used to navigate where the located ISBN is in the entire tree.

    nodeType<elemType>* searchTitle(nodeType<elemType>* p, const elemType& searchItem) const;
    // A helper function that supports the searchByTitle function.
    
    nodeType<elemType>* searchAuthor(nodeType<elemType>* p, const elemType& searchItem) const;
    // A helper function used to locate where the title of the book is in the tree.

    nodeType<elemType>* searchGenre(nodeType<elemType>* p, const elemType& searchItem) const;
    // A helper function used to assist the searchByGenre function.
    
    vector<genreType> getGenres(nodeType<elemType>* p, vector<genreType>& genreList);
    // A helper function to get genres within the inventory based off of their popularity

};


template <class elemType>
bool bSearchTreeType<elemType>::search
(const elemType& searchItem) const
{
    nodeType<elemType>* current;
    bool found = false;

    if (this->root == nullptr)
        cout << "There are no books in the inventory." << endl;
    else
    {
        current = this->root;

        while (current != nullptr && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->lLink;
            else
                current = current->rLink;
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::addBook() {
    int userNum = 0;            // Input integer from the user
    string userString[4];       // Input strings from the user

    // Get input from the user
    this->setInfo(userString[0], userString[1], userString[2], userString[3], userNum);

    // Ensure the book is within the tree to confirm with the user
    nodeType<elemType>* specificBook = searchByISBN(userString[3]);
    if (specificBook == nullptr) {
        cout << "Book added!" << endl;
    }

    // Create a new node from the user input
    insert(userString[0], userString[1], userString[2], userString[3], userNum);
}

template <class elemType>
void bSearchTreeType<elemType>::insert
(const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity)
{
    nodeType<elemType>* current; //pointer to traverse the tree
    nodeType<elemType>* trailCurrent = nullptr; //pointer
    //behind current
    nodeType<elemType>* newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;


    // Setup the information for the book
    newNode->info = insertTitle;     // Set the new book's title
    newNode->author = insertAuthor; // Set the new book's author
    newNode->genre = insertGenre;   // Set the new book's genre
    newNode->ISBN = insertISBN;     // Set the new book's ISBN
    newNode->quantity = insertQuantity; // Set the quantity of this book
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    // Node is sorted alphabetically (Where A has highest root priority, and z is lowest priority)
    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->ISBN == insertISBN) // ISBN's are compared to make sure no duplicate books are added
            {
                cout << "This book is already in the inventory!" << endl;
                return;
            }
    
            // Iterate through each character of both the string to determine order
            if (checkLesser(current->info, insertTitle)) {
                // If mismatching insert character is lesser than current string character
                current = current->lLink; 
            }
            else {
                // If mismatching insert character is greater than current string character
                current = current->rLink;
            }
        }//end while

        // Determine which direction the previous node should point to for the new node
        if (checkLesser(trailCurrent->info, insertTitle)) { 
            // If character of insert string goes before previous string's character, point lLink of previous node to the new node
            trailCurrent->lLink = newNode;
        }
        else {
            // If character of insert string goes after previous string's character, point rLink of previous node to the new node
            trailCurrent->rLink = newNode;
        }
    }

}//end insert

template <class elemType>
void bSearchTreeType<elemType>::updateBook(const string& bookISBN) { // A function to update the book's quantity.
    int userNum = 0;            // Input integer from the user
    string userString[4];       // Input strings from the user
    nodeType<elemType>* specificBook = searchByISBN(bookISBN); // Assign specificBook with a book that contains the same ISBN as bookISBN 

    if (specificBook != nullptr) { // Check if the book exists or not
        cout << "Book Found. Please enter new information." << endl;

        this->setInfo(userString[0], userString[1], userString[2], userString[3], userNum);

        // Check if the new ISBN is not a copy of an already existing ISBN
        if (searchByISBN(userString[3]) == nullptr || userString[3] == specificBook->ISBN) {
            // Delete the book specified by the ISBN (Resets the book's sales by default, but sales are still kept in totalSales)
            deleteNode(specificBook->info);

            // Insert a new book with the new information
            cout << "Book Updated!" << endl;
            insert(userString[0], userString[1], userString[2], userString[3], userNum);
        }
        else {
            cout << "This book is already in the inventory!" << endl;
        }
    }
    else {
        cout << "\nBook with ISBN: " << bookISBN << "\ndoes not exist." << endl;
    }
} // end updateQuantity

template <class elemType>
void bSearchTreeType<elemType>::deleteNode
(const elemType& deleteItem)
{
    nodeType<elemType>* current; //pointer to traverse the tree
    nodeType<elemType>* trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot delete from an empty tree."
        << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != nullptr && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (checkLesser(current->info, deleteItem))
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }//end while

        if (current == nullptr)
            cout << "The item to be deleted is not in the tree."
            << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (checkLesser(trailCurrent->info, deleteItem))
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        else
            cout << "The item to be deleted is not in the tree."
            << endl;
    }
} //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
(nodeType<elemType>*& p)
{
    nodeType<elemType>* current; //pointer to traverse the tree
    nodeType<elemType>* trailCurrent;  //pointer behind current
    nodeType<elemType>* temp;      //pointer to delete the node

    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist."
        << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;

        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == nullptr) //current did not move;
            //current == p->lLink; adjust p
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;

        delete current;
    }//end else
} //end deleteFromTree

template <typename T>
bool bSearchTreeType<T>::checkLesser(string str1, string str2) {
    // True = lLink
    // False = rLink

    int shortestLength = 0; // Length of the shortest string

    // Set shortestLength to the length of the shortest string
    if (str1.length() < str2.length()) {
        shortestLength = str1.length();
    }
    else {
        shortestLength = str2.length();
    }

    // Check the both strings for a character mismatch
    for (int i = 0; i < shortestLength; i++) {

        // Check if the string characters are the same (as lowercase)
        if (tolower(str1[i]) != tolower(str2[i])) {
            // Determine which string character is greater 
            return tolower(str1[i]) > tolower(str2[i]);  // (lowercase is higher than uppercase in hex)
        }
        // Check if the string characters are the same
        else if (str1[i] != str2[i]) {
            // Determine which character is lesser
            return str1[i] < str2[i];
        }
    }
    
    // By this point, the strings have the same characters, so length's are compared. Shorter string goes first.
    return str1.length() > str2.length();
}

template <class elemType>
void bSearchTreeType<elemType>::findBook(const bSearchTreeType<elemType>& p, nodeType<elemType>* specificBook) {
    cout << endl;
    if (specificBook == nullptr) {	// Confirm that the book exists
        cout << "This book is not in inventory." << endl;
    }
    else {  // Display the book's information
        cout << "Book Found!" << endl << "=================" << endl;
        p.printBook(specificBook);
    }
    cout << endl;
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByISBN (const elemType& searchItem) const { // Search the tree that contains the located IBSN.
	// Call the helper function searchISBN to search for the located ISBN.
	return searchISBN(this->root, searchItem);
}// searchByISBN

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchISBN (nodeType<elemType>* p, const elemType& searchItem) const{
	if(p == nullptr) // Check if the node is empty.
		return nullptr;
			
    // Base Case: Check the current node is equal to the located ISBN.
    if (p->ISBN == searchItem)
        return p;

	// Base Case: Traverse the left substree
	nodeType<elemType>* leftNode = searchISBN(p->lLink, searchItem);
	if(leftNode != nullptr)
		return leftNode;

	// Recursive Case: Traverse the right substree
	return searchISBN(p->rLink, searchItem);
}//end searchISBN

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByTitle(const elemType& searchItem) const { // Searchs the tree for the located title of the book.
    // Call the helper function searchTitle to nagivate for the title of the book.
    return searchTitle(this->root, searchItem);
}// searchByTitle

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchTitle(nodeType<elemType>* p, const elemType& searchItem) const { // A helper function that supports the searchByTitle function
    if (p == nullptr) // Check if the node is empty.
        return nullptr;

    // Base Case: Check the current node is equal to the located title.
    if (p->info == searchItem)
        return p;

    // Base Case: Traverse the left substree
    nodeType<elemType>* leftNode = searchTitle(p->lLink, searchItem);
    if (leftNode != nullptr)
        return leftNode;

    // Recursive Case: Traverse the right substree
    return searchTitle(p->rLink, searchItem);
}//end searchTitle

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByAuthor(const elemType& searchItem) const { // Searchs the tree for the author of the book.
    // Call the helper function searchAuthor to search for the author of the book.
    return searchAuthor(this->root, searchItem);
}// searchByAuthor

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchAuthor(nodeType<elemType>* p, const elemType& searchItem) const { // A helper function that supports the searchByAuthor function
    if (p == nullptr) // Check if the node is empty.
        return nullptr;

    // Base Case: Check the current node is equal to the located author.
    if (p->author == searchItem)
        return p;

    // Base Case: Traverse the left substree
    nodeType<elemType>* leftNode = searchAuthor(p->lLink, searchItem);
    if (leftNode != nullptr)
        return leftNode;

    // Recursive Case: Traverse the right substree
    return searchAuthor(p->rLink, searchItem);
}//end searchAuthor

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByGenre(const elemType& searchItem) const { // Finds the located genre of the book in the tree.
    // Call the helper function searchGenre to look for the genre of the book.
    return searchGenre(this->root, searchItem);
}// searchByGenre

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchGenre(nodeType<elemType>* p, const elemType& searchItem) const { // A helper function used to assist the searchByGenre function
    if (p == nullptr) // Check if the node is empty.
        return nullptr;

    // Base Case: Check the current node is equal to the located genre.
    if (p->genre == searchItem)
        return p;

    // Base Case: Traverse the left substree
    nodeType<elemType>* leftNode = searchGenre(p->lLink, searchItem);
    if (leftNode != nullptr)
        return leftNode;

    // Recursive Case: Traverse the right substree
    return searchGenre(p->rLink, searchItem);
}//end searchGenre

template <class elemType>
void bSearchTreeType<elemType>::showPopularGenres() {
    vector<genreType> genreList; // List of genres and the amount of books under them

    // Store the genres and their book counts in genreList
    genreList = getGenres(this->root, genreList);

    // Sort the vector based on highest to lowest book count by using the bubble sort algorithm 

    genreType temp; // Used for swapping

    for (int i = 0; i < genreList.size(); i++) { 
        // i is kept as a running count of passes through the vector to determine the amount of elements to be checked
        for (int j = 0; j < (genreList.size() - 1 - i); j++) { 
            // Check if the book count at the current j index is lesser than the book count at the next index
            if (genreList.at(j).bookCount < genreList.at(j + 1).bookCount) {
                // Swap the genreType's indexes.
                temp = genreList.at(j);
                genreList.at(j) = genreList.at(j + 1);
                genreList.at(j + 1) = temp;
            }
        }
    }

    // Display each book and their book count
    for (int i = 0; i < genreList.size(); i++) {
        cout << genreList.at(i).genre << " | Book Count: " << genreList.at(i).bookCount << endl;
    }
}

template <class elemType>
vector<genreType> bSearchTreeType<elemType>::getGenres(nodeType<elemType>* p, vector<genreType>& genreList) {
    if (p == nullptr) { // Base case
        return genreList; 
    }

    // Traverse left node
    getGenres(p->lLink, genreList);

    bool genreExists = false; 
    // Check if the genre of the node is within the vector already
    for (int i = 0; i < genreList.size(); i++) {
        // Increase the count of that genre if it exists within the vector
        if (genreList.at(i).genre == p->genre) { 
            genreList.at(i).bookCount++;
            genreExists = true; // Skip adding the genre to the vector
            break;
        }
    }

    // If the genre was not found within the vector, add it.
    if (!genreExists) {
        genreType newGenre;
        newGenre.genre = p->genre;
        newGenre.bookCount = 1;
        genreList.push_back(newGenre);
    }

    // Traverse right node
    getGenres(p->rLink, genreList);

    // Return the list of genres and their book counts
    return genreList;
}

template <class elemType>
void bSearchTreeType<elemType>::orderBook() {
    nodeType<elemType>* specificBook; // Specific book to be ordered
    string userISBN; // Input ISBN from the user
    int userInt;  // Input selection from the user

    cout << "Enter ISBN of book to place order for: ";
    cin.ignore();
    getline(cin, userISBN); // Store the ISBN 

    // Search for the book with its ISBN
    specificBook = this->searchByISBN(userISBN);

    if (specificBook != nullptr) { // Check if the book exists or not
        cout << "\nBook Found.\n";
        cout << "===================\n";

        this->printBook(specificBook); // Display the information of the book

        // Check with the user if they want to place an order for this book
        if (specificBook->quantity >= 1) {
            cout << "\nPlace an order for this book?" << endl;
            cout << "1) Yes  |  2) No  " << endl;
            cout << "Input a valid number: ";
            cin >> userInt;

            // Ensure valid input
            while (userInt < 1 || userInt > 2) {
                cout << "ERROR: Invalid choice." << endl;
                cout << "Input a valid number:";
                cin >> userInt;
            }

            switch (userInt) {
            case 1: // If user wants to place an order
                this->addToHistory(*specificBook); // Save the book's information in the order history
                specificBook->quantity--; // Decrement quantity by 1
                specificBook->sales++;    // Increase sales of book by 1
                this->incrementAllTotalSales();    // Increase total sales of bookstore by 1
                cout << "\nBook order placed!\n";
                break;
            case 2:
                cout << "\nOrder cancelled!" << endl;
                break;
            }
        }
        else {
            cout << "\nThe supply of this book is empty!" << endl;
        }
    }
    else {
        cout << "\nBook with ISBN: " << userISBN << "\ndoes not exist." << endl;
    }
}

#endif