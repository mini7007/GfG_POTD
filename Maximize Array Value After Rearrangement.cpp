class Solution {
public:
    int mod = 1e9 + 7;

    int Maximize(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        unsigned long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            ans = (ans + arr[i] * 1ULL * i) % mod;
        }

        return ans;
    }
};
