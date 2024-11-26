#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a task with profit and deadline
struct Task {
    int profit;  // Profit of the task
    int deadline;  // Deadline of the task
};

// Comparison function to create a max-heap based on profit
struct CompareProfit {
    bool operator()(const Task& a, const Task& b) {   // define operator ()
        return a.profit < b.profit;  // If a.profit < b.profit, a will be placed after b
    }
};

// Function to schedule tasks using a Max Priority Queue
int scheduleTasks(vector<Task>& tasks, vector<int>& scheduledTasks) {
    // Create a max-heap (priority queue) to store tasks sorted by profit
    priority_queue<Task, vector<Task>, CompareProfit> maxHeap;    // to make the elements from big to small ex : [140, 130, 120, 100, 90] (from example)

    // Push all tasks into the priority queue
    for (const Task& task : tasks) {
        maxHeap.push(task);
    }

    // Find the maximum deadline to determine the number of time slots
    int maxDeadline = 0;
    for (const Task& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // Create an array to represent time slots, initialized to -1 (unoccupied)
    vector<int> timeSlots(maxDeadline, -1);

    int totalProfit = 0;

    // Process tasks from the max-heap
    while (!maxHeap.empty()) {   
        Task task = maxHeap.top();  // Get the task with the highest profit
        maxHeap.pop();  // Remove the task from the heap

        // Start from the task's deadline and find an available time slot
        for (int j = task.deadline - 1; j >= 0; --j) {
            if (timeSlots[j] == -1) { // If the time slot is unoccupied
                timeSlots[j] = task.profit; // Assign the task to this slot
                totalProfit += task.profit; // Add the profit to the total profit
                scheduledTasks.push_back(task.profit); // Record the scheduled task's profit
                break; // Move to the next task
            }
        }
    }

    return totalProfit;
}

int main() {
    int N; // Number of tasks
    cout << "Enter the number of tasks: ";
    cin >> N;

    vector<Task> tasks(N); // Vector to store all tasks
    cout << "Enter each task's profit and deadline:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline; // Input each task's profit and deadline
    }

    vector<int> scheduledTasks; // Vector to store the scheduled tasks
    int maxProfit = scheduleTasks(tasks, scheduledTasks); // Schedule tasks and calculate the maximum profit

    // Output the results
    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i]; // Print the profit of each scheduled task
        if (i < scheduledTasks.size() - 1) {
            cout << ", "; // Add a comma between task profits
        }
    }
    cout << "]" << endl;

    return 0;
}
