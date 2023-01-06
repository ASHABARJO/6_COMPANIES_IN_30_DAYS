class Solution {
public:
    int trailingZeroes(int n) {
int cnt=0;
while(n){
n/=5;
cnt+=n;
}
return cnt;
    }
};
//T(n)=Depend on the number of factor of 5 in n;
//S(n)=O(1)
