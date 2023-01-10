class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size(),all=(1<<n)-1,res=0;
        auto check=[&](int good){
            for(int i=0;i<n;++i)
                if(good &(1<<i))
            for(int j=0;i<n;++j)
            if(statements[i][j]!=2 && statements[i][j]!=(good & (1<<j)?1:0))
            return false;
    return true;
            };
            for(int good=1;good<=all;++good){
                int cnt=bitset<16>(good).count();
                if(cnt>res && check(good))
                res=cnt;
            }
        return res;
        }
