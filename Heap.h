#ifndef HEAP_H
#define HEAP_H

class Heap {
public:
  Heap();

  //Inserts a number into the heap array, if a number is bigger then the parent the heap swaps their positions,
  //then recurses up the tree to compare other parents, until tree is correctly sorted
  void insertNode(int num, int pos);
  void printHeap(int pos, int depth, int size); //prints out heap in tree formation for ease of viewing/debugging
  void printArr() const; //prints out heap in array form, also for debugging
  
  int heapSize = 1; //Keeps track of heap size, starts at one in order to find out what index would be the end of the heap array

private:
    int heap[100]{}; //heap represented as an array with 100 slots
};
#endif
