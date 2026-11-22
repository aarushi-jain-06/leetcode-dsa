
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<bool>> visited(
            n, vector<bool>(n, false)
        );

        pq.push({grid[0][0], {0, 0}});

        int directions[4][2] = {
            {1, 0}, {-1, 0},
            {0, 1}, {0, -1}
        };

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int time = current.first;
            int r = current.second.first;
            int c = current.second.second;

            if (visited[r][c]) {
                continue;
            }

            visited[r][c] = true;

            if (r == n - 1 && c == n - 1) {
                return time;
            }

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    int newTime = max(
                        time, grid[nr][nc]
                    );

                    pq.push({
                        newTime,
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};
