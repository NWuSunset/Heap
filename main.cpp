#include <iostream>
#include <limits>
#include <string.h>
#include "Heap.h"
using namespace std;

bool userSelection(Heap* heap);
void insert_nodes(int nums[100]);

//Should be able to enter numbers, remove numbers, and display the tree visually
int main() {
  Heap* heap = new Heap(); 
  heap->printHeap(1,0,16);
  heap->insertNode(100, heap->heapSize);
  heap->insertNode(20, heap->heapSize);
  heap->insertNode(30, heap->heapSize);
  heap->insertNode(40, heap->heapSize);
  heap->insertNode(50, heap->heapSize);
  heap->insertNode(200, heap->heapSize);
  heap->insertNode(10, heap->heapSize);
  heap->insertNode(60, heap->heapSize);
  
  heap->printHeap(1,0,heap->heapSize);
  heap->printArr();
  while (!userSelection(heap)) {
  }
}

bool userSelection(Heap* heap) {
  char userInput[9];
  int nums[100]; //arr of numbers
  int size;
  cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name" << endl;
    cin.getline(userInput, 9);

 //in case more than 8 characters are entered (so it won't break the program)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
  if (strcasecmp(userInput, "FILE") == 0) {
    cout << "GO File" << endl;
  } else if (strcasecmp(userInput, "CONSOLE") == 0) {
    //Enter nums
    cout << "How many numbers do you want to enter" << endl;
    cin >> size;

    //Entering numbers based on array
    for (int i = 0; i < size; i++) {
      cout << "Enter number: " << endl;
      cin >> nums[i];
      heap->insertNode(nums[i], heap->heapSize); //add to heap
    }
  } else if (strcasecmp(userInput, "QUIT") == 0) {
    return true;
  }

  return false;
  
}




template <typename T>
T validInput() {
  //Template makes it able to take any data type (so I don't have to write code for different types...)
    T value;
    while (!(cin >> value)) {
        cout << "Invalid input. please enter a valid number" << endl;
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }
    return value;
}
