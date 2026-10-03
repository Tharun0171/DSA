class Solution {
public:
    void countSort(vector<int>& nums,int n,int pos){
        vector<int> b(n);
        vector<int> count(10,0);
        for(int i=0;i<n;i++){
            count[(nums[i]/pos)%10]+=1;
            //cout<<count[(nums[i]/pos)%10]<<endl;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--)b[--count[(nums[i]/pos)%10]]=nums[i];
        for(int i=0;i<n;i++)nums[i]=b[i];
    }
    void RadixSort(vector<int>& nums,int n){
        int maxele=*max_element(nums.begin(),nums.end());
        cout<<maxele<<endl;
        for(long long pos=1;maxele/pos>0;pos*=10){
            countSort(nums,n,pos);
        }
    }
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        int maxi=0;
        RadixSort(nums,n);
        //cout<<nums[0]<<endl;
        for(int i=1;i<n;i++){
            //cout<<nums[i]<<endl;
            maxi=max(maxi,(nums[i]-nums[i-1]));
        }
        return maxi;
    }
};