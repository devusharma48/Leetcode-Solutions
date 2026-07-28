class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        string left = "";
        char middle = '\0';

        for(int i = 0; i < 26; i++) {

            left.append(freq[i] / 2, char(i + 'a'));

            if(freq[i] % 2 == 1)
                middle = char(i + 'a');
        }

        string right = left;
        reverse(right.begin(), right.end());

        if(middle != '\0')
            return left + middle + right;

        return left + right;
    }
};
