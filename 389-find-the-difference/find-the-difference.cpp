class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mpp;
        int n=s.length()+1;
        for(int i=0;i<n;i++){
            mpp[t[i]]++;
        }
        n=n-1;
        char ans;
        for(int i=0;i<n;i++){
            mpp[s[i]]--;
        }
        for(auto it:mpp){
            if(it.second!=0)ans=it.first;
        }
        return ans;
    }
};