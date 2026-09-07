class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long answer = 0;

        for (int i = 31; i >= 0; i--) {
            if ((b << i) <= a) {
                a -= (b << i);
                answer += (1LL << i);
            }
        }

        if ((dividend < 0) ^ (divisor < 0))
            answer = -answer;

        return (int)answer;
    }
};
