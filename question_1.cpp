#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insert_at_bottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    // Hold the top element and pop it
    int a = st.top();
    st.pop();

    // Recursively call to insert at the bottom
    insert_at_bottom(st, x);

    // Push the top element back after inserting the new element at the bottom
    st.push(a);
}

// Function to reverse the given stack using insert_at_bottom()
void reverse(stack<int>& st) {
    if (st.empty()) return;

    // Hold the top element and pop it
    int x = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverse(st);

    // Insert the popped element at the bottom of the reversed stack
    insert_at_bottom(st, x);
}

// Driver Code
int main() {
    stack<int> st;
    int n, value;

    // Get the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Get the stack elements from the user
    cout << "Enter the elements (bottom to top): ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        st.push(value);  // Push the elements into the stack
    }

    // Copy the original stack to display before reversal
    stack<int> st2 = st;

    cout << "Original Stack (top to bottom): ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    // Reverse the stack
    reverse(st);

    // Print the reversed stack
    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

