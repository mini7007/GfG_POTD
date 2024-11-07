class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // If the total sum is not divisible by 3, return {-1, -1}
        if (totalSum % 3 != 0) {
            return {-1, -1};
        }

        int targetSum = totalSum / 3;
        int sum = 0;
        int firstIndex = -1, secondIndex = -1;

        // Find two points where each partition has the target sum
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Find the first partition
            if (sum == targetSum && firstIndex == -1) {
                firstIndex = i;
            }
            // Find the second partition after the first
            else if (sum == 2 * targetSum && firstIndex != -1) {
                secondIndex = i;
                return {firstIndex, secondIndex};  // Return the valid (i, j) pair
            }
        }

        // If no valid split is found, return {-1, -1}
        return {-1, -1};
    }
};
