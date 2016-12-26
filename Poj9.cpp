#include<iostream>
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
	sieve(2000000);
	unsigned long long y=0;
	for(ll i=0;i<_sieve_size;i++)
	{
		if(bs[i])
		{	
			y=y+i;
		}
	}
	cout<<y<<endl;
	return 0;
}
