#include <iostream>
#include <climits>
using namespace std;

// implement class Node, voi Node chua gia tri int
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// implement class SingleLinkedList
class SingleLinkedList {
private:
    Node* head;
    int size;

    // ham de quy ho tro in nguoc
    void printBackwardHelper(Node* node) {
        if (node == nullptr) return;
        printBackwardHelper(node->next);
        cout << node->data << "->";
    }

public:
    // khoi tao mot linkedList rong
    SingleLinkedList() : head(nullptr), size(0) {}

    // destructor: giai phong bo nho
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // tra ve so phan tu
    int getSize() const { return size; }

    // lay phan tu tai vi tri index, O(n)
    int getElementAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Index khong hop le!\n";
            return INT_MIN;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // them vao dau, O(1)
    bool insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    // them vao cuoi, O(n)
    bool insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        return true;
    }

    // them vao vi tri index, O(n)
    bool insertAtPos(int index, int value) {
        if (index < 0 || index > size) return false;

        if (index == 0) return insertAtHead(value);

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return true;
    }

    // xoa dau, O(1)
    bool deleteAtHead() {
        if (size == 0) return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // xoa cuoi, O(n)
    bool deleteAtTail() {
        if (size == 0) return false;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
        return true;
    }

    // xoa tai vi tri index, O(n)
    bool deleteAtPos(int index) {
        if (size == 0 || index < 0 || index >= size) return false;

        if (index == 0) return deleteAtHead();

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* res = temp->next;
        temp->next = res->next;
        delete res;
        size--;
        return true;
    }

    // duyet xuoi
    void forwardTraversal() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    // duyet nguoc
    void backwardTraversal() {
        printBackwardHelper(head);
        cout << "Null" << endl;
    }
};

// ham test
int main() {
    SingleLinkedList lst;

    cout << "=== Test chen vao cuoi ===\n";
    lst.insertAtTail(10);
    lst.insertAtTail(20);
    lst.insertAtTail(30);
    lst.forwardTraversal(); // 10->20->30->Null

    cout << "=== Test chen vao dau ===\n";
    lst.insertAtHead(5);
    lst.insertAtHead(2);
    lst.forwardTraversal(); // 2->5->10->20->30->Null

    cout << "=== Test chen vao vi tri ===\n";
    lst.insertAtPos(2, 99);
    lst.forwardTraversal(); // 2->5->99->10->20->30->Null

    cout << "=== Test xoa dau ===\n";
    lst.deleteAtHead();
    lst.forwardTraversal(); // 5->99->10->20->30->Null

    cout << "=== Test xoa cuoi ===\n";
    lst.deleteAtTail();
    lst.forwardTraversal(); // 5->99->10->20->Null

    cout << "=== Test xoa tai vi tri ===\n";
    lst.deleteAtPos(1);
    lst.forwardTraversal(); // 5->10->20->Null

    cout << "=== Test duyet nguoc ===\n";
    lst.backwardTraversal(); // 20->10->5->Null

    cout << "=== Test getElementAt ===\n";
    cout << "Phan tu tai index 1: " << lst.getElementAt(1) << endl; // 10
    cout << "Phan tu tai index 10: " << lst.getElementAt(10) << endl; // loi

    return 0;
}
