//无法解决（）（（）的问题

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> mystack;
        int res = 0, cur = 0;
        for(int i = 0; i<s.length(); i++){
            char c = s[i];
            if (c == '(') mystack.push(c);
            else {
                if (mystack.empty()) {res = (res>cur)?res:cur; cur = 0;continue;}
                mystack.pop();
                cur+=2;
            }
        }
        if (mystack.empty()) res = (res>cur)?res:cur;
        return res;
    }
};

//ac
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mystack;
        int res = 0, cur = 0;
        mystack.push(-1);
        for(int i = 0; i<s.length(); i++){
            char c = s[i];
            if (c == '(') mystack.push(i);
            else {  
                //if (mystack.empty()) {mystack.push(i);continue;}
                mystack.pop();
                if (mystack.empty()) mystack.push(i);
                else{
                    int ind = mystack.top();
                    //if( ind<0 ) continue;
                    cur = i-ind; 
                 res = (res>cur)?res:cur;
             }
            }
        }
        return res;
    }
};