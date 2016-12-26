#include<iostream>
using namespace std;
#define Digit 256
void multiple(int * digits,int factor)
{
	int carry=0;
	for(int i=0;i<Digit;i++)
	{	
		int digit=digits[i];
		digit=digit*factor;
		digit=digit+carry;
		carry=digit/10;
		digit=digit%10;
		digits[i]=digit;
	}
}
int main()
{
	int digit[Digit];
	
	for(int i=0;i<Digit;i++)
		digit[i]=0;
	digit[0]=1;
	for(int i=2;i<=100;i++)
		multiple(digit,i);
	int sum=0;
	for(int i=0;i<Digit;i++)
		sum=sum+digit[i];
	cout<<sum<<endl;
	return 0;
}
