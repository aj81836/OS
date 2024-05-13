#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int ret1,ret2,ret3,ret4,ret5,i,s;
ret1 = fork();
 if(ret1 == 0)
 {
  for (i=1;i<=5;i++){
   printf("child: %d\n",i);
   sleep(5);
   }
   _exit(0);
 }
 ret2 = fork();
 if(ret2 == 0)
 {
  for(i=1;i<=5;i++){
  printf("child: %d\n",i);
  sleep(5);
  }
  _exit(0);
  }
  ret3 = fork();
  if(ret3 == 0)
  {
  for(i=1;i<=5;i++){
  printf("child: %d\n",i);
  sleep(5);
  }
  _exit(0);
  }
  ret4 = fork();
  if(ret4 == 0)
  {
  for(i=1;i<=5;i++){
  printf("child:%d\n",i);
  sleep(5);
  }
  _exit(0);
  }
  ret5 = fork();
  if(ret5 == 0)
  {
  for(i=1;i<=5;i++){
  printf("child:%d\n",i);
  sleep(5);
  }
  _exit(0);
  }
else {
		// parent process
		for(i=1; i<=1;i++) {
			printf("parent: %d\n", i);
			sleep(1);
		}
		_exit(0);
	}


/*
else
  {
   for(i=1;i<=5;i++)
   {
    printf("parent: %d\n",i);
	sleep(5);
	 if(i==5){
	  wait(&s);
	   printf("chila exit:%d\n",WEXITSTATUS(s));
	   }
	   }
	   }
	   */
return 0;
}
