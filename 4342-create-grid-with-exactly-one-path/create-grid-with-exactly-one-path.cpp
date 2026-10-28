class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> arr;
        for(int i=0;i<m;i++){
            string ans="";
            if(i==0){
                for(int j=0;j<n;j++){
                    ans+=".";
                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(j==n-1)ans+=".";
                    else ans+="#";
                }
            }
            arr.push_back(ans);
        }
        return arr;
    }
};