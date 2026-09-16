class Solution {
public:
    static const int MOD = 1000000007;

    long long modularPower(long long base, long long exponent) {
        long long answer = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                answer = (answer * base) % MOD;
            }

            base = (base * base) % MOD;
            exponent /= 2;
        }

        return answer;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int selected = 2 * k;

        vector<long long> factorial(total + 1);
        factorial[0] = 1;

        for (int i = 1; i <= total; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        long long numerator = factorial[total];

        long long denominator =
            (factorial[selected] * factorial[total - selected]) % MOD;

        long long denominatorInverse =
            modularPower(denominator, MOD - 2);

        return (numerator * denominatorInverse) % MOD;
    }
};
