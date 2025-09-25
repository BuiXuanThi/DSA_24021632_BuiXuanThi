#include "List.h"
#include<iostream>

using namespace std;

// ======= Class Stack =======
class Stack {
private:
    List ls; // List dung lam noi luu tru phan tu

public:
    // Kiem tra stack rong
    // Time complexity: O(1)
    bool isEmpty() const {
        return ls.isEmpty();
    }

    // Lay so luong phan tu trong stack
    // Time complexity: O(1)
    int size() const {
        return ls.getSize();
    }

    // Them phan tu vao dinh stack
    // Time complexity: O(1)
    bool push(int x) {
        return ls.insertTailList(x);
    }

    // Lay va xoa phan tu o dinh stack
    // Time complexity: O(1) (voi List mang, deleteTail chi giam size)
    int pop() {
        if (ls.isEmpty()) return INT_MIN;            // stack rong
        int val = ls.getElement(ls.getSize() - 1);   // lay gia tri cuoi
        ls.deleteAtTail();                           // giam size di 1
        return val;                                  // tra ve gia tri
    }

    // Xem phan tu o dinh stack ma khong xoa
    // Time complexity: O(1)
    int top() const {
        if (ls.isEmpty()) return INT_MIN;            // stack rong
        return ls.getElement(ls.getSize() - 1);      // lay gia tri cuoi
    }
};

// ======= Main test Stack =======
int main() {
    Stack st;

    cout << "Stack co dang rong: " << (st.isEmpty() ? "Yes" : "No") << endl;

    // Them phan tu vao stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Size = " << st.size() << endl; // 3
    cout << "Top = " << st.top() << endl;   // 30

    // Lay va xoa phan tu
    cout << "Pop = " << st.pop() << endl;   // 30
    cout << "Pop = " << st.pop() << endl;   // 20

    cout << "Size = " << st.size() << endl; // 1
    cout << "Top = " << st.top() << endl;   // 10

    // Xoa het phan tu
    cout << "Pop = " << st.pop() << endl;   // 10
    cout << "Pop = " << st.pop() << endl;   // INT_MIN, stack rong

    cout << "Stack rong co dang rong: " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}