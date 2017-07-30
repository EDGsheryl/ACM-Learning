#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int x[100010];
int a[20010];
int c[100010];
int d[100010];
long long ans;//爆int 

inline int lowbit(int k)
{
	return (-k)&k;
}

int sum(int k)
{
	int ret=0;
	while (k>0)
	{
		ret+=x[k];
		k-=lowbit(k);
	}
	return ret;
}

void update(int k,int dlt)
{
	while (k<=100000) //这里不能是n 
	{
		x[k]+=dlt;
		k+=lowbit(k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		memset(x,0,sizeof x);
		for (int i=1;i<=n;i++) 
		{
			c[i]=sum(a[i]);
			update(a[i],1);
		}
		memset(x,0,sizeof x);
		for (int i=n;i;i--) 
		{
			d[i]=sum(a[i]);
			update(a[i],1);
		}
		
		ans=0; 
		for (int i=2;i<n;i++) ans+=(long long)(c[i]*((n-i-d[i])))+(long long)(d[i]*(i-1ll-c[i]));
		cout<<ans<<endl;
	 } 
} 
