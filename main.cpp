#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Heap.h"
using namespace std;

bool userSelection(Heap* heap);
void insert_nodes(int nums[100]);
void fromFile(Heap* heap);
void fromConsole(Heap* heap);

//Should be able to enter numbers, remove numbers, and display the tree visually
int main() {
    Heap* heap = new Heap(); //use auto or no?
    //heap->printHeap(1, 0, 16);
    heap->insertNode(100, heap->heapSize);
    heap->insertNode(20, heap->heapSize);
    heap->insertNode(30, heap->heapSize);
    heap->insertNode(40, heap->heapSize);
    heap->insertNode(50, heap->heapSize);
    heap->insertNode(200, heap->heapSize);
    heap->insertNode(10, heap->heapSize);
    heap->insertNode(60, heap->heapSize);

    heap->printHeap(1, 0, heap->heapSize);
    heap->printArr();

    while (!userSelection(heap)) {}
}

bool userSelection(Heap* heap) {
    char userInput[9];
    cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name. Type PRINT to print out the heap tree" << endl;
    cin.getline(userInput, 9);

    //in case more than 8 characters are entered (so it won't break the program)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (strcasecmp(userInput, "FILE") == 0) {
        fromFile(heap);
    } else if (strcasecmp(userInput, "CONSOLE") == 0) {
        fromConsole(heap);
    } else if (strcasecmp(userInput, "PRINT") == 0) {
        heap->printHeap(1, 0, heap->heapSize);
    } else if (strcasecmp(userInput, "QUIT") == 0) {
        return true;
    }
    return false;
}

void fromFile(Heap* heap) {
    string file;
    cout << "Enter the name of the file you want to read from" << endl;
    getline(cin, file);

    ifstream numFile(file);

    if (numFile.is_open()) {
        int num;
        while (numFile >> num) {
            heap->insertNode(num, heap->heapSize);
        }
        numFile.close();
    } else {
        cout << "Cannot find file specified" << endl;
    }
}

void fromConsole(Heap* heap) {
    string input;
    cout << "Enter numbers separated by spaces: " << endl;
    cin.ignore(); //ignore potential extra things in the input buffer
    getline(cin, input);

    istringstream iss(input);
    //object to stream the string into different variables (since we input ints separated by spaces)
    int num;

    //Stream a number till while space is encountered. Do this until end of string is hit
    while (iss >> num) {
        heap->insertNode(num, heap->heapSize); //add num to heap
    }
}

/*
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
} */
//Not needed due to using string streams and inputting into an int variable
