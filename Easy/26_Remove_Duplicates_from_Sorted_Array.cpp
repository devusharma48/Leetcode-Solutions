class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;

        for (int num : nums) {
            if (k == 0 || nums[k - 1] != num) {
                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};
