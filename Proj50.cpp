#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<bitset>
typedef long long ll;
ll _sieve_size;
using namespace std;
bitset<10000010>bs;
vector<int>primes;
void sieve(ll upperbound)
{
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=0;
	bs[1]=0;
	for(ll i=2;i<=_sieve_size;i++)
	{
		if(bs[i])
		{
			for(ll j=i*i;j<=_sieve_size;j=j+i)
			{
				bs[j]=0;
			}
			primes.push_back((int)i);
		}
	}
}
int main()
{
	
	sieve(1000000);
	ll larg=0;
	ll inc=0;
	cout<<"hello"<<" "<<primes.size()<<endl;
	vector<long long> sum(primes.size(),0);
	long long j1=0;
	sum[0]=primes[0];
	long long temp=0;
	for(j1=1;j1<primes.size();j1++)
	{
		if(j1>=3668&&j1<=3697)
		{
			temp=temp+primes[j1];
			cout<<primes[j1]<<endl;
		}
		
		sum[j1]=sum[j1-1]+primes[j1];
		if(j1==3697)
			cout<<"gde"<<sum[3697]-sum[3668]<<endl;
	}
	cout<<" "<<temp<<endl;
	larg=0;
	for(long long  i=1;i<primes.size();i++)
	{
		for(long long j=i-1;j>=0;j--)
		{
			if((sum[i]-sum[j])>1000000)
				break;
			long long diff=sum[i]-sum[j];
			if(bs[diff]==1&&(sum[i]-sum[j])>larg)
			{
				inc++;
			//	cout<<"i"<<i<<" "<<sum[i]<<"j"<<j<<" "<<sum[j]<<" "<<(sum[i]-sum[j])<<endl;
				larg=(sum[i]-sum[j]);
			}
		}
		
	}
	cout<<larg<<endl;	
	return 0;
}
