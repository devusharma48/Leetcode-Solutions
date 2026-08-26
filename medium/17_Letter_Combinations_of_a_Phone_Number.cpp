class Solution {
public:
    vector<string> result;

    void solve(int index, string& digits, string& current,
               vector<string>& keypad) {
        
        
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        
        string letters = keypad[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);                  
            solve(index + 1, digits, current, keypad);
            current.pop_back();                    
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> keypad = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        string current = "";
        solve(0, digits, current, keypad);

        return result;
    }
};
