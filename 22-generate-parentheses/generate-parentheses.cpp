class Solution {
public:
    void getPar(vector<string>& ans,int n,int open,int close,string sent){
        //1st prg to ppush to github
        if(sent.length()==2*n){
            ans.push_back(sent);
            return;
        }
        if(open<n){getPar(ans,n,open+1,close,sent+"(");}
        if(close<open){getPar(ans,n,open,close+1,sent+")");}
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string sent="";
        getPar(ans,n,0,0,sent);
        return ans;
    }
};