#include <iostream>
using namespace std;

// Node cho linked list trong moi bucket
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// HashTable voi separate chaining, size co the thay doi
class HashTable {
private:
    int tableSize;   // kich thuoc table co the thay doi
    Node** table;    // mang con tro den linked list

    // ham hash O(1)
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // constructor, truyen size vao, khoi tao O(tableSize)
    HashTable(int size) {
        tableSize = size;
        table = new Node * [tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }

    // ------------------------
    // chen key vao table
    // Avg: O(1), Worst: O(n_bucket)
    // ------------------------
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index]; // them dau bucket
        table[index] = newNode;
    }

    // ------------------------
    // tim kiem key
    // Avg: O(1), Worst: O(n_bucket)
    // ------------------------
    bool search(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    // ------------------------
    // xoa key
    // Avg: O(1), Worst: O(n_bucket)
    // ------------------------
    void remove(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return; // khong tim thay
        if (!prev) table[index] = curr->next;
        else prev->next = curr->next;
        delete curr;
    }

    // ------------------------
    // in table
    // O(n) voi n la tong so key
    // ------------------------
    void printTable() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << "->";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

// ------------------------
// test HashTable
// ------------------------
int main() {
    HashTable ht(15); // tao table voi 15 bucket

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    cout << "Hash Table:\n";
    ht.printTable();

    cout << "\nSearch 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.remove(20);
    cout << "\nAfter removing 20:\n";
    ht.printTable();

    return 0;
}
