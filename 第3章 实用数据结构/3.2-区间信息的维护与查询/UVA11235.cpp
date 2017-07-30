#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100010]; 
map<int,int> lft;
map<int,int> rgt;
map<int,int> num;

int d[100010][18];

int x,y;

void build_RMQ()
{
	memset(d,0,sizeof d);
	for (int i=1;i<=n;i++) d[i][0]=num[a[i]];
	for (int j=1;(1<<j)<=n;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
		d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
	return;
}

int RMQ(int l,int r)
{
	int k=0;
	while ((1<<(k+1))<=r-l+1) k++;
	return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	while (cin>>n)
	{
		if (n==0) return 0;
		cin>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		lft.clear();rgt.clear();num.clear();
		for (int i=1;i<=n;i++) rgt[a[i]]=i;
		for (int i=n;i;i--) lft[a[i]]=i;
		for (int i=1;i<=n;i++) num[a[i]]++;
		build_RMQ();
		for (int i=1;i<=m;i++)
		{
			cin>>x>>y;
			int ans=min(rgt[a[x]],y)-x+1;
			x=rgt[a[x]]+1;
			ans=max(ans,y-max(lft[a[y]],x)+1);
			y=lft[a[y]]-1;
			if (x<=y) ans=max(ans,RMQ(x,y));
			cout<<ans<<endl;
		}
	}
} 
