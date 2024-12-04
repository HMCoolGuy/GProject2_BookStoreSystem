//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

//Definition of the Node
template <class elemType>
struct nodeType
{
    // Each node in this binary search tree will represent a singular book in the inventory

    string info; // This will be the title of the book
    string author; // Author of the book
    string genre; // Genre of the book
    string ISBN; // ISBN of the book
    int quantity; // Quantity of book in the store
    int sales = 0;  // Amount of times a book has been sold
    int height = 0; // The height of a node in the binary tree

    nodeType<elemType>* lLink;
    nodeType<elemType>* rLink;
};

// Variable type that holds a genre and the amount of books under it
struct genreType {
    string genre;
    int bookCount;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
        (const binaryTreeType<elemType>&);
    //Overload the assignment operator.

    bool isEmpty() const;
    //Function to determine whether the binary tree is empty.
    //Postcondition: Returns true if the binary tree is empty;
    //               otherwise, returns false.

    void inorderTraversal() const;
    //Function to do an inorder traversal of the binary tree.
    //Postcondition: Nodes are printed in inorder sequence.

    void preorderTraversal() const;
    //Function to do a preorder traversal of the binary tree.
    //Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
    //Function to do a postorder traversal of the binary tree.
    //Postcondition: Nodes are printed in postorder sequence.

    int treeHeight() const;
    //Function to determine the height of a binary tree.
    //Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
    //Function to determine the number of nodes in a 
    //binary tree.
    //Postcondition: Returns the number of nodes in the 
    //               binary tree.

    int treeLeavesCount() const;
    //Function to determine the number of leaves in a 
    //binary tree.
    //Postcondition: Returns the number of leaves in the 
    //               binary tree.

    void destroyTree();
    //Function to destroy the binary tree.
    //Postcondition: Memory space occupied by each node 
    //               is deallocated.
    //               root = nullptr;

    virtual bool search(const elemType& searchItem) const = 0;
    //Function to determine if searchItem is in the binary 
    //tree.
    //Postcondition: Returns true if searchItem is found in 
    //               the binary tree; otherwise, returns 
    //               false.

    virtual void insert
    (const string& insertTitle, const string& insertAuthor, const string& insertGenre, const string& insertISBN, const int& insertQuantity) = 0;
    //Function to insert insertItem in the binary tree.
    //Postcondition: If there is no node in the binary tree
    //               that has the same info as insertItem, a
    //               node with the info insertItem is created
    //               and inserted in the binary search tree.

    virtual void deleteNode(const elemType& deleteItem) = 0;
    //Function to delete deleteItem from the binary tree 
    //Postcondition: If a node with the same info as 
    //               deleteItem is found, it is deleted from
    //               the binary tree.
    //               If the binary tree is empty or 
    //               deleteItem is not in the binary tree, 
    //               an appropriate message is printed.

    void setInfo
    (string& userTitle, string& userAuthor, string& userGenre, string& userISBN, int& userNum);
    // A function to get a new title, author, genre, ISBN, and quantity from the user

    void printBook(nodeType<elemType>* p) const;
    // Function to print a given book node's information
    // (Title, Author, Genre, ISBN, and Quantity).

    void addToHistory(nodeType<elemType> p);
    // Function to add a book to the order history

    void displayHistory();
    // Function to display the order history

    int getBookTotal() const;
    // Function to return the total amount of books within the inventory

    void incrementAllTotalSales();
    // Function to increment the total sales

    int getAllSalesTotal() const;
    // Function to return the total amount of sales made

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    //Copy constructor

    binaryTreeType();
    //Default constructor

    ~binaryTreeType();
    //Destructor

protected:
    nodeType<elemType>* root;

private:
    vector<nodeType<elemType>> orderHistory;      // Vector for keeping track of orders
    int totalSales = 0; // Keeps track of total sales made

    void copyTree(nodeType<elemType>*& copiedTreeRoot,
        nodeType<elemType>* otherTreeRoot);
    //Makes a copy of the binary tree to which 
    //otherTreeRoot points. 
    //Postcondition: The pointer copiedTreeRoot points to
    //               the root of the copied binary tree.

    void destroy(nodeType<elemType>*& p);
    //Function to destroy the binary tree to which p points. 
    //Postcondition: Memory space occupied by each node, in 
    //               the binary tree to which p points, is 
    //               deallocated.
    //               p = nullptr;

    void inorder(nodeType<elemType>* p) const;
    //Function to do an inorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in inorder sequence.

    void preorder(nodeType<elemType>* p) const;
    //Function to do a preorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in preorder 
    //               sequence.

    void postorder(nodeType<elemType>* p) const;
    //Function to do a postorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in postorder 
    //               sequence.

    int height(nodeType<elemType>* p) const;
    //Function to determine the height of the binary tree
    //to which p points. 
    //Postcondition: Height of the binary tree to which 
    //               p points is returned.

