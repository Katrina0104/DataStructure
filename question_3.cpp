#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k) {
    queue<int> negatives;

    // Traverse the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negatives.push(i); // Store the index of the negative element
        }
    }

    // Process the rest of the windows
    for (int i = k; i < n; i++) {
        // Print the first negative integer of the previous window
        if (!negatives.empty()) {
            cout << arr[negatives.front()] << " ";
        } else {
            cout << "0 ";
        }

        // Remove the elements which are out of this window
        while (!negatives.empty() && negatives.front() < i - k + 1) {
            negatives.pop();
        }

        // Add the current element if it's negative
        if (arr[i] < 0) {
            negatives.push(i);
        }
    }

    // For the last window
    if (!negatives.empty()) {
        cout << arr[negatives.front()] << " ";
    } else {
        cout << "0 ";
    }
}

int main() {
    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; 

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the size of the window (k): ";
    cin >> k;

    printFirstNegativeInteger(arr, n, k);

    return 0;
}

