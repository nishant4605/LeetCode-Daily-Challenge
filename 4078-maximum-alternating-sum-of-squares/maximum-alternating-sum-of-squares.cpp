class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];

        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<=j){
            if(i==j){
                ans+=nums[i];
            }else{
                // ans+=nums[j];
                // ans-=nums[i];
                ans+=(nums[j]-nums[i]);
            }
            i++;
            j--;
        }
        return ans;
        
    }
};