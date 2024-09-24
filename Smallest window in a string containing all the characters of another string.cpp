class Solution
{
    
   public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Edge case: if length of s is less than p, no such window is possible
        if (s.length() < p.length()) return "-1";

        // Frequency map for characters in p
        vector<int> freqP(26, 0);
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int required = p.length();  // total number of characters needed from p
        int left = 0, right = 0;    // two pointers
        int minLength = INT_MAX;    // to store the length of the smallest window
        int startIndex = -1;        // to store the starting index of the smallest window
        vector<int> windowFreq(26, 0); // frequency map for the current window

        // Sliding window
        while (right < s.length()) {
            // Expand the window by including s[right]
            windowFreq[s[right] - 'a']++;
            if (freqP[s[right] - 'a'] > 0 && windowFreq[s[right] - 'a'] <= freqP[s[right] - 'a']) {
                required--; // decrement required if we match a character from p
            }

            // Once all characters from p are matched, try to minimize the window
            while (required == 0) {
                // Update the minimum window if this window is smaller
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }

                // Shrink the window by moving left pointer
                windowFreq[s[left] - 'a']--;
                if (freqP[s[left] - 'a'] > 0 && windowFreq[s[left] - 'a'] < freqP[s[left] - 'a']) {
                    required++; // if a necessary character is removed, increment required
                }
                left++;
            }

            // Move right pointer to expand the window
            right++;
        }

        // If we found a valid window, return the substring, otherwise return "-1"
        return (startIndex == -1) ? "-1" : s.substr(startIndex, minLength);
    }
};
