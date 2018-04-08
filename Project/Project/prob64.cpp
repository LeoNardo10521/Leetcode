class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for (int i = 0; i<=m; i++) dp[i][0] = INT_MAX;
        for (int j = 0; j<=n; j++) dp[0][j] = INT_MAX;
        dp[0][1] = 0;
        
        for (int i = 1; i<=m; i++)
            for (int j = 1; j<=n;j++)
                dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
        return dp[m][n];
    }
};

