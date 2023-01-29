/*Intuition: For a given number A[i], we only care about the subarray [p + 1, q - 1] where p and q are the index to the previous and next smaller element.

Why do we use the next/previous smaller element as the boundary?:
For example:

 0 1 2 3 4 5 // index
[3,1,5,6,4,2] // value
For A[1] = 1, it's the smallest value of the entire array. So we should use the sum of the entire array.

For A[5] = 2, it's the second smallest value. We won't want to extend the subarray to index 1 because then the minimum value will become 1 and fall back to the previous case. So we only use subarray [5,6,4,2].

Similarly, for other numbers. In essense, we don't want to go over the previous/next smaller element.

Algorithm:

Store prefix sum in sum array.
Store the indexes to the previous/next smaller element into prev/next array.
For A[i], the max product including it is A[i] * SUM(prev[i] + 1, next[i] - 1) where SUM(i, j) is the sum of subarray A[i..j].
*/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long mod=1e9+7,n=nums.size(),ans=0;
        vector<long long>sum(n+1);
        //prefix sum
        for(int i=0;i<n;++i)
        sum[i+1]=sum[i]+nums[i];
  vector<int>prev(n,-1),next(n,-1);
        vector<int>s;
        //stack
        for(int i=0;i<n;i++){
        //compute the index to the previous smaaler element
        while(s.size() && nums[s.back()]>=nums[i])
        s.pop_back();
        if(s.size())
        prev[i]=s.back();
        s.push_back(i);
    }

s.clear();
  for(int i=n-1;i>=0;--i){
      //compute the index to the next smaller element
      while(s.size() && nums[s.back()]>=nums[i])
      s.pop_back();
      if(s.size())
      next[i]=s.back();
      s.push_back(i);
  }
  for(int i=0;i<n;++i){
      long long s=next[i]==-1?sum.back():sum[next[i]];
      if(prev[i]!=-1){
          s-=sum[prev[i]+1];
      }
      ans=max(ans,(long long)nums[i]*s);
  }
    return ans%mod;
    }
};
