#include <bits/stdc++.h>
#define maxn 60
using namespace std;
int n,avga[maxn],avgb[maxn],avgc[maxn];
int len,ans;
struct node{
	int a,b,c;
};
node good[maxn];
int dp[maxn][maxn];
int main()
{
	freopen("sell.in","r",stdin);
	freopen("sell.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d%d%d",&good[i].a,&good[i].b,&good[i].c);
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			int avgaa = (avga[len] * len + good[j].a) / (len + 1),avgbb = (avgb[len] * len + good[j].b) / (len + 1),avgcc = (avgc[len] * len + good[j].c) / (len + 1);
			if(avgaa <= avgcc && avgaa <= avgcc)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if(len + 1 <= i)
				{
					avga[++len] = avgaa;
					avgc[len] = avgcc;
					avgb[len] = avgbb;
				}

			}
			ans = max(ans,dp[i][j]);
		}
	}
	printf("%d",ans); 
}
