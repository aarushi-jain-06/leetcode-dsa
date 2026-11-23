
class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                        vector<vector<int>>& stations) {

        int n = stations.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = startFuel;

        for (int i = 0; i < n; i++) {

            int position = stations[i][0];
            int fuel = stations[i][1];

            for (int stops = i; stops >= 0; stops--) {

                if (dp[stops] >= position) {

                    dp[stops + 1] = max(
                        dp[stops + 1],
                        dp[stops] + fuel
                    );
                }
            }
        }

        for (int stops = 0; stops <= n; stops++) {

            if (dp[stops] >= target) {
                return stops;
            }
        }

        return -1;
    }
};
