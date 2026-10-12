class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.length();
        int cnta=0,cntb=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')cnta++;
            else cntb++;
        }
        //if(cnta==0 || cntb==0)return max(cnta,cntb);
        return n-2*min(cnta,cntb);
    }
};