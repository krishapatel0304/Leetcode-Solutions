int maxSubArray(int* nums, int numsSize) {
    int maxSum=nums[0];
    int currSum=nums[0];
    for(int i=1;i<numsSize;i++){
        currSum=(currSum + nums[i] > nums[i]) ? currSum + nums[i] : nums[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
    }
    return maxSum;
}