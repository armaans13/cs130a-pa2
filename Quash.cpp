#include "Quash.h"

using namespace std;

Quash::Quash() {
    //hasher = new Hash();
    //heap = new MinHeap();
}

int Quash::insert(int i) {
    int temp = hasher.insert(i);
    //cout << temp << endl;
    int heapIndex = heap.lookup(i);
    if (heapIndex == -1)
        heap.insert(i);
    if (temp == 1)
        cout << "Item successfully inserted, count = " << temp << endl;
    else if (temp > 1)
        cout << "item already present, new count = " << temp << endl;

    return temp;

}

int Quash::lookup(int i) {
    int temp = hasher.lookup(i);
    if (temp > 0)
        cout << "Item found, count = " << temp << endl;
    else if (temp == 0)
        cout << "item not found" << endl;

    return -1;
}

int Quash::deleteMin() {
    try {
    int temp = heap.removeMin();
    int answer = hasher.deleter(temp);
    if ( answer == 0) 
        cout << "min item " << temp << " successfully deleted" << endl;
    else if (answer > 0)
        cout << "min item = " << temp << ", count decremented, new count = " << answer << endl;
    } catch (HeapEmptyException ex) {
        cout << "min item not present since table is empty" << endl;
    }

    return -1;
}

int Quash::deleter(int i) {
    int temp = hasher.deleter(i);
    if (temp == 0) {
        heap.deleter(i);
        cout << "item successfully deleted" << endl;
    } else if (temp > 0) {
        cout << "item count decremented, new count = " << temp << endl;
    } else 
        cout << "item not present in the table" << endl;
}

void Quash::print() {
    heap.printHeap();
}
