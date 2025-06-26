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
        search(x, parent, currentNode); // Pastikan fungsi search() tersedia

        // Step 5: Jika parent adalah NULL (berarti pohon masih kosong)
        if (parent == nullptr)
        {
            ROOT = newNode; // 5a: Jadikan newNode sebagai ROOT
            return;         // 5b: Selesai
        }

        // Step 6: Jika nilai data node baru lebih kecil dari parent
        if (x < parent->info)
        {
            parent->leftchild = newNode; // 6a
            return;                      // 6b
        }

        // Step 7: Jika nilai data node baru lebih besar dari parent
        else if (x > parent->info)
        {
            parent->rightchild = newNode; // 7a
            return;                       // 7b
        }
    }

    // Fungsi pencarian posisi parent dan node (wajib ditambahkan)
    void search(int x, Node *&parent, Node *&current)
    {
        current = ROOT;
        parent = nullptr;

        while (current != nullptr && current->info != x)
        {
            parent = current;
            if (x < current->info)
                current = current->leftchild;
            else
                current = current->rightchild;
        }
    }
};
 // Fungsi untuk mencari parent dan posisi node saat menyisipkan
void search(int x, Node *&parent, Node *&current)
{
    current = ROOT;
    parent = nullptr;

    while (current != nullptr && current->info != x)
    {
        parent = current;
        if (x < current->info)
            current = current->leftchild;
        else
            current = current->rightchild;
    }
}
