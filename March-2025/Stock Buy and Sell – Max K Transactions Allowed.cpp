class Solution {
    public:
      int solve(vector<int> &prices,int k,int i, vector<vector<vector<int>>> &dp,bool mark){
           //base case 
           if(k==0) return 0;
           
           if(i==prices.size()) return 0;
           
           // recursive case 
           if(dp[i][k][mark]!=-1) return dp[i][k][mark];
           int ans1=0,ans2=0;
           
           if(mark==false){
               ans1 = prices[i]+solve(prices,k-1,i+1,dp,true);
               ans2 = solve(prices,k,i+1,dp,mark);
           }
           else{
               ans1=-prices[i]+solve(prices,k,i+1,dp,false);
               ans2=solve(prices,k,i+1,dp,mark);
           }
           return dp[i][k][mark]=max(ans1,ans2);
      }
      int maxProfit(vector<int>& prices, int k) {
         int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>> (k+1,vector<int>(2,-1)));
         return solve(prices,k,0,dp,true);
          
      }
  };

//   Time Complexity:O(n*k)
//   Space Complexity:O(n*k)