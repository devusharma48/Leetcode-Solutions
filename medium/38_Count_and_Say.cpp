class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";

            for (int j = 0; j < result.size();) {
                int count = 0;
                char digit = result[j];

                while (j < result.size() && result[j] == digit) {
                    count++;
                    j++;
                }

                next += to_string(count);
                next += digit;
            }

            result = next;
        }

        return result;
    }
};
