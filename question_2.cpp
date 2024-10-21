#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;

    // push the first element to stack
    s.push(arr[0]);  // Establish a "wait for comparison" mechanism 

    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        // pop elements from the stack smaller than arr[i]
        while (!s.empty() && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        // push the current element onto the stack
        s.push(arr[i]);
    }

    // print -1 for elements remaining in the stack
    while (!s.empty()) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int n;
    
    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // Declare array of size n

    // Input elements into the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to print NGE
    printNGE(arr, n);
    
    return 0;
}

