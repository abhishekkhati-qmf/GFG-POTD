class Solution {
    public:
      bool solve(vector<int>& arr, int sum ,int i,vector<vector<int>> &dp)
      {
          //base case 
          if(sum==0) return true;
          if(i==arr.size()) return false;
          
          //recursive case
          bool pick=false,nopick=false;
          if(dp[i][sum]!=-1) return dp[i][sum];
          if(arr[i]<=sum) pick = solve(arr,sum-arr[i],i+1,dp);
          nopick = solve(arr,sum,i+1,dp);
          return dp[i][sum]=(pick||nopick);
      }
      bool isSubsetSum(vector<int>& arr, int sum)
      {
         int n = arr.size();
         vector<vector<int>> dp(n,vector<int> (sum+1,-1));
         return solve(arr,sum,0,dp);
      }
  };

//   Time Complexity : O(n*sum)
//   Space Complexity : O(n*sum)