#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
int x,y;

int flag[3]; 

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n)
	{
		while (!q.empty()) q.pop();
		while (!s.empty()) s.pop();
		while (!pq.empty()) pq.pop();
		
		memset(flag,0,sizeof flag);
		for (int i=1;i<=n;i++)
		{
			cin>>x>>y;
			if (x==1)
			{
				s.push(y);
				q.push(y);
				pq.push(y);
			}
			else 
			{
				if (!s.empty()) 
				{
					int top=s.top();s.pop();
					if (top!=y) flag[0]=1;
				}
				if (!q.empty()) 
				{
					int top=q.front();q.pop();
					if (top!=y) flag[1]=1;
				}
				if (!pq.empty()) 
				{
					int top=pq.top();pq.pop();
					if (top!=y) flag[2]=1;
				}
				else flag[0]=flag[1]=flag[2]=1;
			}
		}
		int cnt=0;
		for (int i=0;i<3;i++) if (!flag[i]) cnt++;
		if (cnt>1) 
			cout<<"not sure"<<endl;
		else if (cnt==0) 
			cout<<"impossible"<<endl;
		else if (cnt==1)
		{
			if (!flag[0]) cout<<"stack"<<endl;
			else if (!flag[1]) cout<<"queue"<<endl;
			else if (!flag[2]) cout<<"priority queue"<<endl;
		}
	}
	
}
