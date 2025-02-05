#ifndef HEAP_H
#define HEAP_H

class Heap {
 public:
  Heap();
  
  void insertNode(int num); //inserts nodes from an existing number array (user input)
  void printHeap(); //prints out heap in tree formation for ease of viewing/debugging

 private:
  int heap[100]; //heap represented as an array with 100 slots
};
#endif 
