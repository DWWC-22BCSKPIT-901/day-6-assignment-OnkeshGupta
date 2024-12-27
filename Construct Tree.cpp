#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                          int preStart, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (preStart >= preorder.size() || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inIndex = inMap[root->val];

    root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, inIndex - 1, inMap);
    root->right = buildTreeHelper(preorder, inorder, preStart + 1 + inIndex - inStart, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1, inMap);
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    printInOrder(root);

    return 0;
}