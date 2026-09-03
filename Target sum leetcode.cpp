#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int count=0;
    freq(nums,0,target,0,n,count);
    return count;
}
void freq(vector<int> &nums,int idx,int &target,int cur,int &n,int &count){
    if(idx==n){
        if(cur==target)count++;
        return;
    }
    freq(nums,idx+1,target,cur+nums[idx],n,count);
    freq(nums,idx+1,target,cur-nums[idx],n,count);
}