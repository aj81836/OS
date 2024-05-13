#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_A, pid_B, pid_C, pid_D;

    // Create child process B from parent A
    pid_B = fork();
    if (pid_B < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid_B == 0) {  // Child process B
        printf("Child process B (PID: %d) created\n", getpid());

        // Create child process C from child B
        pid_C = fork();
        if (pid_C < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid_C == 0) {  // Grandchild process C
            printf("Grandchild process C (PID: %d) created\n", getpid());

            // Create child process D from grandchild C
            pid_D = fork();
            if (pid_D < 0) {
                perror("fork failed");
                exit(1);
            } else if (pid_D == 0) {  // Great-grandchild process D
                printf("Great-grandchild process D (PID: %d) created\n", getpid());
                sleep(5);  // Process D sleeps for 5 seconds
                printf("Great-grandchild process D (PID: %d) exiting\n", getpid());
                exit(0);
            } else {  // Back in grandchild process C (after creating D)
                wait(NULL);  // Wait for child D to finish before exiting
                printf("Grandchild process C (PID: %d) exiting\n", getpid());
                exit(0);
            }
        } else {  // Back in child process B (after creating C)
            wait(NULL);  // Wait for child C to finish before exiting
            printf("Child process B (PID: %d) exiting\n", getpid());
            exit(0);
        }
    } else {  // Parent process A
        wait(NULL);  // Wait for child B to finish before exiting
        printf("Parent process A (PID: %d) exiting\n", getpid());
        exit(0);
    }

    return 0;
}


