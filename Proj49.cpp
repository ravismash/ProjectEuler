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
bool  check_permut(int x,int y)
{
	int * num=new int[10];
	for(int i=0;i<=9;i++)
		num[i]=0;
	while(x!=0)
	{
		int temp=x%10;
		x=x/10;
		num[temp]++;
	}
	while(y!=0)
	{
		int temp=y%10;
		y=y/10;
		num[temp]--;
	}
	for(int i=0;i<=9;i++)
	{
		if(num[i]!=0)
			return false;
	}
	return true;
	
}
int main()
{
	sieve(1000000);
	for(int i=0;i<primes.size();i++)
	{
		if(primes[i]==9629)
		{
			cout<<i<<endl;
			break;
		}
	}
	for(int i=168;i<primes.size();i++)
	{
		int x=primes[i];	
		int num[10]={0};
		if(x>999&&x<10000&&x!=1487)
		{	
			for(int j=i+1;j<primes.size();j++)
			{
				int z=primes[j];
				bool flag=check_permut(x,z);
				if(flag==true)
				{
					int k=z+z-primes[i];
					flag=check_permut(z,k);
					if(flag==true&&bs[k]==1)
					{
						cout<<x<<" "<<z<<" "<<k<<endl;;	
					}
				}
			}
		}
	}

	return 0;
}
