class Solution {
public:
    vector<string> ans;

    void dfs(string s, int start, int last, char open, char close) {
        int balance = 0;

        for (int i = start; i < s.size(); i++) {
            if (s[i] == open) balance++;
            if (s[i] == close) balance--;

            if (balance >= 0) continue;

            for (int j = last; j <= i; j++) {
                if (s[j] == close && (j == last || s[j - 1] != close)) {
                    string t = s.substr(0, j) + s.substr(j + 1);
                    dfs(t, i, j, open, close);
                }
            }

            return;
        }

        string rev = s;
        
        reverse(rev.begin(), rev.end());

        if (open == '(') {
            dfs(rev, 0, 0, ')', '(');
        } else {
            ans.push_back(rev);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, 0, '(', ')');
        return ans;
    }
};
