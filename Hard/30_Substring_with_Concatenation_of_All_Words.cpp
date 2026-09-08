class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLength = words[0].size();
        int totalWords = words.size();

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        for (int start = 0; start < wordLength; start++) {
            int left = start;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = start; right + wordLength <= s.size();
                 right += wordLength) {

                string word = s.substr(right, wordLength);

                if (required.count(word)) {
                    current[word]++;
                    count++;

                    while (current[word] > required[word]) {
                        string leftWord = s.substr(left, wordLength);
                        current[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    if (count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLength);
                        current[leftWord]--;
                        left += wordLength;
                        count--;
                    }
                } 
                else {
                    current.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }

        return ans;
    }
};
