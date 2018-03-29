class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        for (int i = 0; i<nums.size(); i++){
            auto ite = hmap.find(target-nums[i]);
            if (ite != hmap.end())
                return vector<int> {ite->second, i};
            hmap[nums[i]] = i;
        }
                   
    }
};