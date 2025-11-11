#include <iostream>
using namespace std;

class HashTableLP {
private:
    int tableSize;     // kich thuoc bang bam
    int* table;        // mang chua key
    int* state;        // trang thai cua moi o: 0=EMPTY, 1=OCCUPIED, 2=DELETED
    const int EMPTY = -1; // gia tri NULL cho key

    // ham bam O(1)
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // ------------------------
    // constructor O(n)
    // ------------------------
    HashTableLP(int size) {
        tableSize = size;
        table = new int[tableSize];
        state = new int[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = EMPTY;
            state[i] = 0; // EMPTY
        }
    }

    // ------------------------
    // chen key voi Linear Probing
    // Avg: O(1), Worst: O(tableSize)
    // ------------------------
    void insert(int key) {
        int index = hashFunction(key);
        int start = index;

        // tim vi tri hop le: o EMPTY hoac DELETED
        while (state[index] == 1) { // 1 = OCCUPIED
            index = (index + 1) % tableSize;
            if (index == start) {
                cout << "Bang bam day, khong chen duoc key " << key << endl;
                return;
            }
        }

        table[index] = key;
        state[index] = 1; // danh dau da bi chiem
    }

    // ------------------------
    // tim kiem key
    // Avg: O(1), Worst: O(tableSize)
    // ------------------------
    bool search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (state[index] != 0) { // con ton tai o bi chiem hoac bi xoa
            if (state[index] == 1 && table[index] == key)
                return true; // tim thay
            index = (index + 1) % tableSize;
            if (index == start) break; // quay lai ban dau
        }
        return false;
    }

    // ------------------------
    // xoa key (lazy deletion)
    // Avg: O(1), Worst: O(tableSize)
    // ------------------------
    void remove(int key) {
        int index = hashFunction(key);
        int start = index;

        while (state[index] != 0) { // con ton tai o bi chiem hoac bi xoa
            if (state[index] == 1 && table[index] == key) {
                state[index] = 2;   // danh dau DELETED
                table[index] = EMPTY;
                return;
            }
            index = (index + 1) % tableSize;
            if (index == start) break;
        }
    }

    // ------------------------
    // in bang bam O(n)
    // ------------------------
    void printTable() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            if (state[i] == 1)       cout << table[i];
            else if (state[i] == 2)  cout << "(deleted)";
            cout << endl;
        }
    }

    // destructor
    ~HashTableLP() {
        delete[] table;
        delete[] state;
    }
};

// ------------------------
// test Linear Probing
// ------------------------
int main() {
    HashTableLP ht(10);

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(15);
    ht.insert(25);

    cout << "Bang bam sau khi chen:\n";
    ht.printTable();

    cout << "\nSearch 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;

    ht.remove(20);
    cout << "\nSau khi xoa 20:\n";
    ht.printTable();

    // chen lai key moi de kiem tra tai su dung o xoa
    ht.insert(40);
    cout << "\nSau khi chen 40 (tai su dung o xoa neu co):\n";
    ht.printTable();

    return 0;
}
