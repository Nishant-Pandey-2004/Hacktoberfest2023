#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool searchInBinaryTree(TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    bool leftResult = searchInBinaryTree(root->left, target);
    bool rightResult = searchInBinaryTree(root->right, target);

    return leftResult || rightResult;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    int target = 7;
    if (searchInBinaryTree(root, target)) {
        std::cout << target << " found in the binary tree." << std::endl;
    } else {
        std::cout << target << " not found in the binary tree." << std::endl;
    }

    return 0;
}
