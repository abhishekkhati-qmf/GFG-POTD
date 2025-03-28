class Solution {
    public:
      int activitySelection(vector<int> &start, vector<int> &finish) {
          int n = start.size();
          vector<pair<int,int>> v;
          for(int i=0;i<n;i++){
              v.push_back({finish[i],start[i]});
          }
          sort(v.begin(),v.end());
          int prev=-1,ans=0;
          for(int i=0;i<n;i++){
               if(v[i].second>prev){
                   ans++;
                   prev=v[i].first;
               }
          }
          return ans;
      }
  };
  
  // Time Complexity : O(nlogn)
  // Space Complexiy : O(n)