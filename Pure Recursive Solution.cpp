class Solution {
public:
    // Recursive helper function to compute minimum cost
    int hlo(vector<int>& days, vector<int>& costs, int i, int havetill) {
        // Base case: if we've processed all travel days, no more cost needed
        if (i >= days.size())
            return 0;

        int mini = INT_MAX; // Initialize minimum cost to a large value
        int valid[] = {1, 7, 30}; // Valid durations for each type of ticket

        // Try all 3 types of tickets: 1-day, 7-day, 30-day
        for (int j = 0; j < costs.size(); j++) {
            if (havetill >= days[i]) {
                // If current ticket already covers this day, move to next day without buying new ticket
                mini = min(mini, hlo(days, costs, i + 1, havetill));
            } else {
                // Otherwise, buy a new ticket of duration valid[j]
                // and update havetill to the last day this new ticket will be valid
                mini = min(mini, costs[j] + hlo(days, costs, i + 1, days[i] + valid[j] - 1));
            }
        }
        return mini; // Return the minimum cost found
    }

    // Main function to compute minimum cost for all travel days
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Start from day 0 with no valid ticket (-1)
        return hlo(days, costs, 0, -1);
    }
};
