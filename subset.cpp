#include<bits/stdc++.h>
using namespace std;
int numbers[101];
int  dp[101][101];
int  solv(int n,int t);
int main()
{
    int n,target;
    cin>>n>>target;
    for(int i=1; i<=n; i++)cin>>numbers[i];
    for(int i =0; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            dp[i][j] =-1;
        }
    }
    int  ans =  solv(n,target);
    cout<<ans;
    return 0;
}
int solv(int n,int t)
{
// base case
    if(n == 0 && t == 0)return 1;
    if(n == 0 && t != 0) return 0;
// if the current state is already solved then return it
    if(dp[n][t]!=-1)return dp[n][t];
// solve the current state
    int ans1 = solv(n-1,t );
    if(t<numbers[n])
    {
        dp[n][t]=ans1;
        return ans1;
    }
    int ans2 = solv(n-1,t - numbers[n]);
    if(ans1==1 || ans2==1)
    {
        dp[n][t] =1;
        return 1;
    }
    else
    {
        dp[n][t]=0;
        return 0;
    }

}
