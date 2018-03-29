class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string ans;
        for (int i = 0; i<s.length(); i++){
            int j = i,k = i;
            while (s[k+1] == s[k] && k<s.length()-1) k++;
            while (j>=1 && k<s.length()-1 && s[j-1] == s[k+1]) {j--;k++;}
            if (len<k-j+1) {
                len = k-j+1;
                ans = "";
                for (int t = j; t<=k; t++) ans+=s[t];
            }
        }
        return ans;
    }
};

//Answer
class Solution {
public:
    string preProcess(string s){
        int n = s.length();
        if (n == 0) return "^$";
        string res = "^";
        for (int i = 0; i<n; i++)
            res+= "#" + s.substr(i,1);
        res+="#$";
        return res;
    }
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        int *P = new int[n];
        int c = 0, len = 0,R = 0,resc = 0;
        
        for (int i = 1; i<n-1; i++){
            int tt = 2*c - i;
            P[i] = (R>i)?min(R-i,P[tt]):0;
            while (T[i-P[i]-1] == T[i+P[i]+1]) P[i]++;
            
            if (i+P[i]>R){
                c = i;
                R = i+P[i];
            }
        }
        
        for (int i =1; i<n-1; i++)
            if (P[i] >len) {
                resc = i;
                len = P[i];
            }
        delete [] P;
        
        return s.substr((resc-1-len)/2,len);
    }
};