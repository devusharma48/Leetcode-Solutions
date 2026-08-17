class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long long num = 0;

  
        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

       
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            num = num * 10 + digit;

     
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
