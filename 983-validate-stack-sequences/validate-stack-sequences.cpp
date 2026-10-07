class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        st.push(pushed[0]);
        for(int i=1;i<pushed.size();i++){
            while(!st.empty() && st.top()==popped[j]){st.pop();j++;}
            st.push(pushed[i]);
        }
        while(j<pushed.size() && st.top()==popped[j]){
            st.pop();j++;
        }
        if(st.empty())return true;
        return false;
    }
};