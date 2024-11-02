class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;

        for (int i = 0; i < arr.size(); ++i) {
            if (window.count(arr[i])) {
                return true;
            }
            window.insert(arr[i]);
            if (i >= k) {
                window.erase(arr[i - k]);
            }
        }
        return false;
    }
};
