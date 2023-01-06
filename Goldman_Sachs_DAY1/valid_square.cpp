class Solution {
public:
int find_dis(vector<int>&p1,vector<int>&p2){
    return pow(p2[0]-p1[0],2)+pow(p2[1]-p1[1],2);
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12=find_dis(p1,p2);
        int d23=find_dis(p2,p3);
        int d34=find_dis(p3,p4);
        int d41=find_dis(p4,p1);
        int d31=find_dis(p3,p1);
        int d24=find_dis(p2,p4);
        
        unordered_set<int>s;
        s.insert({d12,d23,d34,d41,d31,d24});
        return !s.count(0) && s.size()==2;
    }
};
//T(n)=O(1);
