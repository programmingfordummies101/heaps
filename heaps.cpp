#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

// Adds a delay to make the outputs more dramatic
void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

// Prints the current state of the heap with a label
void printHeap(const vector<int>& heap, string message = "Heap") {
    cout << "\n" << message << ": ";
    for (int val : heap) cout << val << " ";
    cout << endl;
    delay(300);
}

// Simulates recruiting an agent (just for thematic output)
void recruitAgent(string agent, int power) {
    cout << "Recruiting '" << agent << "' with power " << power << "... ";
    delay(500);
    cout << "Success!" << endl;
    delay(300);
}

// Inserts a value into the Max-Heap and maintains heap properties
void insertAgent(vector<int>& heap, int power, string agent) {
    recruitAgent(agent, power); // Themed animation
    heap.push_back(power);      // Add the new power to the end of the heap
    push_heap(heap.begin(), heap.end()); // Rearrange to maintain Max-Heap structure
    printHeap(heap, "Max-Heap");
}

// Converts the Max-Heap into a Min-Heap by flipping priorities
void convertToMinHeap(vector<int>& heap) {
    cout << "\nConverting to Min-Heap...\n";
    for (int& val : heap) val = -val; // Negate all values (makes large numbers "small")
    make_heap(heap.begin(), heap.end(), greater<int>()); // Rearrange as a Min-Heap
    for (int& val : heap) val = -val; // Restore original values but in Min-Heap order
    printHeap(heap, "Min-Heap");
}

// Removes and "deploys" the strongest agent from the heap
void deployAgent(vector<int>& heap) {
    if (heap.empty()) { // Prevents errors when trying to deploy from an empty heap
        cout << "No agents available to deploy!" << endl;
        return;
    }
    cout << "\nDeploying agent with power: " << heap.front() << endl; // Shows the strongest agent
    pop_heap(heap.begin(), heap.end()); // Moves the largest value to the end
    heap.pop_back(); // Actually removes the largest value
    printHeap(heap, "Max-Heap after deployment");
}

int main() {
    cout << "=== Valorant Agent HQ ===" << endl;

    vector<int> maxHeap;

    // Adding agents to the heap
    insertAgent(maxHeap, 80, "Jett");
    insertAgent(maxHeap, 95, "Phoenix");
    insertAgent(maxHeap, 70, "Sage");

    // Converts Max-Heap to Min-Heap
    convertToMinHeap(maxHeap);

    // Deploys the strongest agent
    deployAgent(maxHeap);

    return 0;
}
