#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int A,B,C,D,s1,s2,s3,s4;
	A=fork();
	if(A==0)
	{
		B=fork();
		if(B==0)
		{
			C=fork();
			if(C==0)
			{
				D=fork();
				if(D==0)
				{
					for(int i=0;i<5;i++)
					{
						printf("Child D: %d\n",i);
						sleep(1);
					}
					_exit(0);	
				}
				for(int i=0;i<5;i++)
				{
					printf("Child C: %d\n",i);
					sleep(1);
				}
				waitpid(D,&s4,0);
				_exit(0);
			}
			for(int i=0;i<5;i++)
			{
				printf("Child B: %d\n",i);
				sleep(1);
			}
			waitpid(C,&s3,0);
			_exit(0);
		}
		waitpid(B,&s2,0);
		for(int i=0;i<5;i++)
		{
			printf("Parent A: %d\n",i);
			sleep(1);
		}
		_exit(0);
	}
	waitpid(A,&s1,0);
	_exit(0);
	return 0;
}
