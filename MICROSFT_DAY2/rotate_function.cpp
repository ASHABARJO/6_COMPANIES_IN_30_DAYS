class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int lastindx=nums.size()-1;
        int ans=INT_MIN;
        vector<int>f(nums.size(),0);
        int curr=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            curr+=i*nums[i];
        }
        f[0]=curr;
        ans=max(ans,f[0]);
        for(int i=1;i<nums.size();i++){
            f[i]=f[i-1]+sum-(nums.size()*nums[lastindx]);
            lastindx--;
            ans=max(ans,f[i]);
        }
    return ans;
    }
};