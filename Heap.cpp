#include "Heap.h"
#include <cmath>
#include <iostream>
Heap::Heap() = default;

//Assuming you start at index 1 (instead of 0), you can find your left child at (index * 2) and your right child at (index * 2 + 1), while your parent is (floor(index / 2)).

//intial position of heapSize
void Heap::insertNode(int num, int pos) {
  std::cout << pos << std::endl;
  //Add to first empty spot in heap then floor(index/2) and compare it to the parent
  if (heapSize == 1) {
    heap[heapSize] = num; //head of tree
    heapSize++; // the next index in the tree (end of tree)
    return; 
  }

   if (pos == 1) { //if we are at the top of the tree
     std::cout << "Top Pos" << std::endl;
     return;
  }

  int parent = floor((heapSize)/2); //since parent would be floor(index/2)
  //Insert to end
  if (num > heap[parent]) {
    //Switch their positions then recursively run back through the tree to the first parent
    int temp = heap[parent];//save parent
    heap[parent] = num; //number is now the parent
    heap[heapSize++] = temp; //parent is now swapped to the original point (and increasing heap size)
    //Recuse through previous nodes (basically checking if num is greater than the next parent and so on until the top of the tree
    return insertNode(num, --pos);
  } 

  //std::cout << parent << "-->" << parent << std::endl;
  if (num <= heap[parent]) {
  //Inserting a lower value node
  heap[heapSize++] = num; //basically just add it to the end
  }
}

/*Takes in tree index (arr index), how deep we are in the tree, and the tree size (initially (1,0,size))
 *Since each instance of the function still exists when recursion happens, that means each place of the tree will be printed out
 *(so  *once the end of the tree is printed, the original parent node still has the printHeap function happening,
 *so it just continues throgh the function. So if the right tree was printed, it will then go print the top of the tree,
 *then the left of the tree (since that'*s the order the function is in. */
void Heap::printHeap(int pos, int depth, int size) {
  if (pos*2 + 1 < size) { //check if right node exists
    printHeap(pos*2 + 1, depth + 1, size); //recusion right of the tree
  }
  for (int i = 0; i < depth; i++) {
    std::cout << '\t'; //add a tab for each depth
  }
  std::cout << heap[pos] << std::endl; //print out the node
  if (pos*2 < size) { //Check if left exists 
    printHeap(pos*2, depth+1, size); //recurse through the left of the tree
  }

}

void Heap::printArr() {
  for (int i = 1; i < heapSize; i++) {
    std::cout << heap[i] << std::endl;
  }
}
