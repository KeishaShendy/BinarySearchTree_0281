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

    // Fungsi untuk mengecek apakah pohon kosong
    bool isEmpty()
    {
        return ROOT == nullptr;
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

    // Fungsi inorder traversal: kiri → root → kanan
    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);     // Kiri
        cout << ptr->info << " ";    // Tampilkan data
        inorder(ptr->rightchild);    // Kanan
    }

    // Fungsi preorder traversal: root → kiri → kanan
    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr == nullptr)
            return;

        cout << ptr->info << " ";    // Tampilkan data
        preorder(ptr->leftchild);    // Kiri
        preorder(ptr->rightchild);   // Kanan
    }

    // Fungsi postorder traversal: kiri → kanan → root
    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr == nullptr)
            return;

        postorder(ptr->leftchild);    // Kiri
        postorder(ptr->rightchild);   // Kanan
        cout << ptr->info << " ";     // Tampilkan data (akhir)
    }
};

int main()
{
    BinaryTree x; // Membuat objek pohon

    while (true)
    {
        // Menu interaktif
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
            x.insert();                // Menyisipkan data
            break;
        case '2':
            x.inorder(x.ROOT);         // Traversal inorder
            cout << endl;
            break;
        case '3':
            x.preorder(x.ROOT);        // Traversal preorder
            cout << endl;
            break;
        case '4':
            x.postorder(x.ROOT);       // Traversal postorder
            cout << endl;
            break;
        case '5':
            return 0;                  // Keluar dari program
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
}
