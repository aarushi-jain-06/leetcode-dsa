
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) {
            return 0;
        }

        // {height, row, column}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        // Add all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int directions[4][2] = {
            {1, 0}, {-1, 0},
            {0, 1}, {0, -1}
        };

        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n ||
                    visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;

                int neighborHeight = heightMap[nr][nc];

                if (neighborHeight < height) {
                    water += height - neighborHeight;
                }

                int effectiveHeight = max(
                    height, neighborHeight
                );

                pq.push({
                    effectiveHeight,
                    nr,
                    nc
                });
            }
        }

        return water;
    }
};
