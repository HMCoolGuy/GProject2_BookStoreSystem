//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <string>
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

private:
    void deleteFromTree(nodeType<elemType>*& p);
    //Function to delete the node to which p points is
    //deleted from the binary search tree.
    //Postcondition: The node to which p points is deleted
    //               from the binary search tree.

    bool checkLesser(string str1, string str2);
    // Function to check for which string is lesser than the other
    // for alphabetical sorting purposes.
};


template <class elemType>
bool bSearchTreeType<elemType>::search
(const elemType& searchItem) const
{
    nodeType<elemType>* current;
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot search an empty tree." << endl;
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
            // TODO: lowercase a and uppercase A are now put together, but in no particular order. 
            // unsure if lowercase should come before uppercase

            // Iterate through each character of both the string
            if (checkLesser(current->info, insertTitle)) { // current node string < insertTitle
                // If character of mismatch goes first, then traverse to the left
                current = current->lLink;
            }
            else {
                // If character goes afterward, traverse right
                current = current->rLink;
            }
        }//end while

        if (checkLesser(trailCurrent->info, insertTitle)) { // last node string < insertTitle
            // if character of mismatch goes first, point lLink of previous node to the new node
            trailCurrent->lLink = newNode;
        }
        else {
            // if the character goes afterward, point rLink of previous node to the new node
            trailCurrent->rLink = newNode;
        }

    }
}//end insert

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

                if (current->info > deleteItem)
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
            else if (trailCurrent->info > deleteItem)
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
 
    // TODO: Uppercase letters are sorted correctly, but if lowercase letters (such as c) are inserted after
    // Upper case letters (A and Z), c is placed at the end.
    for (int i = 0; i < shortestLength; i++) { // Make sure that each character is the same
        if (str1[i] != str2[i]) {
            // If there is a mismatch, check to see if both are the same letter
            if (tolower(str1[i]) == tolower(str2[i])) {
                // if str1 character is lowercase, it goes first. otherwise, it goes afterward
                return str1[i] < str2[i];
            }
            else {
                // if str1 character is higher (in hex), it , otherwise pick right node

                return str1[i] > str2[i];
            }
        }
    }
    // By this point, the strings have the same characters, so length's are compared to put shortest first
    return str1.length() > str2.length();
}
#endif
