#include<iostream>
#include"SinglyLinkedList.h"

using namespace std;
//----------------IMPLEMENT STACK------------
class Stack {
private:
    SingleLinkedList ll;
public:
    bool isEmpty() {
        return ll.getSize() == 0;
    }

    void push(int x) {
        ll.insertAtHead(x);
    }

    int pop() {
        if (isEmpty()) return INT_MIN;    // stack rong
        int val = ll.getElementAt(0);     // lay gia tri dinh
        ll.deleteAtHead();                // xoa dinh
        return val;                        // tra gia tri vua pop
    }

    int size() {
        return ll.getSize();
    }

    int top() {
        return ll.getElementAt(0);
    }
};

//----------------MAIN TEST------------
int main() {
    Stack st;

    cout << "Stack rong:  " << (st.isEmpty() ? "Yes" : "No") << endl;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Size = " << st.size() << endl;
    cout << "Top = " << st.top() << endl;

    // Lay va xoa cac phan tu
    while (!st.isEmpty()) {
        cout << "Pop = " << st.pop() << endl;
    }

    cout << "Stack rong: " << (st.isEmpty() ? "Yes" : "No") << endl;
    return 0; 
}