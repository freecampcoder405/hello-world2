int maxi(int a,int b){
    return a>b?a:b;
}
int maxdiff(int* arr,int s,int e){
    if(s>=e){
        return -1;
    }
    int max=-1;
    for(int i=s+1;i<=e;i++){
        if(arr[i]>arr[s] && arr[i]-arr[s]>max){
            max=arr[i]-arr[s];
        }
    }
    return maxi(max,maxdiff(arr,s+1,e));
}
int maximumDifference(int* nums, int numsSize){
    return maxdiff(nums,0,numsSize-1);
}
