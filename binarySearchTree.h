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
    void findBook(const bSearchTreeType<elemType>& p, nodeType<elemType>* specificBook);
    // Checks if the books exists in the inventory

    void isBookFound(const elemType& searchItem, const int& userInt, const int& count);
    // A function used to confirm if the book(s) under searchItem exist or not.

    nodeType<elemType>* searchByISBN(const elemType& searchItem) const;
    // A function to search for a book through the book's ISBN.

    nodeType<elemType>* searchByTitle(const elemType& searchItem);
    // Finds a book under the searchItem title in the inventory.

    void printByAuthor(const elemType& searchItem, int& count);
    // Prints book(s) under the same author in the inventory.

    void printByGenre(const elemType& searchItem, int& count);
    // A function to print books out that have same genre in the inventory.

    void addBook();
    // A function add a new book node

    void deleteNode(const elemType& deleteItem);
    //Function to delete deleteItem from the binary search tree
    //Postcondition: If a node with the same info as deleteItem
    //               is found, it is deleted from the binary
    //               search tree.
    //               If the binary tree is empty or deleteItem
    //               is not in the binary tree, an appropriate
    //               message is printed.

    void updateBook(const string& bookISBN);
    // A function to update a book's values (searching through the book's ISBN).

    void showPopularGenres();
    // A function to show genres within the inventory based off of their popularity

    void orderBook();
    // A function that let the user order a book

