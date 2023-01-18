/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      auto peak=0,r=mountainArr.length()-1;
      while(peak<r){
          int m=(peak+r)/2;
          if(mountainArr.get(m)>mountainArr.get(m+1))
          r=m;
          else
          peak=m+1;
      }  
      auto i=bSearch(mountainArr,target,0,peak);
      return i!=-1?i:bSearch(mountainArr,target,peak+1,mountainArr.length()-1,false) ;
    }
    int bSearch(MountainArray& arr, int target, int l, int r, bool asc = true){
        while(l<r){
            int m=(l+r)/2;
            auto val=arr.get(m);
            if(val==target)
            return m;
            if(asc==val<target)
            target=m+1;
            else
            r=m-1;
        }
        return -1;
    }
};