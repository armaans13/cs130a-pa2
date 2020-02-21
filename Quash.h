#ifndef QUASH_H
#define QUASH_H

#include <iostream>
#include "MinHeap.h"
#include "Hash.h"

class Quash {
    public:
    Quash();
    int insert (int i);
    int lookup (int i);
    int deleteMin ();
    int deleter (int i);
    void print();

    private:
    Hash hasher;
    MinHeap heap;

};

#endif