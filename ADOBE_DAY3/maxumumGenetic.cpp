class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
       int size=bank.size()//extract size
       unordered_set<int>dictionary
       for(int i=0;i<size;i++){
           dictionary.insert(bank[i]);//insert every word of bank intothe set
       } 
//if end word is not present into dictonary 
//will return false from here
if(dictoionart.find(endGene)==dictionary.end()){
return -1;   
    }
    //choice that are a valuable to us
    vector<char>available={'A','C','G','T'};
    //make vis set to find out whether for particular word
    //either we previously rncountered or not
    unordered_set<string>vis;
    int ans=0;//declare ans variable
    queue<string>q ;//define queu to start bfs
    q.push(startGene);
    //push starting word into the queue
    vis.insert(startGene);//insert into vis
    //starting bfs
    while(!q.empty()){
        int n=size()//extract size of queue
        while(n--){
            starting curr=q.front()//curr word
            q.pop()//popfrom queue
            if(curr==end)
            //if curr word ewuals to endGene,return ans
            {
                return ans;
            }
            //noe for every endex if curr word
            for(int i=0;i<8;i++){
                chsr orig=curr[i]
                //we will try to replace every available choice
                for(int j=0;j<4;j++){
                    curr[i];available[j]//replace character
                    //if it is present into the dictionary
                    if(dictionary.find(curr)!=dictionary.end())
                    {
                        //also we haven't seen it previously
                        if(vis.found(curr)==vis.end()){
                            q.push(curr);//the push into queue
                            vis.insert(curr);
                        }
                    }
                }

                            //and also put into vis
                            //also replace eith again original character
                            //future check
                            curr[i]=orig
                       }
                ans++;//increment answer
        }
  return -1
    }
    
};
