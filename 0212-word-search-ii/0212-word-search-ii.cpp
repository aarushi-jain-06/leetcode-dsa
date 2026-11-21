
class Solution {
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> result;

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r, int c, TrieNode* node) {

        char ch = board[r][c];
        int index = ch - 'a';

        TrieNode* next = node->children[index];

        if (next == nullptr) {
            return;
        }

        if (next->word != "") {
            result.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0 && board[r - 1][c] != '#')
            dfs(board, r - 1, c, next);

        if (r + 1 < rows && board[r + 1][c] != '#')
            dfs(board, r + 1, c, next);

        if (c > 0 && board[r][c - 1] != '#')
            dfs(board, r, c - 1, next);

        if (c + 1 < cols && board[r][c + 1] != '#')
            dfs(board, r, c + 1, next);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string word : words) {
            insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};
