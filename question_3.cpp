// Katrina 1123521 deadline : 11/28

#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // For parsing input
using namespace std;

// Define a structure to represent elements in the priority queue
struct Element {
    int value;       // Value of the element
    int arrayIndex;  // Index of the array it belongs to
    int elementIndex; // Index of the element in the array

    // Define a comparison operator for the priority queue (min-heap)    ->   like the qus2 we use same way
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;   // Initialize a minimum heap (min-heap)
    vector<int> mergedArray;

    // Step 1: Add the first element of each array into the heap
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) { // Check if the array is not empty
            minHeap.push({arrays[i][0], i, 0});  // this part {arrays[i][0], i, 0} can look line22 bcs the value define like this
        }
    }

    // Step 2: Process the heap until it's empty
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();

        // Add the smallest value to the merged array
        mergedArray.push_back(current.value);

        // If the array has more elements, add the next element to the heap
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
        /*
		Initialize a new Element structure containing the following three values:

		arrays[current.arrayIndex][current.elementIndex + 1]:   Numeric value, that is, the element at position current.elementIndex + 1 in the current array.
		current.arrayIndex:   The index of the array from which this element comes.
		current.elementIndex + 1:   The index of the element in the array
		*/
    }

    return mergedArray;
}

int main() {
    int k;
    cout << "Enter the number of sorted arrays (K): ";
    cin >> k;
    cin.ignore(); // Ignore the newline after the number of arrays

    vector<vector<int>> arrays(k);

    // Input the sorted arrays
    cout << "Enter each sorted array on a new line:\n";
    for (int i = 0; i < k; ++i) {
        string line;
        getline(cin, line); // Read the entire line
        istringstream iss(line);  // isringstream allows you to treat a string as a stream (just like a file or standard input) and read data from the string as if it were a stream.
        int num;
        while (iss >> num) {  // Read each number from the stream
            arrays[i].push_back(num);
        }
    }

    // Merge the sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
