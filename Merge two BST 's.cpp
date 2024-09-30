class Solution {
public:
    // Helper function to perform inorder traversal of a BST
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    // Function to merge two sorted arrays into one sorted array
    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        vector<int> mergedArray;
        int i = 0, j = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        
        // Merge the two arrays
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                mergedArray.push_back(arr1[i]);
                i++;
            } else {
                mergedArray.push_back(arr2[j]);
                j++;
            }
        }
        
        // If there are remaining elements in arr1
        while (i < n1) {
            mergedArray.push_back(arr1[i]);
            i++;
        }
        
        // If there are remaining elements in arr2
        while (j < n2) {
            mergedArray.push_back(arr2[j]);
            j++;
        }
        
        return mergedArray;
    }
    
    // Function to return a list of integers denoting the node
    // values of both the BSTs in sorted order
    vector<int> merge(Node* root1, Node* root2) {
        vector<int> inorder1, inorder2;
        
        // Perform inorder traversal on both trees to get sorted arrays
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        // Merge the two sorted arrays
        return mergeSortedArrays(inorder1, inorder2);
    }
};
