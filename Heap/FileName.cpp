// Max heap
/*
#include <iostream>
using namespace std;

class BinaryHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int leftIdx = left(index);
        int rightIdx = right(index);
        int largest = index;

        if (leftIdx < size && heap[leftIdx] > heap[largest])
            largest = leftIdx;
        if (rightIdx < size && heap[rightIdx] > heap[largest])
            largest = rightIdx;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~BinaryHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Heap is empty.\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    BinaryHeap h(10);

    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    h.printHeap();

    cout << "Extracted Max: " << h.extractMax() << endl;
    h.printHeap();
    cin.get();
    return 0;
}
*/

// Min headp
#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int leftIdx = left(index);
        int rightIdx = right(index);
        int smallest = index;

        if (leftIdx < size && heap[leftIdx] < heap[smallest])
            smallest = leftIdx;
        if (rightIdx < size && heap[rightIdx] < heap[smallest])
            smallest = rightIdx;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMin() {
        if (size <= 0) {
            cout << "Heap is empty.\n";
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return minVal;
    }

    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    h.printHeap();

    cout << "Extracted Min: " << h.extractMin() << endl;
    h.printHeap();
    cin.get();
    return 0;
}
