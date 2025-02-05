#include "Heap.h"

Heap::Heap() = default;

//Assuming you start at index 1 (instead of 0), you can find your left child at (index * 2) and your right child at (index * 2 + 1), while your parent is (floor(index / 2)).

void Heap::insertNode(int num) {
  //Insert a node / number into the heap
  
  //Add to first empty spot in heap then floor(index/2) and compare it to the parent
  if (heapSize == 0) {
    heap[1] = num; //head of tree
    return; 
  }

  parent = floor((heapIndex)/2); //since parent would be floor(index/2)
  //Insert to end
  if (num > parent) {
    //Switch their positions then recursively run back through the tree to the first parent 
  }
      heap[heapIndex];

  
}

void Heap::printHeap() {


}
