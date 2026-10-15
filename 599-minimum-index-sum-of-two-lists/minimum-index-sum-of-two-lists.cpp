class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> compare;
        unordered_map<string,pair<int,int>> mpp;
        for(int i=0;i<list1.size();i++){
            compare[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(compare.find(list2[i])!=compare.end())mpp[list2[i]]={compare[list2[i]],i};
        }
        int mini=INT_MAX;
        vector<string> ans;
        for(auto it:mpp){
            int sum=it.second.first+it.second.second;
            if(sum<mini){mini=sum;}
        }
        for(auto it:mpp){
            int sum=it.second.first+it.second.second;
            if(sum==mini)ans.push_back(it.first);
        }
        return ans;
    }
};