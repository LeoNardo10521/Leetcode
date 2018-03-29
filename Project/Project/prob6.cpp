class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 ) return s;
        string res[numRows];
        string ans;
        int pos = 0,dir = 1;
        for (int i = 0; i<s.length(); i++){
            res[pos]+=s.substr(i,1);
            pos+=dir;
            if ((i+1) % (numRows-1) == 0) dir *= -1;
            
        }
        for(int i = 0; i<numRows; i++) {
            ans += res[i];
        }
        return ans;
    }
};