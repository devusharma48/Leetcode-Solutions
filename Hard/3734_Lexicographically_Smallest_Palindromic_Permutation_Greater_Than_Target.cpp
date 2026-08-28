class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int oddCount = 0;
        int middleChar = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                middleChar = i;
            }
        }

        if (oddCount > 1) {
            return "";
        }

        auto calendrix = make_pair(s, target);
        const string& t = calendrix.second;

        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int half = n / 2;
        string answer(n, ' ');

        auto buildPalindrome = [&]() {
            if (middleChar != -1) {
                answer[half] = char('a' + middleChar);
            }

            for (int i = 0; i < half; i++) {
                answer[n - 1 - i] = answer[i];
            }
        };

        int position = 0;

        while (position < half) {
            int current = t[position] - 'a';

            if (freq[current] == 0) {
                break;
            }

            answer[position] = t[position];
            freq[current]--;
            position++;
        }

        if (position == half) {
            buildPalindrome();

            if (answer > t) {
                return answer;
            }
        }

        while (true) {
            if (position < half) {
                int start = t[position] - 'a' + 1;

                for (int ch = start; ch < 26; ch++) {
                    if (freq[ch] == 0) {
                        continue;
                    }

                    answer[position] = char('a' + ch);
                    freq[ch]--;

                    int index = position + 1;

                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            answer[index++] = char('a' + c);
                            freq[c]--;
                        }
                    }

                    buildPalindrome();
                    return answer;
                }
            }

            if (position == 0) {
                return "";
            }

            position--;
            freq[t[position] - 'a']++;
        }
    }
};
