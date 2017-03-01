#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

char number1[15];

int ctoi(char ch)
{
	if(ch>='0'&&ch<='9')
		return ch-'0';
	else
		return ch-'A'+10;
}

char itoc(int v)
{
	if(v<10) 
		return v+'0';
	else
		return v+'A'-10;
}

void dtob2(long long v,int b2)
{
	if (v)
	{
		dtob2(v/b2,b2);
		printf("%c",itoc(v%b2));
	}
}

main()
{
	int base1,base2;
	while (scanf("%d%d%s",&base1,&base2,number1))
	{
		//非法判断
		int flag=0;
		for(int i=0;number1[i];++i)
			if(ctoi(number1[i])>=base1)
				flag=1;
		if (flag)
		{
			printf("%s is an illegal base %d number\n",number1,base1);
			continue;
		}
		//转化成10进制的值 
		long long value=0LL;
		for(int i=0;number1[i];++i)
		{
			value*=base1;
			value+=ctoi(number1[i]);
		}
		//转化成base2进制数 
		printf("%s base %d = ",number1,base1);
		if(value==0LL)
			printf("0");
		else
			dtob2(value,base2);
		printf(" base %d\n",base2);
	}
}
