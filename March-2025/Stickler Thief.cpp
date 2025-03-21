// Approach 1
class Solution {
    public:
      int solve(vector<int> &arr, int i,vector<int>& dp){
           //base case
            if(i>=arr.size()) return 0;
           //recursive case;
           int pick = 0 , nopick = 0;
           if(dp[i]!=-1) return dp[i];
           pick = arr[i]+solve(arr,i+2,dp);
           nopick = solve(arr,i+1,dp);
           return dp[i]=max(pick,nopick);
      }
      int findMaxSum(vector<int>& arr) {
          int n = arr.size();
          vector<int> dp(n,-1);
          return solve(arr,0,dp);
      }
  };
  //Time Complexity:O(n)
  //Space complexity;O(n)

//Approach 2
class Solution {
    public:
    int solve(vector<int> &arr, int n){
           if(n==1) return arr[0];
           if(n==2) return max(arr[0],arr[1]);
           int secprev = 0, prev = arr[0];
           int ans;
           for(int i=1;i<n;i++){
                ans = max(prev,secprev+arr[i]);
                secprev = prev;
                prev = ans;
           }
           return ans;
      }
      int findMaxSum(vector<int>& arr) {
          int n = arr.size();
          return solve(arr,n);
      }
  };
  
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  