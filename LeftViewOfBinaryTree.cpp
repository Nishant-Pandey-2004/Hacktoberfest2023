#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

class LeftViewOfBinaryTree {
public:
    std::vector<int> leftView(Node* root) {
        std::vector<int> ans;
        if (root == nullptr) return ans;
        std::queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            ans.push_back(que.front()->data);
            while (size-- > 0) {
                Node* rNode = que.front();
                que.pop();

                if (rNode->left != nullptr) que.push(rNode->left);
                if (rNode->right != nullptr) que.push(rNode->right);
            }
        }
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    LeftViewOfBinaryTree tree;

    std::vector<int> leftViewList = tree.leftView(root);

    std::cout << "Left View of the Binary Tree: ";
    for (int value : leftViewList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
