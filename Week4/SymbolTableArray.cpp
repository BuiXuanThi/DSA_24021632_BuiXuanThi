//#include <iostream>
//using namespace std;
////=================IMPLEMENT SYMBOLTABLE WITH ARRAY========//
//const int MAXN = 100;
//
//// Struct luu mot cap key-value
//struct Symbol {
//    int key;
//    string value;
//};
//
//class SymbolTable {
//private:
//    Symbol table[MAXN];
//    int n; // so luong phan tu hien co
//
//public:
//    SymbolTable() {
//        n = 0;
//    }
//
//    // Them moi hoac cap nhat
//    void put(int key, string value) {
//        // Neu key da ton tai -> cap nhat value
//        for (int i = 0; i < n; i++) {
//            if (table[i].key == key) {
//                table[i].value = value;
//                return;
//            }
//        }
//
//        // Neu chua ton tai -> them moi
//        if (n < MAXN) {
//            table[n].key = key;
//            table[n].value = value;
//            n++;
//        }
//        else {
//            cout << "Bang da day, khong the them!\n";
//        }
//    }
//
//    // Lay gia tri tu key
//    string get(int key) {
//        for (int i = 0; i < n; i++) {
//            if (table[i].key == key)
//                return table[i].value;
//        }
//        return "Khong tim thay key!";
//    }
//
//    // Xoa mot key
//    void remove(int key) {
//        for (int i = 0; i < n; i++) {
//            if (table[i].key == key) {
//                // Dich trai cac phan tu sau no
//                for (int j = i; j < n - 1; j++) {
//                    table[j] = table[j + 1];
//                }
//                n--;
//                return;
//            }
//        }
//        cout << "Khong tim thay key de xoa!\n";
//    }
//
//    // Kiem tra key ton tai
//    bool contains(int key) {
//        for (int i = 0; i < n; i++) {
//            if (table[i].key == key)
//                return true;
//        }
//        return false;
//    }
//
//    // Lay so luong phan tu
//    int size() {
//        return n;
//    }
//
//    // In ra tat ca cap key-value
//    void print() {
//        cout << "Noi dung Symbol Table:\n";
//        for (int i = 0; i < n; i++) {
//            cout << table[i].key << " -> " << table[i].value << endl;
//        }
//    }
//};
////================MAINTEST===============//
//int main() {
//    SymbolTable st;
//    st.put(1, "apple");
//    st.put(2, "banana");
//    st.put(3, "cherry");
//    st.put(2, "blueberry"); // cap nhat key 2
//
//    st.print();
//
//    cout << "Gia tri cua key 3: " << st.get(3) << endl;
//
//    st.remove(1);
//    st.print();
//
//    cout << "Co key 1 khong? " << (st.contains(1) ? "Co" : "Khong") << endl;
//}
