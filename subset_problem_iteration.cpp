#include<bits/stdc++.h>
using namespace std;
const int N =100;
const int M =100;
int numbers[N];
int dp[N][M];
int main()
{
    int n,target;
    cin>>n>>target;
    for(int i=1; i<=n; i++)cin>>numbers[i];
    for(int i=1; i<=n; i++)dp[0][i] = 0;
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=target; j++)
        {
            int ans1 = dp[i-1][j];
            if(j<numbers[i])
            {
                dp[i][j] = ans1;
            }
            else
            {
                int ans2 = dp[i-1][j-numbers[i]];
                dp[i][j] = ans1 || ans2;
            }

        }
    }
    cout<<dp[n][target];

    return 0;
}
