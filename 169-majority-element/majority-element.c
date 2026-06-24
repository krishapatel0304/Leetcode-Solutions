int majorityElement(int* nums, int numsSize) {
    int count=0;
    int m=0;
    for(int i=0;i<numsSize;i++)
    {
        if(count==0){
            m=nums[i];
        }
        if(nums[i]==m){
            count++;
        } else{
            count--;
        }
    }
    return m;
}