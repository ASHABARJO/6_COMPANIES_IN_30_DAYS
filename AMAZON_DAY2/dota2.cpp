/*Lets take some examples to understand this question
Input: senate = "RDRDD" and "DDRRR"
Here R takes rights of D and again joins back of the string.

We will take "RDRDD" example and see how to code for this problem.

First we will create 2 queues for radiant and dire, and next we push indices of R to R queue and indices of D to D queue.



Now we take 2 front elements from queues, pop both of them and add the min elem to the queue at the back (as it kills and gets ready for another round).
image

That's it!! 🥳 Atlast Radiant won against Dire!*/


//Code:-
class Solution {
public:
    string predictPartyVictory(string senate) {
     queue<int>rq,dq;
     for(int i=0;i<senate.size();i++)
     senate[i]=='R'?rq.push(i):dq.push(i);
     int a,b;
     while(!rq.empty() and !dq.empty()){
         a=rq.front(),b=dq.front();
         rq.pop(),dq.pop();
         if(a<b)//taking min and pushing it to queue again
         rq.push(a+senate.size());
         else
         dq.push(b+senate.size());
         }
         if(rq.size()>dq.size())
         return "Radiant";
         else
         return "Dire"; 
    }
};
