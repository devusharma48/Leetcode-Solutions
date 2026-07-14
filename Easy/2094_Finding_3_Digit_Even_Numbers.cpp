class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        vector<int> ans;

        for (int num = 100; num <= 998; num += 2) {

            vector<int> cnt(10, 0);

            int temp = num;

            cnt[temp % 10]++;
            temp /= 10;

            cnt[temp % 10]++;
            temp /= 10;

            cnt[temp % 10]++;

            bool possible = true;

            for (int i = 0; i < 10; i++) {
                if (cnt[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans.push_back(num);
        }

        return ans;
    }
};
