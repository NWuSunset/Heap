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
    Heap* heap = new Heap(); 
    while (!userSelection(heap)) {}
}

bool userSelection(Heap* heap) {
    char userInput[12];
    cout << "Type CONSOLE to enter a series of numbers in the console. Or type FILE to enter a file name. Type PRINT to print out the heap tree" << endl;
    cin.getline(userInput, 12);

    //in case more than 8 characters are entered (so it won't break the program)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input Error. Input is too long" << endl;
    }

    if (strcasecmp(userInput, "FILE") == 0) {
        fromFile(heap);
    } else if (strcasecmp(userInput, "CONSOLE") == 0) {
        fromConsole(heap);
    } else if (strcasecmp(userInput, "PRINT") == 0) {
        heap->printHeap(1, 0, heap->heapSize);
    } else if (strcasecmp(userInput, "remove-root") == 0) {
        heap->deleteRoot();
    } else if (strcasecmp(userInput, "remove-all") == 0) {
        heap->deleteAll();
    } else if (strcasecmp(userInput, "QUIT") == 0) {
        return true;
    } else {
        cout << "Invalid input." << endl;
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
        cout << "Adding numbers from file" << endl;
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
    getline(cin, input);

    istringstream iss(input);
    //object to stream the string into different variables (since we input ints separated by spaces)
    int num;

    //Stream a number till while space is encountered. Do this until end of string is hit
    while (iss >> num) {
        heap->insertNode(num, heap->heapSize); //add num to heap
    }
}
