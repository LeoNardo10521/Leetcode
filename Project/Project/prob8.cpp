class Solution {
public:
    int myAtoi(string str) {
        int start = 0,flag = 1; 
        while (start<str.length() && str[start] == ' ') start++;
        if (start == str.length()) return 0;
        if (str[start] == '+') start++;
        else if (str[start] == '-') {start++; flag = -1;}
        else if (str[start] > '9' || str[start] < '0' ) return 0;
        long long res = 0;
        while (str[start] <= '9' && str[start] >= '0' && start<str.length() ){
            res = res*10 + str[start++] - '0';
            if (res*flag > INT_MAX) return INT_MAX;
            else if (res*flag<INT_MIN) return INT_MIN;
        }
        return flag*res;
    }
};