#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n;
ll f[10001];

int main()
{
	ios::sync_with_stdio(false);
	n=10000;
	f[0]=1;
	for (int i=1;i*i*i<=n;i++)
		for (int o=i*i*i;o<=n;o++) 
			f[o]+=f[o-i*i*i];
	while (cin>>n) cout<<f[n]<<endl;
	
}
