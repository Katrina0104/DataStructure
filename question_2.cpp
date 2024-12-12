// Katrina 1123521 deadline:12/12

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>  // For stringstream to split input
using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> bfs;               // Stores the BFS traversal result
    vector<bool> visited(V, false); // To keep track of visited nodes
    // Initialize a Boolean vector to record whether the node is accessed to prevent repeated processing of nodes during BFS or DFS, thereby ensuring the correctness and efficiency of the algorithm.
    queue<int> q;                  // Queue for BFS

    // Start BFS from vertex 0
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // Traverse all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor);         // Add to queue for further exploration
            }
        }
    }

    return bfs;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cin.ignore();  // To ignore the newline character after entering the number of vertices

    vector<vector<int>> adj(V);

    cout << "Enter the adjacency list for each vertex, with neighbors separated by spaces:" << endl;

    for (int i = 0; i < V; i++) {
        string line;
        cout << "Vertex " << i << ": ";
        getline(cin, line);  // Read the whole line of neighbors for vertex i

        stringstream ss(line);  // Use stringstream to parse the line
        int neighbor;
        while (ss >> neighbor) {
            adj[i].push_back(neighbor); // Add each neighbor to the adjacency list
        }
    }

    vector<int> result = bfsTraversal(V, adj);

    // Output the BFS traversal
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

