class Solution { public:     
vector<int> largestDivisibleSubset(vector<int>& nums) {         
int ans=-1,lastind=-1;         
int n=nums.size();         
vector<int>dp(n,1);       
vector<int>trace(n,-1);         
sort(nums.begin(),nums.end());       
for(int i=0;i<n;i++){          
for(int j=0;j<i;j++){    
if((nums[i]%nums[j]==0) && dp[j]>=dp[i]) 
{ dp[i]=dp[j]+1;         
 trace[i]=j;          
 }          
 }
 if(dp[i]>ans){    
 ans=dp[i];         
 lastind=i; } }     
 vector<int>path;      
 while(lastind!=-1){          
 path.push_back(nums[lastind]);             
 lastind=trace[lastind]; }        
 reverse(path.begin(),path.end());     
 return path;     }          };
 
