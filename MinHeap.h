#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

class HeapEmptyException {};

class MinHeap {
private:
    int* heapArray;
    int size;
    const static int CAPACITY = 100;
    void heapify(int index);
public:
    MinHeap();
    int removeMin();
    void insert(int e);
    int getSize() { return size; }
    void printHeap();
    int lookup(int i);
    int deleter(int i);

};

#endif
