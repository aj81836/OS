#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int arr,arr1[1],arr2[2], ret, s1,s2,sum,s;
	char datawr[32], datard[32];
	ret = pipe(arr1);
	ret = pipe(arr2);
	ret = fork();
	if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- writer process
		close(arr1[0]); // close read fd
		printf("child: enter a number: ");
		scanf("%d%d", &s1,&s2);
		ret = write(arr1[1], &s1, sizeof(s1));
		ret = write(arr2[1], &s2, sizeof(s2));
		ret = read(arr2[0],&ret, sizeof(ret));
		printf("result: %d\n", ret);
		close(arr2[1]);
		close(arr1[1]);// close write fd
	}
	else {
		// parent -- reader process
		close(arr1[1]);
		close(arr2[0]);// close write fd
		printf("parent: waiting for data...\n");
		ret = read(arr1[0], &s1, sizeof(s1));
		ret = read(arr1[0], &s2, sizeof(s2));
		sum = s1 + s2;
		ret = write(arr2[1],&sum,sizeof(sum));
		printf("parent: %d bytes -- %d\n", ret, sum);
		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1, &s, 0);
	}

	return 0;
}

