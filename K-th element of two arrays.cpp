class Solution {
public:
    int kth(vector<int>& arr1, vector<int>& arr2, int s1, int e1, int s2, int e2, int k) {
        if (s1 >= e1) return arr2[s2 + k];
        if (s2 >= e2) return arr1[s1 + k];
        int mid1 = (e1 - s1) / 2;
        int mid2 = (e2 - s2) / 2;
        if (mid1 + mid2 < k) {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, e1, s2 + mid2 + 1, e2, k - mid2 - 1);
            } else {
                return kth(arr1, arr2, s1 + mid1 + 1, e1, s2, e2, k - mid1 - 1);
            }
        } else {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, s1 + mid1, s2, e2, k);
            } else {
                return kth(arr1, arr2, s1, e1, s2, s2 + mid2, k);
            }
        }
    }

    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        return kth(arr1, arr2, 0, n, 0, m, k - 1);
    }
};
