
class Solution {
public:
    unordered_map<string, priority_queue<string,
        vector<string>, greater<string>>> graph;

    vector<string> route;

    void dfs(string airport) {

        auto& destinations = graph[airport];

        while (!destinations.empty()) {

            string next = destinations.top();
            destinations.pop();

            dfs(next);
        }

        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());

        return route;
    }
};
