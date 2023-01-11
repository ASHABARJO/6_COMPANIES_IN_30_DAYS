class Solution {
public:
    int findKthNumber(int n, int k) {
        int result=1;
        for(--k;k>0;){
            int count=0;
            for(long long first=static_cast<long long>(result),last=first+2;first<=n;
            //interval is not empty)
            first*=20,last*=10)//increase a digit
            {
                //valid interval [first,last union,first,n]
                count+=static_cast<int>((min(n+1LL,last)-first));
            }
            if(k>=count)
            {
                //skip {result,result*,result**,result***,...}
                //increase the current prefix
                ++result;
                k-=count;
            }
            else{
                //not able to skip all{result,result*.result**.result***....}
                //search more detailedly
                result*=10;
                --k;
            }
        }
        return result;
    }
};
