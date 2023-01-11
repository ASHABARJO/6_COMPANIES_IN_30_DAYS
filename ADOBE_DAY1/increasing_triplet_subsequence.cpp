class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
  //size of vector nums
  int n=nums.size();
  //first store the first number of triplet & second store the 
  //second number of triplet
  int firstNum=INT_MAX,SecondNum=INT_MAX;
  for(int i=0;i<n;i++){
      if(nums[i]<=firstNum){
  //Current element less than or  equal to firstNum update first number.   
          firstNum=nums[i];
      }
      else if(nums[i]<=SecondNum){
          //Current element greater than firstNum but less than or equal to SecondNum
          //update second
          SecondNum=nums[i];
      }
      else return true;
  }
    return false;
    }
};
//T(n)=O(n)
//T(n)=O(1)
