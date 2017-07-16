#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll n,m,k;
ll ans;
int cnt;

ll c[510][510];
const ll MOD=1000007;

int main()
{
	ios::sync_with_stdio(false);
	
	c[0][0]=1;
	for (int i=0;i<=500;i++)
	{
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	cin>>n;
	while (cin>>n>>m>>k)
	{
		ans=0;
		ans+=c[(n-1)*m][k]*2+c[n*(m-1)][k]*2;
		ans%=MOD;
		ans-=c[(n-2)*m][k]+c[(n-1)*(m-1)][k]*4+c[(m-2)*n][k];
		ans%=MOD;
		ans+=c[(n-2)*(m-1)][k]*2+c[(m-2)*(n-1)][k]*2;
		ans%=MOD;
		ans-=c[(m-2)*(n-2)][k];
		ans%=MOD;
		ans=(c[m*n][k]-ans+MOD)%MOD;
		cout<<"Case "<<++cnt<<": "<<ans<<endl;
	}
	
}
