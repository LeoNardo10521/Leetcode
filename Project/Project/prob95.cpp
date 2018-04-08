/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>(0);
        return gen(1,n);
    }
    
    vector<TreeNode*> gen(int start, int end){
        vector<TreeNode*> ans;
        
        if (start>end){
            ans.push_back(NULL);
            return ans;
            }
        
        for (int i = start; i<=end; i++){
            vector<TreeNode*>lefts = gen(start,i-1);
            vector<TreeNode*>rights = gen(i+1,end);
            for (int p = 0; p<lefts.size(); p++)
                for (int q =0; q<rights.size(); q++){
                    TreeNode*tmp = new TreeNode(i);
                    tmp->left = lefts[p];
                    tmp->right = rights[q];
                    ans.push_back(tmp);
                }
        }
        return ans;
    }
};