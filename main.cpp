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
  
  while (!userSelection(heap)) {
  }
}

bool userSelection(Heap* heap) {
  char userInput[9];
  int nums[100]; //arr of numbers
  int size;
  cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name" << endl;
    cin.getline(userInput, 9);
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
      heap->insertNode(nums[i]); //add to heap
    }
  }

  return true;
  
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
