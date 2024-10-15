class Solution {
  public:
    // Function to count the number of subarrays which add to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int, int> prefixSumFreq;  // Stores prefix sum frequencies
        int prefix_sum = 0;  // Stores the cumulative sum of elements
        int count = 0;  // Stores the number of subarrays with sum = tar

        // Initialize the map with prefix_sum 0 to handle cases where a subarray from the start equals tar.
        prefixSumFreq[0] = 1;

        for (int num : arr) {
            prefix_sum += num;  // Update the prefix sum

            // Check if (prefix_sum - tar) exists in the map
            if (prefixSumFreq.find(prefix_sum - tar) != prefixSumFreq.end()) {
                count += prefixSumFreq[prefix_sum - tar];
            }

            // Update the frequency of the current prefix_sum in the map
            prefixSumFreq[prefix_sum]++;
        }

        return count;
    }
};
