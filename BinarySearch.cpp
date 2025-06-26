// BinarySearchTree_4NIMBelakang
// 15 Commit

#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for the node class
    Node()
    {
        leftchild = nullptr;  // Initialize left child to null
        rightchild = nullptr; // Initialize right child to null
    }
};
