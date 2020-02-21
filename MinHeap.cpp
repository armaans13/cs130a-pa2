
#include "MinHeap.h"

using namespace std; 

void MinHeap::heapify(int index) {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int smallestIndex = index;

    if (leftChild <= size && 
    heapArray[leftChild] < heapArray[smallestIndex]) {
        smallestIndex = leftChild;
    }
    if (rightChild <= size &&
    heapArray[rightChild] < heapArray[smallestIndex]) {
        smallestIndex = rightChild;
    }
    if (smallestIndex != index) {
        int temp = heapArray[index];
        heapArray[index] = heapArray[smallestIndex];
        heapArray[smallestIndex] = temp;
        heapify(smallestIndex);
    }
}

int MinHeap::lookup(int i) {
    for(int e = 0; e < 100; e++) {
        if (heapArray[e] == i)
            return e;
    }
    return -1;
}

int MinHeap::deleter(int i) {
    int temp = lookup(i);

    int lastIndex = 0;
    while(heapArray[lastIndex] != NULL)
        lastIndex++;
    heapArray[i] = heapArray[lastIndex];
    heapArray[lastIndex] = NULL;
    heapify(i);

}
    
MinHeap::MinHeap() {
    size = 0;
    heapArray = new int[100];
}

void MinHeap::insert(int e) {
    size++;
    heapArray[size] = e;
    int temp;
    int index = size;
    while (index > 1 && heapArray[index / 2] > heapArray[index]) {
        // swap parent and current node
        temp = heapArray[index];
        heapArray[index] = heapArray[index / 2];
        heapArray[index / 2] = temp;
        index = index / 2;
    }
}
int MinHeap::removeMin(){
    if (size <= 0)
        throw HeapEmptyException();

    if (size == 1) {
        size--;
        return heapArray[1];
    }

    int index = 1;
    int min = heapArray[index];
    heapArray[index] = heapArray[size];
    size--;

    heapify(index);
    return min;
}

void MinHeap::printHeap() {
    for (int i = 1; i <= size; i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;
}