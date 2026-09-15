class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

      
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }


        vector<int> dp(n + 1, 0);

        for (int end = 1; end <= n; end++) {
       
            dp[end] = dp[end - 1];

      
            for (int start = 0; start + k <= end; start++) {
                if (isPalindrome[start][end - 1]) {
                    dp[end] = max(dp[end], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};
