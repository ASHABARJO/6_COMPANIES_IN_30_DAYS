class Solution {
public:
int maxscore;
vector<int>ans;
void helper(vector<int>&bob,int i,vector<int>&alice,int remarrow,int score)
{
    if(i==-1 or remarrow<=0){
        if(score>=maxscore){
            maxscore=score;
            ans=bob;
        }
        return;
    }
helper(bob,i-1,alice,remarrow,score);
if(remarrow>alice[i])
{bob[i]=alice[i]+1;
remarrow-=(alice[i]+1);
score+=i;
helper(bob,i-1,alice,remarrow,score);
bob[i]=0;
} 
 }
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>bob(12,0);
        maxscore=INT_MIN;
        helper(bob,11,aliceArrows,numArrows,0);
        int arrow_used=0;
        for(int a:ans)
        arrow_used+=a;
        if(arrow_used<numArrows)
        ans[0]+=(numArrows-arrow_used);
        return ans;
    }
};
/*Intuition:-
I observed that since there are 12 round there can br at max 2^12 permutation on either bob wins ith rounds not since 2^12 isn't that big of a number that could gi
-ve TLE we can generate all possible sequence.Also we can optimally win a round from Alice by just having 1 extra as compared to Alice
For each possible sequence, we see if this sequence has a greater score, if yes then we update the answer.*/
