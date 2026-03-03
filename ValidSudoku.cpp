class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                if (rows[r].count(ch)) return false;
                rows[r].insert(ch);

                if (cols[c].count(ch)) return false;
                cols[c].insert(ch);

                int b = (r / 3) * 3 + (c / 3);
                if (boxes[b].count(ch)) return false;
                boxes[b].insert(ch);
            }
        }
        return true;
    }
};
