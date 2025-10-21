#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//------------IMPLEMENT MIN_HEAP---------------
class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Ham dua phan tu len (sau khi chen)
    void swim(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Ham dua phan tu xuong (sau khi xoa)
    void sink(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < n && heap[l] < heap[smallest])
                smallest = l;
            if (r < n && heap[r] < heap[smallest])
                smallest = r;

            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    // Them phan tu vao heap
    void insert(int val) {
        heap.push_back(val);
        swim(heap.size() - 1);
    }

    // Xoa va tra ve phan tu nho nhat
    int delMin() {
        if (heap.empty()) return INT_MIN;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) sink(0);
        return minVal;
    }

    // Kiem tra heap rong khong
    bool isEmpty() {
        return heap.empty();
    }

    // Lay phan tu nho nhat
    int min() {
        if (heap.empty()) return INT_MIN;
        return heap[0];
    }

    // Tra ve so phan tu
    int size() {
        return heap.size();
    }

    // In heap
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

//--------------IMPLEMENT MAX_HEAP----------------
class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Dua phan tu len tren dung vi tri (sau khi chen)
    void swim(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Dua phan tu xuong dung vi tri (sau khi xoa)
    void sink(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l < n && heap[l] > heap[largest])
                largest = l;
            if (r < n && heap[r] > heap[largest])
                largest = r;

            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Them phan tu moi vao heap
    void insert(int val) {
        heap.push_back(val);
        swim(heap.size() - 1);
    }

    // Xoa va tra ve phan tu lon nhat
    int delMax() {
        if (heap.empty()) return INT_MIN;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) sink(0);
        return maxVal;
    }

    // Tra ve phan tu lon nhat
    int max() {
        if (heap.empty()) return INT_MIN;
        return heap[0];
    }

    // Kiem tra heap co rong khong
    bool isEmpty() {
        return heap.empty();
    }

    // So phan tu hien co trong heap
    int size() {
        return heap.size();
    }

    // In toan bo heap
    void printHeap() {
        for (int v : heap) cout << v << " ";
        cout << endl;
    }
};
