class Solution {
public:    
    void recursive(int pos, vector<int> &cur, vector<vector<int> >&res){
        if(pos>= cur.size()) {res.push_back(cur); return;}
        for (int i = pos; i<cur.size(); i++){
            swap(cur[pos],cur[i]);
            recursive(pos+1, cur, res);
            swap(cur[i],cur[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int >> res;
        recursive(0, nums, res);
        return res;
    }
    

};