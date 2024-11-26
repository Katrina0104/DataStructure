// Katrina 1123521  deadline: 11/28

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
Without pointers, the TreeNode structure would need to embed the entire left and right subtrees directly within itself.
This would result in inflexible and inefficient memory usage since every node would have to allocate space for potential child subtrees, even when those subtrees are not present.
*/

TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]); // take the first element's value(levelOrder[0]) to become the root
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* node = q.front();
        q.pop();  // bcs it already add

        if (levelOrder[i] != -1) {
            node->left = new TreeNode(levelOrder[i]);  // let's why i start from 1
            q.push(node->left);
        }
        i++;  // go to the next one

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            node->right = new TreeNode(levelOrder[i]);
            q.push(node->right);
        }
        i++;
    } // add from left to right

    return root;
}

int diameterOfBinaryTree(TreeNode* root, int& diameter) {   // Because it is a reference (&), it will be continuously updated during the recursion process, recording the currently found maximum diameter.
    if (!root) return 0;   // if it's nullptr return 0

    int leftHeight = diameterOfBinaryTree(root->left, diameter);
	/* Call itself, passing in the left child node root->left of the current node as the new root node.
       In this recursion, the program will try to calculate the height of the left subtree and check whether the diameter needs to be updated.*/
    int rightHeight = diameterOfBinaryTree(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;  // the function to count
}

int main() {
    vector<int> levelOrder;
    cout << "Enter level-order traversal (use -1 for null nodes): ";
    int value;
    while (cin >> value) levelOrder.push_back(value);  // we need to use ctrl+z to stop the input (for windows)

    TreeNode* root = buildTree(levelOrder);

    int diameter = 0;  // initialization
    diameterOfBinaryTree(root, diameter);

    cout << "Diameter of the Binary Tree: " << diameter << endl;
    return 0;
}

