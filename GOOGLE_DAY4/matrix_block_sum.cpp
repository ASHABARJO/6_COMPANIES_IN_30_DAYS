class Solution {
public:
int sizeX,sizeY;
int extractSum(int i,int j,const vector<vector<int>>&sum){
    if(i<0 || j<0)
    return 0;

    if(i>=sizeX)
    i=sizeX-1;
    
    if(j>=sizeX)
    j=sizeY-1;
    
    return sum[i][j];
}

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
  sizeX=mat.size();
  sizeY=mat[0].size();
  vector<vector<int>>sum(sizeX,vector<int>(sizeY,0));
  //Calculate prefix matrix
  for(int i=0;i<sizeX;i++){
  for(int j=0;j<sizeY;i++){
      sum[i][j]=mat[i][j]+extractSum(i-1,j,sum)+extractSum(i,j-1,sum)-extractSum(i-1,j-1,sum);
  }       
    }
 //Usr prefix matrix to calculate our sum
 vector<vector<int>>ans(sizeX,vector<int>(sizeY,0));
 for(int i=0;i<sizeX;i++){
 for(int j=0;j<sizeY;j++){
     ans[i][j]=extractSum(i+k,j+k,sum)-extractSum(i+k,j-k,sum)-extractSum(i-k-1,j+k,sum)+extractSum(i-k-1,j-k-1,sum);
 }
 }   
 return ans;
    }  
};
