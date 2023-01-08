class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>pos2;
        
        for(int i=0;i<n;i++){
        pos2[nums2[i]]=i;}
        
        set<int>left,right;
        
        left.insert(pos2[nums1[0]]);
        
        for(int i=2;i<n;i++)
        right.insert(pos2[nums1[i]]);

      long long ans=0;
      for(int i=1;i<n-1;i++){
          int k=pos2[nums1[i]];
          int a=distance(left.begin(),left.lower_bound(k));
          int b=right.size()-distance(right.begin(),right.lower_bound(k));
          ans=ans+a*b;
          left.insert(pos2[nums1[i]]);
          right.erase(pos2[nums1[i+1]]);
      }
return ans;        
    }
};