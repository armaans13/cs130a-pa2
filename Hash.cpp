#include "Hash.h"

using namespace std;


int Hash::insert(int i) {
    int key = hash(i);
    for(int e = 0; e < hasher[key].size();e++) {
        if(hasher[key].at(e).first == i) {
            hasher[key].at(e).second++;
            return hasher[key].at(e).second;
        }
    }

    hasher[key].push_back(make_pair(i,1));
    //cout << hasher[key].at(0).first << endl;
    return hasher[key].at(0).second;
}
Hash::Hash() {
   // hasher = new std::vector<std::pair<int,int>>;
}

int Hash::lookup(int i) {
    int key = hash(i);
    for(int e = 0; e < hasher[key].size();e++) {
        if(hasher[key].at(e).first == i) {
            return hasher[key].at(e).second;
        }
    }

    return 0;
}

int Hash::deleter(int i) {
    int key = hash(i);
    //cout << key;
    for(int e = 0; e < hasher[key].size();e++) {
        if(hasher[key].at(e).first == i) {
            hasher[key].at(e).second--;
            //cout << hasher[key].at(e).second << endl;
            return hasher[key].at(e).second;
        }
    }

    return -1;
}

int Hash::hash(int i) {
    while (i < 0)
        i += 43;
    return i % 43;
}
