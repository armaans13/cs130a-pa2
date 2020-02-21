#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <utility>

class Hash {
    public:
    Hash();
    int insert(int i);
    int lookup(int i);
    int deleter(int i);
    int hash(int i);

    private:
    std::vector<std::pair<int,int>> hasher[43];

};

#endif

