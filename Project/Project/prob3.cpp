class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<int> q;
        int check[256];
        string ans;
        int len = 0;
        for(int i = 0; i<256; i++) check[i] = 0;
        for (int i = 0; i<s.length(); i++){
            q.push(s[i]);
            if (check[s[i]]) {
                while (q.front()!= s[i]) {check[q.front()] = 0; q.pop();}
                q.pop();
                continue;
            }
            check[s[i]] = 1; 
            if (len<q.size()) len = q.size();
        }
        return len;
        
    }
};

//Answer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int start = -1;
        int ans = 0;
        for (int i = 0; i<s.length(); i++){
            start = max(start, dict[s[i]]);
            ans = max(ans, i-start);
            dict[s[i]] = i;
        }
        return ans;
    }
};