    int max(int x, int y) const;
    //Function to determine the larger of x and y.
    //Postcondition: Returns the larger of x and y.

    int nodeCount(nodeType<elemType>* p) const;
    //Function to determine the number of nodes in 
    //the binary tree to which p points. 
    //Postcondition: The number of nodes in the binary 
    //               tree to which p points is returned.

    int leavesCount(nodeType<elemType>* p) const;
    //Function to determine the number of leaves in  
    //the binary tree to which p points 
    //Postcondition: The number of leaves in the binary 
    //               tree to which p points is returned.

    int traverseBookTotal(nodeType<elemType>* p) const;
    // Helper function of getBookTotal that returns a running count of all book quantities.

};

//Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
(nodeType<elemType>*& copiedTreeRoot,
    nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder
(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        // Each node represents a book, so all nodes will be printed out alphabetically

        // Go to the left node in the tree
        inorder(p->lLink);
        // Print the book
        printBook(p);
        // Go to the right node in the tree
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder
(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        cout << p->info << " " << endl;
        preorder(p->lLink);
        preorder(p->rLink);
    }
}


template <class elemType>
void binaryTreeType<elemType>::postorder
(nodeType<elemType>* p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
            //destroy the binary tree
            destroy(root);

        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this;
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>*& p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

//Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height
(nodeType<elemType>* p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const
{
    if (p == nullptr)
        return 0;
    else
        if (p->lLink == nullptr && p->rLink == nullptr)
            return 1;
        else
            return leavesCount(p->lLink) + leavesCount(p->rLink);
}

template <class elemType>
void binaryTreeType<elemType>::setInfo // Function that gets new book info from the user
(string& userTitle, string& userAuthor, string& userGenre, string& userISBN, int& userNum) {

    cout << "Enter Title of Book: ";
    getline(cin, userTitle); // Store the title within index 0 of userString

    cout << "Enter Book Author: ";
    getline(cin, userAuthor); // Store the author within index 1 of userString

    cout << "Enter Book Genre: ";
    getline(cin, userGenre); // Store the genre within index 2 of userString

    cout << "Enter Book's ISBN: ";
    getline(cin, userISBN); // Store the ISBN within index 3 of userString

    while (userISBN.length() != 10 && userISBN.length() != 13) { // Check if the length of the ISBN is valid.
        // Call the helper function searchByISBN
        cout << "ERROR: Invalid ISBN (Must be 10 or 13 characters)" << endl;
        cout << "Enter Book's ISBN: ";
        getline(cin, userISBN); // Store the ISBN within index 3 of userString
    }

    cout << "Enter Book Quantity: ";
    cin >> userNum;				 // Store the quantity of the book within userString

    // Ensure that the capacity is valid
    while (userNum < 0) {
        cout << "ERROR: Invalid Quantity (Must be a positive integer)" << endl;
        cout << "Enter Book Quantity: ";
        cin.ignore();
        cin >> userNum;				 // Store the quantity of the book within userString
    }
}

template<class elemType>
void binaryTreeType<elemType>::printBook(nodeType<elemType>* p) const {
    // Print the book title
    cout << p->info << " | ";
    // Print the book author
    cout << "Author(s): " << p->author << " | ";
    // Print the book genre
    cout << "Genre: " << p->genre << " | ";
    // Print the book ISBN
    cout << "ISBN: " << p->ISBN << " | ";
    // Print the quantity of the book
    cout << "Quantity: " << p->quantity << " | ";
    // Print the quantity of the book
    cout << "Sales: " << p->sales << endl;
}

template<class elemType>
void binaryTreeType<elemType>::addToHistory(nodeType<elemType> p) {
    orderHistory.push_back(p); // Add a book's info (its info before it is ordered) to the orderHistory
}

template<class elemType>
void binaryTreeType<elemType>::displayHistory() {

    // Check if any orders have been places
    if (orderHistory.size() == 0) {
        cout << "No orders have been placed yet.";
    }
    else {
        // Traverse the list from most to least recent orders
        for (int i = (orderHistory.size() - 1); i >= 0; i--) {
            this->printBook(&orderHistory.at(i));
        }
    }

    cout << "\n\n";
}

// Function that returns the total amount of books within the inventory
template<class elemType>
int binaryTreeType<elemType>::getBookTotal() const {
    return traverseBookTotal(this->root); // Use recursive helper function to traverse the list for each quantity
}

template<class elemType>
int binaryTreeType<elemType>::traverseBookTotal(nodeType<elemType>* p) const { // Helper function
    if (p == nullptr) { // Base case
        return 0;
    }
    // Traverse the list and return the total sum of each quantity
    return p->quantity + traverseBookTotal(p->lLink) + traverseBookTotal(p->rLink);
}

template<class elemType>
void binaryTreeType<elemType>::incrementAllTotalSales() {
    totalSales++; // Increment all total sales by 1
}

template<class elemType>
int binaryTreeType<elemType>::getAllSalesTotal() const {
    return totalSales;
}



#endif
