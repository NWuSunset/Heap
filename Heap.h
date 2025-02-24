#ifndef HEAP_H
#define HEAP_H

class Heap {
public:
  Heap();

    void insertNode(int num, int pos); //inserts nodes from an existing number array (user input)
    void printHeap(int pos, int depth, int size); //prints out heap in tree formation for ease of viewing/debugging
    void sortHeap(int index); //sorts heap from the root (when the root is smaller than it's children)
    void deleteRoot(); //deletes the root of the tree
    void deleteAll(); //deletes every element in the tree
    void printArr() const; //debugging tool, prints actual array.
    int heapSize = 1; //Keeps track of heap size, starts at one in order to find out what index would be the end of the heap array

private:
    int heap[100]{}; //heap represented as an array with 100 slots
};
#endif
