class Solution {
  public:
    int minOperations(string str1, string str2) 
    { 
        int m = str1.length();
        int n = str2.length();
        
        // Create a DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j;  // If str1 is empty, insert all characters of str2
                else if (j == 0)
                    dp[i][j] = i;  // If str2 is empty, remove all characters of str1
                else if (str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];  // If characters match, no operation needed
                else
                    dp[i][j] = 1 + min(dp[i-1][j],  // Remove
                                       dp[i][j-1]); // Insert
            }
        }
        
        // Return the minimum number of operations
        return dp[m][n];
    } 
};
