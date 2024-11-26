// Katrina 1123521  deadline:11/28

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>   //A string stream used to parse input commands
#include <algorithm>
using namespace std;

struct Task {
    int priority;
    string name;

    // Custom comparator for max-heap behavior
    bool operator<(const Task& other) const {   // determine the operator < 
        return priority < other.priority;
    }
};

int main() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    cin.ignore();

    priority_queue<Task> maxHeap; // Max-heap to store tasks
    vector<string> results;      // Store results for "GET" operations

    for (int i = 0; i < n; ++i) {
        string operation;
        getline(cin, operation);  // read every line

        stringstream ss(operation);  // Creates a stringstream object ss and initializes it as an operation string. This way, you can decompose the operation string into its components as if it were reading data from standard input.
        string command;
        ss >> command;  // Extracts a word (or a string separated by whitespace characters) from the stringstream object ss and assigns it to the variable command

        if (command == "ADD") {
            string task_name;
            int priority;
            ss >> task_name >> priority;
            maxHeap.push({priority, task_name});
        } else if (command == "GET") {
            if (!maxHeap.empty()) {
                Task topTask = maxHeap.top();
                maxHeap.pop();
                results.push_back(topTask.name);
            } else {
                results.push_back("No tasks available");
            }
        }
    }
    
    cout << endl; 
    cout << "Output : " << endl;
    for (const string& result : results) {
        cout << result << endl;
    }

    // Remaining tasks in descending order of priority
    vector<Task> remainingTasks;
    while (!maxHeap.empty()) {
        remainingTasks.push_back(maxHeap.top());
        maxHeap.pop();
    }

    sort(remainingTasks.rbegin(), remainingTasks.rend(), [](const Task& a, const Task& b) {
        return a.priority < b.priority;
    });

    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i != remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
