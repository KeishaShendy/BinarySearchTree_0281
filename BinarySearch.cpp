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

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Menginisialisasi ROOT ke null
    }

    void insert()
    {
        int x;
        cout << "Masukan nilai: ";
        cin >> x;

        // Langkah 1: Alokasikan memori untuk node baru
        Node *newNode = new Node();

        // Langkah 2: Isi nilai data pada node baru
        newNode->info = x;

        // Langkah 3: Set anak kiri dan kanan dari node baru ke NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // Langkah 4: Temukan node yang akan menjadi parent dari node yang akan disisipkan
        Node *parent = nullptr;
        Node *currentNode = nullptr;
