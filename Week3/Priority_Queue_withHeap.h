#include <iostream>
#include <vector>
using namespace std;

//------------IMPLEMENT PRIORITY QUEUE WITH MAXHEAP-----------------

class PriorityQueueMax {
private:
    vector<int> heap; // dung vector de lam heap

    // Dua phan tu len dung vi tri (swim)
    void swim(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] >= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    // Dua phan tu xuong dung vi tri (sink)
    void sink(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            // tim con lon hon
            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break; // da dung vi tri
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Chen mot gia tri vao heap
    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    // Xoa va tra ve phan tu lon nhat
    int delMax() {
        if (isEmpty()) {
            return INT_MIN;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!isEmpty()) sink(0);
        return maxVal;
    }

    // Kiem tra rong
    bool isEmpty() {
        return heap.empty();
    }

    // Lay phan tu lon nhat
    int max() {
        if (isEmpty()) {
            return INT_MIN;
        }
        return heap[0];
    }

    // So luong phan tu
    int size() {
        return heap.size();
    }

    // In heap de kiem tra
    void printHeap() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

//-----------IMPLEMENT PRIORITYQUEUE WITH MINHEAP----------------
class PriorityQueueMin {
private:
    vector<int> heap;

    // Day len (swim)
    void swim(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            // Min Heap: Neu cha nho hon hoac bang con thi dung.
            if (heap[parent] <= heap[i]) break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    // Day xuong (sink)
    void sink(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            // Tim con nho hon
            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    // Chen mot gia tri vao heap
    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    // Xoa va tra ve phan tu nho nhat
    int delMin() {
        if (isEmpty()) {
            return INT_MAX;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!isEmpty()) sink(0);
        return minVal;
    }

    // Kiem tra rong
    bool isEmpty() const {
        return heap.empty();
    }

    // Lay phan tu nho nhat
    int min() const {
        if (isEmpty()) {
            return INT_MAX;
        }
        return heap[0];
    }

    // So luong phan tu
    int size() const {
        return heap.size();
    }

    // In heap de kiem tra
    void printHeap() const {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};
