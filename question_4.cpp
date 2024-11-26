// Katrina 1123521 deadline : 11/28

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task with profit and deadline
struct Task {
    int profit;  // Profit of the task
    int deadline;  // Deadline of the task
};

// Comparison function to sort tasks in descending order of profit
bool compare(Task a, Task b) {
    return a.profit > b.profit;
}

// Function to schedule tasks to maximize profit
int scheduleTasks(vector<Task>& tasks, vector<int>& scheduledTasks) {
    // Sort tasks in descending order of profit
    sort(tasks.begin(), tasks.end(), compare);

    // This code loops through all tasks and finds the maximum deadline, so we know how many time slots are needed to schedule the task
    int maxDeadline = 0;
    for (const Task& task : tasks) {  // const Task& task : tasks is syntax for a range-based for loop  -> range-based means simplify the writing of the loop and directly traverse the container
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // We create a timeSlots vector to represent the status of each time slot, initialized to -1 to indicate that the time slot is not occupied
    vector<int> timeSlots(maxDeadline, -1);

    int totalProfit = 0;

    // Iterate through the sorted tasks
    for (const Task& task : tasks) {
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

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i]; 
        if (i < scheduledTasks.size() - 1) {
            cout << ", "; 
        }
    }
    cout << "]" << endl;

    return 0;
}
