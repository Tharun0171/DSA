class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long> st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            if(st.top()==nums[i]){
                long long n=st.top()+nums[i];
                st.pop();
                while(!st.empty() && n==st.top()){
                    n=n+st.top();
                    st.pop();
                }
                st.push(n);
            } 
            else st.push(nums[i]);
        }
        vector<long long> ans(st.size());
        int cnt=st.size();cnt-=1;
        while(!st.empty()){
            ans[cnt--]=st.top();
            st.pop();
        }
        return ans;
    }
};