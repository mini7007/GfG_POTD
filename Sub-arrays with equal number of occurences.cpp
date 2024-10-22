class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> prefixDiffCount;
        prefixDiffCount[0] = 1; // Initialize with diff = 0 seen once.
        
        int diff = 0;  // Difference between occurrences of x and y.
        int count = 0; // To store the final result.

        for (int num : arr) {
            // Update the difference based on the current element.
            if (num == x) diff++;
            else if (num == y) diff--;

            // If this difference has been seen before, add the count to the result.
            if (prefixDiffCount.find(diff) != prefixDiffCount.end()) {
                count += prefixDiffCount[diff];
            }

            // Increment the occurrence of the current difference.
            prefixDiffCount[diff]++;
        }

        return count;
    }
};
