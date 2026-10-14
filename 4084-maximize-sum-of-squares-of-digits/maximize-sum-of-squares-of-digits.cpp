class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans="";
        while(num>0){
            if(sum>=9){
                ans+='9';
                sum-=9;
            }else if(sum>0){
                ans+=char('0'+sum);
                sum=0;
            }else{
                ans+='0';
            }
            num--;
        }
        return ans;
            
        
        
    }
};