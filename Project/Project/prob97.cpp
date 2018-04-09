//Brute Force(TLE)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0 && s2.size() == 0) 
            return s3.size() == 0;
        if (s3.size()==0) 
            return  !(s1.size() ||s2.size());
        
        int flag1= 0, flag2=0;
        if (s1.size()!=0) if (s1[0] == s3[0]) flag1 = isInterleave(s1.substr(1,s1.size()-1),s2,s3.substr(1,s3.size()));
        if (s2.size()!=0) if (s2[0] == s3[0]) flag2 = isInterleave(s1,s2.substr(1,s2.size()-1),s3.substr(1,s3.size()));
        
        return flag1 ||flag2;
    }
};

//1-d dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> dp (s2.size()+1,1);
        if (s1.size()+s2.size() != s3.size()) return 0;
        
        for (int i = 0; i<=s1.size(); i++)
            for (int j = 0; j<=s2.size(); j++)
            {
                int tmp = dp[j]; dp[j]=0;
                if (i == 0 && j == 0) {dp[j] = 1;continue;}
                if (i>0) if (s1[i-1] == s3[i+j-1] && tmp) dp[j] = 1;
                if (j>0) if (s2[j-1] == s3[i+j-1] && dp[j-1]) dp[j] =1;
            }
        return dp[s2.size()];
    }
};