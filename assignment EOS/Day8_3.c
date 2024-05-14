#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret,s,i;
	i=1;
	while(1)
	{
		ret=fork();
		if(ret==0)
		{
			printf("Hello Everybody\n");
			_exit(0);
		}
		else if(ret==-1)
		{
			break;
		}
		else
		{
			i++;
			printf("Child count: %d\n",i);
		}
	}
	for(int j=0;j<i;j++)
	{
		wait(&s);
	}
	return 0;
}
