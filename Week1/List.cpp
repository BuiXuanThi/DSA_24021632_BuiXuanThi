#include <iostream>
#include <climits>
using namespace std;

const int Max = 100;

// Implement class List voi kieu du lieu la int
class List {
private:
    int data[Max]; // mang luu cac phan tu
    int size;      // so phan tu thuc su
public:
    // Khoi tao list rong
    List() : size(0) {}

    // tra ve so phan tu hien co
    int getSize() const {
        return size;
    }

    // kiem tra list rong
    bool isEmpty() const {
        return size == 0;
    }

    // kiem tra list day
    bool isFull() const {
        return size == Max;
    }

    // lay phan tu tai vi tri index (O(1))
    int getElement(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index khong hop le!\n";
            return INT_MIN; // gia tri bao loi
        }
        return data[index];
    }

    // chen vao dau (O(n))
    bool insertHeadList(int x) {
        if (isFull()) return false;
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = x;
        size++;
        return true;
    }

    // chen vao cuoi (O(1))
    bool insertTailList(int x) {
        if (isFull()) return false;
        data[size] = x;
        size++;
        return true;
    }

    // chen vao vi tri index (O(n))
    bool insertAtPos(int index, int value) {
        if (isFull() || index < 0 || index > size) return false;
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = value;
        size++;
        return true;
    }

    // xoa dau (O(n))
    bool deleteAtHead() {
        if (isEmpty()) return false;
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }

    // xoa cuoi (O(1))
    bool deleteAtTail() {
        if (isEmpty()) return false;
        size--;
        return true;
    }

    // xoa tai vi tri index (O(n))
    bool deleteAtPos(int index) {
        if (isEmpty() || index < 0 || index >= size) return false;
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }

    // duyet xuoi (O(n))
    void forwardTraversal() const {
        if (isEmpty()) {
            cout << "List rong!\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // duyet nguoc (O(n))
    void backwardTraversal() const {
        if (isEmpty()) {
            cout << "List rong!\n";
            return;
        }
        for (int i = size - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// ham test
int main() {
    List lst;

    cout << "=== Test chen vao cuoi ===\n";
    lst.insertTailList(10);
    lst.insertTailList(20);
    lst.insertTailList(30);
    lst.forwardTraversal(); // 10 20 30

    cout << "=== Test chen vao dau ===\n";
    lst.insertHeadList(5);
    lst.insertHeadList(2);
    lst.forwardTraversal(); // 2 5 10 20 30

    cout << "=== Test chen vao vi tri ===\n";
    lst.insertAtPos(2, 99); // chen 99 vao index = 2
    lst.forwardTraversal(); // 2 5 99 10 20 30

    cout << "=== Test xoa dau ===\n";
    lst.deleteAtHead();
    lst.forwardTraversal(); // 5 99 10 20 30

    cout << "=== Test xoa cuoi ===\n";
    lst.deleteAtTail();
    lst.forwardTraversal(); // 5 99 10 20

    cout << "=== Test xoa tai vi tri ===\n";
    lst.deleteAtPos(1);
    lst.forwardTraversal(); // 5 10 20

    cout << "=== Test duyet nguoc ===\n";
    lst.backwardTraversal(); // 20 10 5

    cout << "=== Test getElement ===\n";
    cout << "Phan tu tai index 1: " << lst.getElement(1) << endl; // 10
    cout << "Phan tu tai index 10: " << lst.getElement(10) << endl; // loi

    return 0;
}
