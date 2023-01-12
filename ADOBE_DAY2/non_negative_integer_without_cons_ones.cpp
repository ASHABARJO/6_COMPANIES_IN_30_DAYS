class Solution {
public:
    int findIntegers(int n) {
       n++;
       int num=n;
       int odd[34]={};
       for(int i=0;i<34;i++){
           odd[i]=num%2;
           num/=2;
       }
       int ans=0;
       int dp[34]={};
       dp[0]=1;
       dp[1]=2;
       for(int i=2;i<32;i++){
           dp[i]=dp[i-1]+dp[i-2];
       }
    for(int i=31;i>=0;i--){
        if(odd[i])
        {ans+=dp[i];
        }
        if(odd[i] && odd[i+1]){
            break;
        }
    }
    return ans;
    }
};
//T(n)=O(n)
//S(n)=O(n)
