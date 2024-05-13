#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int retA,retB,retC,retD,i,s4,s3,s2,s1;
retA = fork();
 if(retA == 0){
  retB = fork();
  if(retB == 0){
   retC = fork();
   if(retC == 0){
    retD =fork();
	if(retD == 0)
	//cD
     for(i=1;i<=5;i++)
	{
	 waitpid(retD,&s4,0);
	 _exit(0);
    }
	 waitpid(retC,&s3,0);
	 _exit(0);
	 }
	  waitpid(retB,&s2,0);
	  _exit(0);
	 }
	 else
	 {
	  for(i=1;i<=5;i++){
	  printf("parent:%d\n",i);
	  waitpid(retA,&s1,0);
	  }
	  }
	  }
return 0;
}

