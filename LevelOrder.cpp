#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class LevelOrder {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return std::vector<std::vector<int>>();

        std::queue<TreeNode*> que;
        que.push(root);
        std::vector<std::vector<int>> ans;

        while (!que.empty()) {
            int size = que.size();
            std::vector<int> smallAns;

            while (size-- > 0) {
                TreeNode* rNode = que.front();
                que.pop();
                smallAns.push_back(rNode->val);

                if (rNode->left != nullptr)
                    que.push(rNode->left);
                if (rNode->right != nullptr)
                    que.push(rNode->right);
            }
            ans.push_back(smallAns);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    LevelOrder levelOrder;

    std::vector<std::vector<int>> result = levelOrder.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
