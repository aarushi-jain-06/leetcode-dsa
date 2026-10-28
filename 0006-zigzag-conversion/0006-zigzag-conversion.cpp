
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = 1;

        for (int i = 0; i < s.length(); i++) {
            rows[currentRow] += s[i];

            if (currentRow == 0) {
                direction = 1;
            } else if (currentRow == numRows - 1) {
                direction = -1;
            }

            currentRow += direction;
        }

        string result = "";

        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }

        return result;
    }
};
