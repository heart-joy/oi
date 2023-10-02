#include <bits/stdc++.h>
#define maxn 20010
using namespace std;
int n,m,x;
vector <int> c,ans;
struct node{
	int l,r;
};
node a[maxn];
bool cmp(node x,node y)
{
	return x.l < y.l;
}
void dfs(int s)
{
	for(int i = s;i < m;i ++)
	{
		if(a[i].r >= a[i + 1].l && a[i + 1].r != x)
		{
			ans.push_back(a[i + 1].r);
		}
	}
	for(int i = s;i > 0;i --)
	{
		if(a[i].l <= a[i - 1].r && a[i - 1].l != x)
		{
			ans.push_back(a[i - 1].l);
		}
	}
}
int main()
{
//	freopen("station2.in","r",stdin);
//	freopen("2.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&x);
	for(int i = 1;i <= m;i ++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a + 1,a + m + 1,cmp);
	for(int i = 1;i <= m;i ++)
	{
		if(x <= a[i].r && x >= a[i].l)
		{
			c.push_back(i);
			if (x != a[i].l) ans.push_back(a[i].l);
			if (x != a[i].r) ans.push_back(a[i].r);
		}
	}
	for(int i = 0;i < c.size();i ++)
	{
		dfs(i); 
	}
	sort(ans.begin(),ans.end());
	cout << ans[0] << " ";
	for(int i = 1;i < ans.size();i ++)
	{
		if(ans[i] != ans[i - 1]) printf("%d ",ans[i]);
	}
	return 0;
}
