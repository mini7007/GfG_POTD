class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Modify the array based on the given rules
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;  // Double the current element
                arr[i + 1] = 0;  // Set the next element to 0
            }
        }

        // Step 2: Rearrange by shifting non-zero elements forward
        int index = 0;  // Pointer to place the next non-zero element

        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }

        // Step 3: Fill the rest of the array with zeros
        while (index < n) {
            arr[index++] = 0;
        }

        return arr;
    }
};
