#include <iostream>
#include <climits>
using namespace std;

// Khai bao Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Lay phan tu vi tri index
    int getElementAt(int index) {
        if (index < 0 || index >= size) return INT_MIN;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Them vao dau
    bool insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        return true;
    }

    // Them vao cuoi
    bool insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        return true;
    }

    // Them tai vi tri index
    bool insertAtPos(int index, int value) {
        if (index < 0 || index > size) return false;
        if (index == 0) return insertAtHead(value);
        if (index == size) return insertAtTail(value);

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
        return true;
    }

    // Xoa dau
    bool deleteAtHead() {
        if (!head) return false;
        Node* temp = head;
        if (!head->next) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    // Xoa cuoi
    bool deleteAtTail() {
        if (!tail) return false;
        Node* temp = tail;
        if (!tail->prev) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    // Xoa tai vi tri index
    bool deleteAtPos(int index) {
        if (index < 0 || index >= size) return false;
        if (index == 0) return deleteAtHead();
        if (index == size - 1) return deleteAtTail();

        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
        return true;
    }

    // Duyet xuoi
    void forwardTraversal() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Duyet nguoc
    void backwardTraversal() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }

    // Lay size
    int getSize() const { return size; }
};

// Main test
int main() {
    DoublyLinkedList lst;

    cout << "=== Them vao cuoi ===\n";
    lst.insertAtTail(10);
    lst.insertAtTail(20);
    lst.insertAtTail(30);
    lst.forwardTraversal();

    cout << "=== Them vao dau ===\n";
    lst.insertAtHead(5);
    lst.insertAtHead(2);
    lst.forwardTraversal();

    cout << "=== Them vao vi tri ===\n";
    lst.insertAtPos(2, 99);
    lst.forwardTraversal();

    cout << "=== Xoa dau ===\n";
    lst.deleteAtHead();
    lst.forwardTraversal();

    cout << "=== Xoa cuoi ===\n";
    lst.deleteAtTail();
    lst.forwardTraversal();

    cout << "=== Xoa tai vi tri ===\n";
    lst.deleteAtPos(1);
    lst.forwardTraversal();

    cout << "=== Duyet nguoc ===\n";
    lst.backwardTraversal();

    cout << "=== Test getElementAt ===\n";
    int val = lst.getElementAt(1);
    if (val == INT_MIN) cout << "Index khong hop le!\n";
    else cout << "Gia tri tai index 1: " << val << endl;

    val = lst.getElementAt(10);
    if (val == INT_MIN) cout << "Index khong hop le!\n";
    else cout << "Gia tri tai index 10: " << val << endl;

    return 0;
}
