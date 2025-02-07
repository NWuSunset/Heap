#ifndef HEAP_H
#define HEAP_H

class Heap {
 public:
  Heap();
  
  void insertNode(int num, int pos); //inserts nodes from an existing number array (user input)
  void printHeap(int pos, int depth, int size); //prints out heap in tree formation for ease of viewing/debugging
  void printArr();
  int heapSize = 1;
  
 private:
  int heap[100]{}; //heap represented as an array with 100 slots
};
#endif 
