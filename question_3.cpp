// Katrina 1123521 deadline:12/12

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

// Helper function to perform DFS traversal
void dfs(int node, const vector<vector<int>>& adj, unordered_set<int>& visited, vector<int>& result) {
    visited.insert(node);    // Mark the node as visited
    result.push_back(node);  // Add the node to the result

    // Explore each neighbor of the current node
    for (int neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adj, visited, result); // Recursively visit unvisited neighbors
        }
    }
}

// Main function to perform DFS traversal
vector<int> dfsTraversal(const vector<vector<int>>& adj) {
    int V = adj.size();
    unordered_set<int> visited; // Set to track visited nodes
    vector<int> result;         // Store the DFS traversal result

    dfs(0, adj, visited, result); // Start DFS from vertex 0

    return result; // Return the result of DFS traversal
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    cout << "Enter the adjacency list for each vertex (use space to separate neighbors), one vertex per line:" << endl;

    cin.ignore(); // Ignore the newline character left by cin

    for (int i = 0; i < V; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);   // Used to initialize stringstream and use line string as data source. This allows us to extract numbers or other data from the string one by one and process the contents of the string like a stream.
        int neighbor;   // determine the neighbor value
        while (ss >> neighbor) {
            adj[i].push_back(neighbor);
        }
    }

    // Get the DFS traversal result
    vector<int> result = dfsTraversal(adj);

    // Output the result
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

