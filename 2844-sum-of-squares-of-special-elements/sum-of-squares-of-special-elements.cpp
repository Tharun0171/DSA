class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            int rei=i+1;
            if(!(n%rei))sum+=nums[i]*nums[i];
        }
        return sum;
    }
};