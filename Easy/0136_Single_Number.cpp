class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;  // its a xor operation in the array..!
        }

        return ans;
    }
};
