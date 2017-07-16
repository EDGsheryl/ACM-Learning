#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n;
ll ans;
ll a[1000010];
ll x[2];

int main()
{
	ios::sync_with_stdio(false);
	for (int i=2;i<=1000000;i++) 
	{
		ans+=x[0]*x[1];
		a[i]=ans;
		x[i&1]++;
	}
	while (cin>>n)
	{
		if (n<3) return 0;
		cout<<a[n]<<endl;
	}
	
}
