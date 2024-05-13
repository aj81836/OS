#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num_children = 5;

   
    for (int i = 0; i < 5; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("fork failed");
			sleep(5);
            exit(0);
        } 
		else if (child_pid == 0) { 
            printf("Child:  %d (PID: %d\n)", i + 1, getpid());
            sleep(5);  
           
            exit(0);  
        } else {  
           
            //continue;
        }
    }

    
    for (int i = 0; i < 5; i++) {
        wait(0); 
    }

    printf("Parent PID: %d\n", getpid());
    return 0;
}

