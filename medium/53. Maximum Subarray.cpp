/*
    LeetCode 53 - Maximum Subarray

    Approach:
    - Use Kadane's Algorithm.
    - Maintain a running sum (currentSum).
    - If currentSum becomes negative, reset it to 0 because
      a negative sum cannot help in getting a larger subarray sum.
    - Keep track of the maximum sum found so far.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];

            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};
