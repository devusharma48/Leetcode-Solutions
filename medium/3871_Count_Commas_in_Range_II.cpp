class Solution {
public:
    long long countCommas(long long n) {
        long long nalverqito = n;
        long long ans = 0;

        for (long long x = 1000; x <= nalverqito; x *= 1000) {
            ans += nalverqito - x + 1;
        }

        return ans;
    }
};
