class Solution {
public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_set<int> numSet(arr.begin(), arr.end()); 
        int count = 0;

        for (int x : numSet) {
            if (numSet.find(x + k) != numSet.end()) {
                count += count_if(arr.begin(), arr.end(), [x](int n){ return n == x; }) * 
                         count_if(arr.begin(), arr.end(), [x, k](int n){ return n == x + k; });
            }
        }

        return count;
    }
};
