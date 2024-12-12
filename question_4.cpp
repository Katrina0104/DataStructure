// Katrina 1123521 deadline:12/12

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint Set (Union-Find) Data Structure
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int V) {
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i; // Each vertex is its own parent initially
        }
    }

    // Find the root of the set containing x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Union by rank to merge two sets
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int kruskalMST(int V, vector<vector<pair<int, int>>>& adj) {
    // Step 1: Convert adjacency list to edge list
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}
    for (int u = 0; u < V; u++) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (u < v) {  // To avoid adding both directions (u-v and v-u)
                edges.push_back({weight, {u, v}});
            }
        }
    }

    // Step 2: Sort edges by weight
    sort(edges.begin(), edges.end());

    // Step 3: Initialize Union-Find
    DisjointSet ds(V);
    int mstWeight = 0;

    // Step 4: Process each edge
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // If u and v are in different sets, add this edge to MST
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mstWeight += weight;  // Add the weight of the edge to MST
        }
    }

    return mstWeight;
}

int main() {
    int V, E;

    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);  // Adjacency list to store graph

    cout << "Enter the edges (u, v, weight) for each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});  // Add edge u-v with weight
        adj[v].push_back({u, weight});  // Add edge v-u with weight (undirected graph)
    }

    // Find the MST weight
    int mstWeight = kruskalMST(V, adj);

    // Output the weight of the MST
    cout << "Weight of the MST: " << mstWeight << endl;

    return 0;
}

