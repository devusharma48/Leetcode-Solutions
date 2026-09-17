class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9);
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        
        int current_sum = 0;
        int ans = 1e9;
        int current_min_len = 1e9;
        
        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            int complement = current_sum - target;
            
            if (prefix_map.count(complement)) {
                int start_idx = prefix_map[complement] + 1;
                int len = i - start_idx + 1;
                
                if (start_idx > 0 && min_len[start_idx - 1] != 1e9) {
                    ans = min(ans, len + min_len[start_idx - 1]);
                }
                
                current_min_len = min(current_min_len, len);
            }
            
            min_len[i] = current_min_len;
            prefix_map[current_sum] = i;
        }
        
        return ans >= 1e9 ? -1 : ans;
    }
};
