#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
int a[760];

queue<vector<int> > qq;
vector<int> v;

int main()
{
	while (scanf("%d",&n)==1)
	{
		v.clear();
		for (int i=1;i<=n;i++) v.push_back(0);
		for (int i=1;i<=n;i++)
		{
			for (int o=0;o<n;o++) scanf("%d",&v[o]);
			sort(v.begin(),v.end());
			qq.push(v);
		}
		auto v1=qq.front();qq.pop();
		while (!qq.empty())
		{
			auto v2=qq.front();qq.pop();
			for (auto i:v1)
				q.push(make_pair(i+v2[0],0));
			for (int i=0;i<n;i++) //维护n个最小值 O(NlogN) 
			{
				v1[i]=q.top().first;
				if (q.top().second+1<n) q.push(make_pair(q.top().first-v2[q.top().second]+v2[q.top().second+1],q.top().second+1));
				q.pop();
			}
			while (!q.empty()) q.pop();
		}
		v=v1;
		for (int i=0;i<n-1;i++) cout<<v[i]<<" ";
		cout<<v[n-1]<<endl;
	}
}
