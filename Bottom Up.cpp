class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Find the last day of travel to determine size of DP array
        int lastday = days[days.size() - 1];

        // DP array to store minimum cost up to each day
        vector<int> dp(lastday + 1, 0);

        // Set to quickly check if a day is a travel day
        unordered_set<int> st;
        for (int i = 0; i < days.size(); i++) {
            st.insert(days[i]);
        }

        // Iterate over each day from 1 to last travel day
        for (int i = 1; i <= lastday; i++) {

            // If today is not a travel day, cost remains same as previous day
            if (st.find(i) == st.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            // Initialize cost for today as infinite
            int cost = INT_MAX;

            // Ticket durations: 1-day, 7-day, and 30-day
            int duration[] = {1, 7, 30};

            // Try all three types of tickets
            for (int j = 0; j < 3; j++) {
                int prevDay = i - duration[j];

                // If the previous day is valid, use its cost
                if (prevDay >= 0) {
                    cost = min(cost, costs[j] + dp[prevDay]);
                } 
                // If previous day is negative, it means ticket covers from day 0
                else {
                    cost = min(cost, costs[j]);
                }
            }

            // Store the minimum cost for day i
            dp[i] = cost;
        }

        // Return minimum cost to cover all travel days
        return dp[lastday];
    }
};
