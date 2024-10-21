#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
    // Check for even number of elements
    if (q.size() % 2 != 0) {
        cout << "Input even number of integers." << endl;
        return; // Exit the function if the queue has an odd size
    }

    // Initialize an empty queue of int type
    queue<int> temp;
    int halfSize = q.size() / 2;

    // Push the first half elements into the temporary queue
    for (int i = 0; i < halfSize; i++) {
        temp.push(q.front());
        q.pop();
    }

    // Enqueue back the queue elements alternatively
    while (!temp.empty()) {
        q.push(temp.front()); // Push from the first half
        temp.pop();           // Remove from temporary queue

        if (!q.empty()) { // Check if the original queue is not empty
            q.push(q.front()); // Push from the second half
            q.pop();           // Remove the front element from the original queue
        }
    }
}

int main()
{
    queue<int> q;
    int n;

    cout << "Enter the number of integers (even): ";
    cin >> n;

    // Check for even number of integers
    if (n % 2 != 0) {
        cout << "Please enter an even number of integers." << endl;
        return 1; // Exit if the number is odd
    }

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num; 
        q.push(num);
    }

    interLeaveQueue(q);

    // Print the interleaved queue
    int length = q.size();
    cout << "Interleaved queue: ";
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl; 
    return 0;
}

