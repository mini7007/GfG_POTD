class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<int> reordered;
        
        // Rearrange by alternating smallest and largest elements
        int i = 0, j = n - 1;
        while (i <= j) {
            if (i != j) {
                reordered.push_back(arr[i++]);
                reordered.push_back(arr[j--]);
            } else {
                reordered.push_back(arr[i++]);  // Add middle element if odd size
            }
        }

        // Calculate maximum absolute difference sum in circular manner
        long long maxSum = 0;
        for (int k = 0; k < n; ++k) {
            maxSum += abs(reordered[k] - reordered[(k + 1) % n]);
        }

        return maxSum;
    }
};
