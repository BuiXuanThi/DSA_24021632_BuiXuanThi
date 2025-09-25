#include <iostream>
#include <climits>
#include "SinglyLinkedList.h" 
using namespace std;

//----------------IMPLEMENT QUEUE------------
class Queue {
private:
    SingleLinkedList ll;  // dung linked list goc de luu tru
public:
    // kiem tra queue rong, O(1)
    bool isEmpty() {
        return ll.getSize() == 0;
    }

    // them phan tu vao cuoi queue, O(n)
    void push(int x) {
        ll.insertAtTail(x);
    }

    // xoa phan tu dau queue va tra ve gia tri, O(1)
    int pop() {
        if (isEmpty()) return INT_MIN;   // queue rong
        int val = ll.getElementAt(0);    // lay dau
        ll.deleteAtHead();               // xoa dau
        return val;
    }

    // xem phan tu dau queue ma khong xoa, O(1)
    int front() {
        if (isEmpty()) return INT_MIN;
        return ll.getElementAt(0);
    }

    // lay so luong phan tu, O(1)
    int size() {
        return ll.getSize();
    }
};

//----------------MAIN TEST------------
int main() {
    Queue q;

    cout << "Queue rong: " << (q.isEmpty() ? "Yes" : "No") << endl;

    // them phan tu
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Size = " << q.size() << endl;
    cout << "Front = " << q.front() << endl;

    // lay va xoa tung phan tu
    while (!q.isEmpty()) {
        cout << "Pop = " << q.pop() << endl;
    }

    cout << "Queue rong: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
