class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sDs = 0 ;
        int dDs = 0 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i]<=9 ){
                sDs = sDs + nums[i];
            }
            else{
                dDs = dDs + nums[i];
            }

        }
        if(sDs > dDs){ 
            return true ;
        }
        else if(dDs > sDs){
             return true;
        }
        else {
            return false ;
        }
        
    }
};
