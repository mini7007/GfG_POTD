class Solution {
public:
    bool isLeaf(Node* node) {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }

    bool checkSumTree(Node* node, int &sum) {
        if (node == nullptr) {
            sum = 0;
            return true;
        }
        if (isLeaf(node)) {
            sum = node->data;
            return true;
        }

        int leftSum = 0, rightSum = 0;

        if (checkSumTree(node->left, leftSum) && checkSumTree(node->right, rightSum)) {
            sum = node->data + leftSum + rightSum;
            return node->data == leftSum + rightSum;
        }

        return false;
    }

    bool isSumTree(Node* root) {
        int sum = 0;
        return checkSumTree(root, sum);
    }
};
