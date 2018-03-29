class Solution {
public:
    bool isPalindrome(int x) {
        if (x <0 || ( x!= 0 && x % 10 == 0)) return false;
        int tmp = 0;
        while (x>tmp){
            tmp = tmp * 10 + x % 10;
            x /= 10;
            
        }
        
        return (x == tmp) || (x == tmp /10);
    }
};