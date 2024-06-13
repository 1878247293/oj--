#includeiostream
#include vector
#include queue
#include map
#include algorithm
#include math.h

using namespace std;
priority_queueint small;                          大根堆
priority_queueint,vectorint,greaterint  big;   小根堆
mapint,int  mp;                     
int getMedian(int &k)
{
    if(k%2) return small.top();
    else return min(small.top(),big.top());   
}


int main() {
    int n, k;
    cin  n  k;  
    vectorint nums(n);
    
    for (int i = 0; i  n; ++i)
        cin  nums[i];
    
    for(int i=0;ik;i++)
    {
        small.push(nums[i]);
    }
    for(int i=0;ik2;i++)
    {
        big.push(small.top());
        small.pop();
    }
    vectorint ans;
    ans.push_back(getMedian(k));
    for(int i=k;in;i++)
    {
        int balance = 0;
        int l = nums[i-k];
        mp[l]++;
        if(!small.empty() && l=small.top())
            balance--;
        else balance++;
        if(!small.empty()&&nums[i]=small.top())
        {
            small.push(nums[i]);
            balance++;
        }
        else
        {
            big.push(nums[i]);
            balance--;
        }
        if(balance0)
        {
            big.push(small.top());
            small.pop();
        }
        if(balance0)
        {
            small.push(big.top());
            big.pop();
        }
        while(!small.empty() && mp[small.top()]0)
        {
            mp[small.top()]--;
            small.pop();
        }
        while(!big.empty() && mp[big.top()]0)
        {
            mp[big.top()]--;
            big.pop();
        }
        ans.push_back(getMedian(k));
    }
    for(int i=0;ians.size();i++)
        coutans[i] ;
    return 0;
}