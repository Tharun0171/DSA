class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            string check=strs[i];
            sort(check.begin(),check.end());
            mpp[check]++;
        }
        unordered_map<string,int> ind;
        int cnt=0;
        for(int i=0;i<n;i++){
            string check=strs[i];
            sort(check.begin(),check.end());
            if(mpp.find(check)!=mpp.end()){
                if(ind.find(check)!=ind.end())ans[ind[check]].push_back(strs[i]);
                else{
                    ind[check]=cnt;
                    cnt+=1;
                    vector<string> ref={strs[i]};
                    ans.push_back(ref);
                }
            }
            else{
                cnt++;
                vector<string> ref={strs[i]};
                ans.push_back(ref);
            }
        }
        return ans;
    }
};