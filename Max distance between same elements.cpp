class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> firstOccurrence;  // To store the first occurrence of each element
        int maxDist = 0;

        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // If element has been seen before, calculate the distance
            if (firstOccurrence.find(arr[i]) != firstOccurrence.end()) {
                maxDist = max(maxDist, i - firstOccurrence[arr[i]]);
            } else {
                // Otherwise, store the index of the first occurrence
                firstOccurrence[arr[i]] = i;
            }
        }

        return maxDist;
    }
};
