//My work
class Solution {
public:
    bool count(string s1, string s2){
        
        unordered_map <char, int> record1;
        unordered_map <char, int> record2;
        for (int i = 0; i<s1.length(); i++)
            record1[s1[i]]++;
        for (int i = 0; i<s2.length(); i++)
            record2[s2[i]]++; 
        if (record2 != record1) return 0;
        else return 1;
    }
    
    bool jud(string s1, string s2){
        int l = s1.length();
        if (l == 1) return s1[0] == s2[0];
       // if (l<=1) return 1;
       /* int l_s = l/2;
        if   ((count(s1.substr(0,l_s),s2.substr(0,l_s)) && count(s1.substr(l_s,l-l_s),s2.substr(l_s,l-l_s))) ||
                (count(s1.substr(0,l-l_s),s2.substr(0,l-l_s)) && count(s2.substr(l-l_s,l_s),s1.substr(l-l_s,l_s))) ||
                (count(s1.substr(0,l_s),s2.substr(l-l_s,l_s)) && count(s1.substr(l_s,l-l_s),s2.substr(0,l-l_s))) ||
                (count(s2.substr(0,l_s),s1.substr(l-l_s,l_s)) && count(s2.substr(l_s,l-l_s),s1.substr(0,l-l_s))) ;*/
        int flag = 0;
        for (int i = 1; i<=l-1; i++)
            if ((count(s1.substr(0,i),s2.substr(0,i)) && count(s1.substr(i,l-i),s2.substr(i,l-i)) 
                && jud(s1.substr(0,i),s2.substr(0,i)) && jud(s1.substr(i,l-i),s2.substr(i,l-i)))   ||
                (count(s1.substr(0,i),s2.substr(l-i,i)) && count(s1.substr(i,l-i),s2.substr(0,l-i)) 
                && jud(s1.substr(0,i),s2.substr(l-i,i)) && jud(s1.substr(i,l-i),s2.substr(0,l-i)))
                )
    
                {flag = 1; break;}
        return flag;
    }
    
    
    bool isScramble(string s1, string s2) {
        return jud(s1,s2);
    }
};




//modified
class Solution {
public:
    bool count(string s1, string s2){
        vector<int> record1(26,0);
        vector<int>record2(26,0);
        for (int i = 0; i<s1.length(); i++)
            record1[s1[i]-'a']++;
        for (int i = 0; i<s2.length(); i++)
            record2[s2[i]-'a']++; 
        return record1 == record2;
    }
    
    bool jud(string s1, string s2){
        int l = s1.length();
        if (s1 == s2) return 1;
        if (!count(s1,s2)) return 0;
        int flag = 0;
        for (int i = 1; i<=l-1; i++)
            if ((jud(s1.substr(0,i),s2.substr(0,i)) && jud(s1.substr(i,l-i),s2.substr(i,l-i)))   ||
                (jud(s1.substr(0,i),s2.substr(l-i,i)) && jud(s1.substr(i,l-i),s2.substr(0,l-i))))
                {flag = 1; break;}
        return flag;
    }
    
    
    bool isScramble(string s1, string s2) {
        return jud(s1,s2);
    }
};