class Solution {
public:
    int reverse(int x) {
        long long p = abs(x), q = 0;
        while (p>0){
            int tmp = p % 10;
            q = q*10 +tmp;
            p /=10;
        }
        if (q*x <0) q*=-1;
        int t = q;
        if (t!=q) return 0;
        return q;
    }
};