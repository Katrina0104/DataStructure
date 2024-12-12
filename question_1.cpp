// Katrina 1123521 deadline:12/12

#include <iostream>
#include <vector>
using namespace std;

void getAdjacencyList(vector<pair<int, int>>& edges,
                      vector<vector<int>>& adj)
{
    for (auto edge : edges) {
        // For edge [u, v], push v to the
        // list at index u
        adj[edge.first].push_back(edge.second);

        // For edge [u, v], push u to the
        // list at index v
        adj[edge.second].push_back(edge.first);
    }
}

// Driver's code
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    /*The size V of the outer vector represents the number of nodes, and adj[i] represents the adjacent nodes of node i.
The inner vector<int> is used to store the node number adjacent to a node*/
    vector<pair<int, int>> edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    getAdjacencyList(edges, adj);

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << ": [";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if (j + 1 < adj[i].size()) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
