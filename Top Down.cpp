class Solution {
public:
    int dp[366];  // DP array to memoize minimum cost starting from each index (up to 365 travel days)

    // Recursive function to find the minimum cost of tickets starting from day index i
    int hlo(vector<int>& days, vector<int>& costs, int i) {
        // Base case: if all travel days are covered
        if (i >= days.size())
            return 0;

        // If already computed for index i, return cached result
        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX; // To store minimum cost among all ticket choices
        int valid[] = {1, 7, 30}; // Ticket validity in days

        // Try all 3 types of tickets: 1-day, 7-day, 30-day
        for (int j = 0; j < costs.size(); j++) {
            int maxdays = days[i] + valid[j] - 1;  // Last day the current ticket is valid
            int k = i;

            // Find the next index (k) where the travel day is not covered by the current ticket
            while (k < days.size() && days[k] <= maxdays) {
                k++;
            }

            // Recursively calculate cost starting from index k, add current ticket cost
            mini = min(mini, costs[j] + hlo(days, costs, k));
        }

        // Store and return the computed minimum cost for index i
        return dp[i] = mini;
    }

    // Main function that initializes memoization and starts recursion
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));  // Initialize all dp values to -1
        return hlo(days, costs, 0);  // Start recursion from index 0
    }
};
