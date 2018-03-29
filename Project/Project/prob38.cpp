class Solution {
public:
    string countAndSay(int n) {
        string s ="1";
        for (int i = 1; i<n; i++)
        {
            string tmp = ""; 
            int j = 0, l = s.length();
            while (j<l){
                char c = s[j];
                int t = j;
                while (s[t] == s[t+1]) t++;
                tmp = tmp +  (char)(t-j+1 + '0') + s[j];
                j = t+1;
        }
            s = tmp;
        }
        return s;
    }
        
};