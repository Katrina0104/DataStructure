# DataStructure HW3
katrina 1123521 

Question: 1
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input:
V = 5, E = 7
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
![image](https://github.com/user-attachments/assets/d95991d4-fcf6-4e1f-abb5-0b7715ee1c69)

Output: 
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.

--------------------------------------------------------------------
Input:
V = 4, E = 4
edges = [[0,1], [1,2], [1,3], [2,3]]

Output: 
[[1], [0,2,3], [1,3], [1,2]]
Explanation:
Node 0 is connected to 1.
Node 1 is connected to 0,2,3.
Node 2 is connected to 1,3.
Node 3 is connected to 1,2.

 
Question: 2
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input: adj = [[2,3,1], [0], [0,4], [0], [2]]
![image](https://github.com/user-attachments/assets/c39425ff-f046-4a96-a67e-52a639567871)

Output: [0, 2, 3, 1, 4]
Explanation: 
Starting from 0, the BFS traversal will follow these steps: 
Visit 0 → Output: 0 
Visit 2 (first neighbor of 0) → Output: 0, 2 
Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4

-----------------------------------------------------------------------
Input: adj = [[2,3,1], [0], [0,4], [0, 5], [2], [3]]

Output: [0, 2, 3, 1, 4, 5]
Explanation: 
Starting from 0, the BFS traversal will follow these steps: 
Visit 0 → Output: 0 
Visit 2 (first neighbor of 0) → Output: 0, 2 
Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
Visit 5 (neighbor of 3) → Final Output: 0, 2, 3, 1, 4, 5


Question: 3
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
![image](https://github.com/user-attachments/assets/1a015387-dab1-43d0-a2dd-baaf69d54b40)

Output: [0, 1, 2, 3, 4]
Explanation: 
Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4

--------------------------------------------------------------------
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2, 5], [2],[3]]

Output: [0, 1, 2, 3, 4, 5]
Explanation: 
Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Visit 5 (the first neighbor of 3) → Output: 0, 1, 2, 3, 5
Backtrack to 3 then 2 and visit 4 → Final Output: 0, 1, 2, 3, 5, 4


Question: 4
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input:
V = 3, E = 3
0 1 5
1 2 3
0 2 1
![image](https://github.com/user-attachments/assets/46a6861d-5c27-480c-90a2-c24a160d86d4)

Output:
4
Explanation:
![image](https://github.com/user-attachments/assets/d21170fa-5cea-4c55-9337-6e228c216dc3)
The Spanning Tree resulting in a weight of 4 is shown above.

--------------------------------------------------------------------
Input:
V = 4, E = 5
0 1 5
0 2 1
1 3 4
1 2 3
2 3 6

Output:
8
Explanation:
The Spanning Tree resulting in a weight of 8 is shown above.




