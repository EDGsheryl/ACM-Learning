#include <bits/stdc++.h>
using namespace std;

string d;
int num,p;
int k;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v;

int flag[3]; 

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>d)
	{
		if (d=="#") break;
		cin>>num>>p;
		v.push_back(make_pair(num,p));
	}
	cin>>k;
	for (auto pp:v)
	{
		for (int i=1;i<=k;i++) q.push(make_pair(pp.second*i,pp.first));
	}
	for (int i=1;i<=k;i++)
	{
		auto pp=q.top();q.pop();
		cout<<pp.second<<endl;
	}
}
