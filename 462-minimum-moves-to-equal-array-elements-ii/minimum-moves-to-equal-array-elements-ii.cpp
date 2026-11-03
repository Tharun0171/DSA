class Solution {
public:
    int minMoves2(vector<int>& nums) {
        vector<int> nums2=nums;
        sort(nums2.begin(),nums2.end());
        int n=nums.size();
        int index=n/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums2[index]-nums2[i]);
        }
        return sum;
    }
};