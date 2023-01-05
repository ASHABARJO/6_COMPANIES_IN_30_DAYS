class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
int n=nums.size();
vector<int>nums1;
int start=-1,end=-1;
for(int x:nums){
    nums1.push_back(x);
}
sort(nums1.begin(),nums1.end());
for(int i=0;i<n;i++){
    if(nums[i]!=nums1[i]){
        start=i;
        break;
    }
}
    for(int j=n-1;j>=0;j--){
        if(nums1[j]!=nums[j]){
            end=j;
            break;
        }
    }
    if(start==-1 or end==-1)
    return 0;
    //condition if array is sorted 
    return end-start+1;
    //else returning length of window
    }
};