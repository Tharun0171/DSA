class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<n;i++){
            string check=strs[i];
            sort(check.begin(),check.end());
            mpp[check].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};