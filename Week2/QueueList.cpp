#include"List.h"
#include<iostream>
#include<climits>
using namespace std;

//----------------IMPLEMENT QUEUE------------
class Queue {
private:
    List ls;   // dung List de luu tru phan tu
public:
    // kiem tra queue rong, O(1)
    bool isEmpty() {
        return ls.isEmpty();
    }

    // them phan tu vao cuoi queue, O(n) neu List la mang
    bool push(int x) {
        return ls.insertTailList(x);
    }

    // xoa phan tu dau queue va tra ve gia tri, O(1)
    int pop() {
        if (isEmpty()) return INT_MIN;   // queue rong
        int value = ls.getElement(0);    // lay phan tu dau
        ls.deleteAtHead();               // xoa dau
        return value;
    }

    // xem phan tu dau queue ma khong xoa, O(1)
    int front() {
        if (isEmpty()) return INT_MIN;   // queue rong
        return ls.getElement(0);
    }

    // lay so luong phan tu trong queue, O(1)
    int size() {
        return ls.getSize();
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