#include <bits/stdc++.h>
using namespace std;

int x,y;
int fa[100010];
int ans;

int find(int k)
{
	return fa[k]==k?k:fa[k]=find(fa[k]);
 } 

void unionit(int q,int w)
{
	int f=find(q);
	int fv=find(w);
	fa[f]=fv;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i=1;i<=100000;i++) fa[i]=i;
	while (cin>>x)
	{
		if (x==-1)
		{
			cout<<ans<<endl;
			ans=0;
			for (int i=1;i<=100000;i++) fa[i]=i;
			continue;
		}
		cin>>y;
		if (find(x)!=find(y)) unionit(x,y);
		else ans++;
		
	}
}
