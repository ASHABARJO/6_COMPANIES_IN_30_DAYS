class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n>=k+maxPts || k==0)
        return 1;
        vector<double>dp(n+1);
        dp[0]=1.0;
        double ans=0,window_sum=1;
        for(int i=1;i<=n;i++){
            dp[i]=(window_sum/(double)maxPts);
            if(i<k)
            window_sum+=dp[i];
            else
            ans+=dp[i];
            if(i>=maxPts)
            window_sum-=dp[i-maxPts];
        }
        return ans;
    }
};
