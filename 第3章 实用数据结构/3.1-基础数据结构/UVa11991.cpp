#include <bits/stdc++.h>
using namespace std;

int n,m;
int x;
map<int,vector<int> > mmp;
int k,v;

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		mmp.clear();
		for (int i=1;i<=n;i++) 
		{
			cin>>x;
			mmp[x].push_back(i);
		} 
		for (int i=1;i<=m;i++) 
		{
			cin>>k>>v;
			if (k-1<mmp[v].size()) cout<<mmp[v][k-1]<<endl;
			else cout<<0<<endl;
		}
	}
	
}
