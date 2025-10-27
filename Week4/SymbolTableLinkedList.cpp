#include <iostream>
using namespace std;
//===============IMPLEMENT SYMBOLTABLE WITH LL===============//
// Struct Symbol cho mot node
struct Symbol {
    int key;
    string value;
    Symbol* next;
};

class SymbolTable {
private:
    Symbol* head; // dau danh sach

public:
    SymbolTable() {
        head = nullptr;
    }

    // Them hoac cap nhat mot cap key-value
    void put(int key, string value) {
        Symbol* curr = head;
        while (curr) {
            if (curr->key == key) {
                curr->value = value; // cap nhat gia tri
                return;
            }
            curr = curr->next;
        }
        // Neu chua ton tai -> them moi vao dau danh sach
        Symbol* node = new Symbol{ key, value, head };
        head = node;
    }

    // Lay gia tri tu key
    string get(int key) {
        Symbol* curr = head;
        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }
        return "Khong tim thay key!";
    }

    // Xoa mot key
    void remove(int key) {
        Symbol* curr = head;
        Symbol* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next;
                }
                else {
                    head = curr->next; // xoa dau
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Khong tim thay key de xoa!\n";
    }

    // Kiem tra key ton tai
    bool contains(int key) {
        Symbol* curr = head;
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    // In ra tat ca
    void print() {
        cout << "Noi dung Symbol Table:\n";
        Symbol* curr = head;
        while (curr) {
            cout << curr->key << " -> " << curr->value << endl;
            curr = curr->next;
        }
    }
    int size() {
        int count = 0;
        Symbol* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }




    // Huy tat ca node khi xoa SymbolTable
    ~SymbolTable() {
        Symbol* curr = head;
        while (curr) {
            Symbol* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
};

// ================ Test ==================//
int main() {
    SymbolTable st;
    st.put(1, "apple");
    st.put(2, "banana");
    st.put(3, "cherry");
    st.put(2, "blueberry"); // cap nhat key 2

    st.print();

    cout << "Gia tri cua key 3: " << st.get(3) << endl;

    st.remove(1);
    st.print();

    cout << "Co key 1 khong? " << (st.contains(1) ? "Co" : "Khong") << endl;
}