private:

    nodeType<elemType>* searchTitle(nodeType<elemType>* p, const elemType& searchItem);
    // A helper function to support the searchByTitle function.

    void printAuthor(nodeType<elemType>* p, const elemType& searchItem, int& count);
    // A helper function to print books under the same author in the printByAuthor function.

    void printGenre(nodeType<elemType>* p, const elemType& searchItem, int& count);
    // A helper function to assist the printByGenre function.

    nodeType<elemType>* searchISBN(nodeType<elemType>* p, const elemType& searchItem) const;
    // A helper function used to navigate where the located ISBN is in the entire tree.

    bool checkLesser(string str1, string str2);
    // Function to check for which string is lesser than the other
    // for alphabetical sorting purposes.

    void insert
    (const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity);
    //Function to insert insertItem in the binary search tree.
    //Postcondition: If there is no node in the binary search
    //               tree that has the same info as
    //               insertItem, a node with the info
    //               insertItem is created and inserted in the
    //               binary search tree.

    nodeType<elemType>* insertHelper 
    (nodeType<elemType>* p, const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity);
    // Helper function to insert an item into the tree

    int getHeight(const nodeType<elemType>* p) const;
    // A function to return the node's height.

    int getBalanceFactor(nodeType<elemType>* p);
    // A helper function used to return the node's balance factor.

    nodeType<elemType>* rotateRight(nodeType<elemType>* p);
    // A private function to rotate a current node to the right

    nodeType<elemType>* rotateLeft(nodeType<elemType>* p);
    // A private function to rotate a current node to the left

    nodeType<elemType>* balanceTree(nodeType<elemType>* p);
    // A function used to balance the nodes of a binary search tree.

    void deleteFromTree(nodeType<elemType>*& p);
    //Function to delete the node to which p points is
    //deleted from the binary search tree.
    //Postcondition: The node to which p points is deleted
    //               from the binary search tree.

    vector<genreType> getGenres(nodeType<elemType>* p, vector<genreType>& genreList);
    // A helper function to get genres within the inventory based off of their popularity

};

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
void bSearchTreeType<elemType>::isBookFound(const elemType& searchItem, const int& userInt, const int& count) { // Confirms if the books under searchItem exist or not.
    string searchCategory; // Stores the search category used to search book(s) under searchItem.

    switch (userInt) {
    case 1: // Store "with title" into searchCategory.
        searchCategory = "with title";
        break;
    case 2: // Store "author" into searchCategory.
        searchCategory = "under author(s)";
        break;
    case 3: // Store "genre" into searchCategory.
        searchCategory = "by genre";
        break;
    }


    // Check if the book(s) under the which search category exist in the inventory.
    if (count == 0) {
        cout << "There are no book(s) " << searchCategory << " " << searchItem << " in the inventory." << endl;
    }
    else {
        cout << "There exists " << count << " book(s) " << searchCategory << " " << searchItem << " in the inventory" << endl;
    }
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByTitle(const elemType& searchItem) { // Search the tree that contains the located Title.
    // Call the helper function searchTitle to search for the located Title.
    return searchTitle(this->root, searchItem);
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchTitle(nodeType<elemType>* p, const elemType& searchItem) {
    if (p == nullptr) // Check if the node is empty.
        return nullptr;

    // Base Case: Check the current node is equal to the located ISBN.
    if (p->info == searchItem)
        return p;

    if (checkLesser(p->info, searchItem)) {
        return searchTitle(p->lLink, searchItem);
    }
    else {
        return searchTitle(p->rLink, searchItem);
    }

}//end searchTitle

template <class elemType>
void bSearchTreeType<elemType>::printByAuthor(const elemType& searchItem, int& count) { // Prints book(s) under the same author in the inventory.
    count = 0; // Set count to 0.

    // Call the helper function printAuthor
    printAuthor(this->root, searchItem, count);
}

template <class elemType>
void bSearchTreeType<elemType>::printAuthor(nodeType<elemType>* p, const elemType& searchItem, int& count) {
    bSearchTreeType<elemType> books;

    // Check if the node is empty.
    if (p != nullptr) {
        // Traverse the left subtree.
        printAuthor(p->lLink, searchItem, count);

        // If the book's author is equal to searchItem, print out that book.
        if (p->author == searchItem) {
            cout << "Book Found!" << endl << "=================" << endl;
            books.printBook(p);
            cout << endl;
            count++; // Increment count by 1.
        }

        // Traverse the right substree.
        printAuthor(p->rLink, searchItem, count);
    }
}

template <class elemType>
void bSearchTreeType<elemType>::printByGenre(const elemType& searchItem, int& count) { // Print(s) books out that have same genre in the inventory.
    count = 0; // Set count to 0.

    // Call the helper function printGenre
    printGenre(this->root, searchItem, count);
}

template <class elemType>
void bSearchTreeType<elemType>::printGenre(nodeType<elemType>* p, const elemType& searchItem, int& count) {
    bSearchTreeType<elemType> books;

    // Check if the node is empty.
    if (p != nullptr) {
        // Traverse the left subtree.
        printGenre(p->lLink, searchItem, count);

        // If the book's genre is equal to searchItem, print out that book.
        if (p->genre == searchItem) {
            cout << "Book Found!" << endl << "=================" << endl;
            books.printBook(p);
            cout << endl;
            count++; // Increment count by 1.
        }

        // Traverse the right substree.
        printGenre(p->rLink, searchItem, count);
    }
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchByISBN(const elemType& searchItem) const { // Search the tree that contains the located IBSN.
    // Call the helper function searchISBN to search for the located ISBN.
    return searchISBN(this->root, searchItem);
}// searchByISBN

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::searchISBN(nodeType<elemType>* p, const elemType& searchItem) const {
    if (p == nullptr) // Check if the node is empty.
        return nullptr;

    // Base Case: Check the current node is equal to the located ISBN.
    if (p->ISBN == searchItem)
        return p;

    // Base Case: Traverse the left substree
    nodeType<elemType>* leftNode = searchISBN(p->lLink, searchItem);
    if (leftNode != nullptr)
        return leftNode;

    // Recursive Case: Traverse the right substree
    return searchISBN(p->rLink, searchItem);
}//end searchISBN

template <class elemType>
void bSearchTreeType<elemType>::addBook() {
    // userString[0] = title, userString[1] = author, userString[2] = genre, userString[3] = ISBN, userNum = quantity
    int userNum = 0;         
    string userString[4];       

    // Get input from the user
    this->setInfo(userString[0], userString[1], userString[2], userString[3], userNum);

    if (searchByISBN(userString[3]) != nullptr || searchByTitle(userString[0]) != nullptr) {
        cout << "This book is already in the inventory!" << endl;
        return;
    }
    // Create a new node from the user input
    insert(userString[0], userString[1], userString[2], userString[3], userNum);
    cout << "Book added!" << endl;
}

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
void bSearchTreeType<elemType>::insert
(const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity)
{
    this->root = insertHelper(this->root, insertTitle, insertAuthor, insertGenre, insertISBN, insertQuantity);
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::insertHelper
(nodeType<elemType>* p, const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity)
{
    
    // Base Case (if the current node being pointed at is nllptr, either the root or at the end of a path)
    if (p == nullptr) {
        // Create the new node
        nodeType<elemType>* newNode = new nodeType<elemType>;

        newNode->info = insertTitle;     // Set the new book's title
        newNode->author = insertAuthor; // Set the new book's author
        newNode->genre = insertGenre;   // Set the new book's genre
        newNode->ISBN = insertISBN;     // Set the new book's ISBN
        newNode->quantity = insertQuantity; // Set the quantity of this book
        newNode->lLink = nullptr;
        newNode->rLink = nullptr;

        // Return the new node
        return newNode;
    }

    // Ensure the book is not already in the inventory
    if (p->ISBN == insertISBN || p->info == insertTitle) {
        cout << "ERROR: No Duplicate Books are Allowed" << endl;
        return p;
    }
  
    // Determine where to put the newNode
    if (checkLesser(p->info, insertTitle)) {
        // If the title goes alphabetically before the current node's title, go to the lLink
        p->lLink = insertHelper(p->lLink, insertTitle, insertAuthor, insertGenre, insertISBN, insertQuantity);
    }
    else {
        // If the title goes alphabetically after the current node's title, go to the rLink
        p->rLink = insertHelper(p->rLink, insertTitle, insertAuthor, insertGenre, insertISBN, insertQuantity);
    }

    // Make sure that each node's balance factor is correct, and that the tree is balanced
    return balanceTree(p);

}//end insert

template <class elemType>
int bSearchTreeType<elemType>::getHeight(const nodeType<elemType>* p) const { // returns the node's height.
    // Check if the node is empty first.
    if (p == nullptr)
        return -1;

    return p->height;
}

template <class elemType>
int bSearchTreeType<elemType>::getBalanceFactor(nodeType<elemType>* p) { // Returns the node's balance factor.
    // Check if the node is empty.
    if (p == nullptr) {
        return 0;
    }

    return (getHeight(p->lLink) - getHeight(p->rLink));
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::rotateRight(nodeType<elemType>* p) {
    nodeType<elemType>* leftNode = p->lLink;                // Node that will become the new parent
    nodeType<elemType>* childRightNode = leftNode->rLink;   // Node that will become the new lLink of leftNode (if it exists)

    // Rotate the nodes
    leftNode->rLink = p;        // Set the left node's (the new parent) rLink to point to p (the previous parent)
    p->lLink = childRightNode;  // Set the rLink of the leftNode to become the lLink of the leftNode (if it exists)

    // Update height for each node
    p->height = 1 + max(getHeight(p->lLink), getHeight(p->rLink));  // Determine the height of the rLink of leftNode
    leftNode->height = 1 + max(getHeight(leftNode->lLink), getHeight(leftNode->rLink)); // determine the height of leftNode

    return leftNode;    // Return the new parent, leftNode
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::rotateLeft(nodeType<elemType>* p) {
    nodeType<elemType>* rightNode = p->rLink;   // Node that will become the new parent 
    nodeType<elemType>* childLeftNode = rightNode->lLink;   // Node that will become the new lLink of leftNode (if it exists)

    // Rotate the nodes
    rightNode->lLink = p;       // Set the right node's (new parent) lLink to point to p (previous parent)
    p->rLink = childLeftNode;   // Set the lLink of the rightNode to become the rLink of the rightNode (if it exists)

    // Update height for each node
    p->height = 1 + max(getHeight(p->lLink), getHeight(p->rLink));  // Determine the height of the lLink of rightNode
    rightNode->height = 1 + max(getHeight(rightNode->lLink), getHeight(rightNode->rLink));  // determine the height of rightNode

    return rightNode;       // Return the new parent, rightNode
}

template <class elemType>
nodeType<elemType>* bSearchTreeType<elemType>::balanceTree(nodeType<elemType>* p) { // A function used to balance the nodes of a binary search tree.
    if (p == nullptr) {    // Base case
        return p;
    }

    // Set the height of the current node to be the maximum of the heights of either lLink or rLink
    p->height = 1 + max(getHeight(p->lLink), getHeight(p->rLink));

    // Determine the balancing factor of the current node
    int balanceFactor = getBalanceFactor(p);

    // If the balanceFactor is greater than 1, perform a right rotation.
    if (balanceFactor > 1) {
        // Perform a left-right rotation if the node's left subtree's balanceFactor is less than 0.
        if (getBalanceFactor(p->lLink) < 0) {
            p->lLink = rotateLeft(p->lLink);

        }
        return rotateRight(p);
    }

    // If the balanceFactor is less than -1, perform a left rotation.
    else if (balanceFactor < -1) {
        // Perform a right-left rotation if the node's right subtree's balanceFactor is greater than 0.
        if (getBalanceFactor(p->rLink) > 0) {
            p->rLink = rotateRight(p->rLink);
        }
        return rotateLeft(p);
    }

    return p;
}

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

template <class elemType>
void bSearchTreeType<elemType>::updateBook(const string& bookISBN) { // A function to update the book's quantity.
    int userNum = 0;            // Input integer from the user
    string userString[4];       // Input strings from the user
    nodeType<elemType>* specificBookISBN = searchByISBN(bookISBN); // Assign specificBook with a book that contains the same ISBN as bookISBN 

    if (specificBookISBN != nullptr) { // Check if the book exists or not

        cout << "Book Found. Please enter new information." << endl;

        this->setInfo(userString[0], userString[1], userString[2], userString[3], userNum);
        
        // Check if the new ISBN and Title are not copies of already existing ISBN and titles (seperate from the node being updated)
        if ((searchByISBN(userString[3]) == nullptr || userString[3] == specificBookISBN->ISBN) && 
            (searchByTitle(userString[0]) == nullptr || userString[0] == specificBookISBN->info)) {

            // Delete the book specified by the ISBN (Resets the book's sales by default, but sales are still kept in totalSales)
            deleteNode(specificBookISBN->info);

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
