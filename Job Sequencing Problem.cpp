class Solution {
public:
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > maxDeadline) {
                maxDeadline = arr[i].dead;
            }
        }
        vector<int> slot(maxDeadline + 1, -1);
        int jobCount = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobCount, totalProfit};
    }
};
