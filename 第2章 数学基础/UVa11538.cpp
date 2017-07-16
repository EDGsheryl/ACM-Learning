#include <bits/stdc++.h>
using namespace std;

using ll=long long ;
ll n,m;
ll ans;

int main()
{
	ios::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		if (n==m && m==0) return 0;
		if (n>m) swap(n,m);
		ans+=(n*m)*(m-1);
		ans+=(n*m)*(n-1);
		ans+=2*n*(n-1)*(3*m-n-1)/3;
		cout<<ans<<endl;
		ans=0;
	}
	
}
