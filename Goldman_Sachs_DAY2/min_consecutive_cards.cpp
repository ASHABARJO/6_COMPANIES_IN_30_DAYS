class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
    unordered_map<int,int>hash;
    int res=INT_MAX, flag=0;
    for(int i=0;i<cards.size();i++){
        if(hash.count(cards[i])){
            res=min(res,i-hash[cards[i]]+1);
            flag=1;
        }
        hash[cards[i]]=i;
    }  
    return (flag==0)? -1 : res ;
    }
};
/*Intuition:-Keeping track oflast postion of particular card .And finding diiferece b/w its last occurred index and current index 
Approch:-1.If the current value is present in hash map then finding minimum of the diference b/w its last occurance index and the current index.(Min because to find minimum 
number of cards to be  picked)
2.Updating the index of the current value in map.
Complexity:-
T(n)=O(n)
S(n)=O(n) */
