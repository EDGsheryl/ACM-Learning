#include <bits/stdc++.h>
using namespace std;

int x,y;
int fa[20010];
int d[20010]; 
int ans;
int T;
int n;
char ch;

int find(int k)
{
	if (fa[k]!=k)
	{
		int f=find(fa[k]);
		d[k]+=d[fa[k]];
		return fa[k]=f;
	}
	else return k;
 } 

void unionit(int q,int w)
{
	fa[q]=w;
	d[q]=abs(q-w)%1000;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) d[i]=0,fa[i]=i;
		while (1)
		{
			cin>>ch;
			if (ch=='O') 
			{
				break;
			}
			else if (ch=='E') 
			{
				cin>>x;
				find(x);
				cout<<d[x]<<endl;
			}
			else if (ch=='I')
			{
				cin>>x>>y;
				unionit(x,y);
			}
		}
		
	}
}
