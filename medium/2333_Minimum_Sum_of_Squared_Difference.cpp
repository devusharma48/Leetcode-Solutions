class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            mx = max(mx, d);
        }

        long long sum = 0;
        for (int d : diff) sum += d;

        if (sum <= k) return 0;

        int l = 0, r = mx;

        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long need = 0, ans = 0;

        for (int d : diff) {
            if (d > l) need += d - l;
            int x = min(d, l);
            ans += 1LL * x * x;
        }

        long long rem = k - need;

        for (int d : diff) {
            if (rem == 0) break;
            if (d >= l && d > 0) {
                ans -= 2LL * l - 1;
                rem--;
            }
        }

        return ans;
    }
};
