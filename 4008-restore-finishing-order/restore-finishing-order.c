/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    int*res=(int*)malloc(friendsSize*sizeof(int));
    int a=0;
    for(int i=0;i<orderSize;i++){
        for(int j=0;j<friendsSize;j++){
            if(order[i]==friends[j]){
                res[a++]=order[i];
            }
        }
    }
    *returnSize=friendsSize;
    return res;
}