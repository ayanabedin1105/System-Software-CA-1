#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>

void backup_dashboard(void) {
    // Open file for error logging in append mode
    FILE *fptr = fopen("logs.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Print message to indicate file transfer initiation
    fprintf(fptr, "File transfer initiated.\n");

    // Flush the output buffer to ensure immediate writing to the file
    fflush(fptr);

    pid_t pid;
    int status;

    // Get current time
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int hour = local_time->tm_hour;
    int min = local_time->tm_min;

    // Check if the current time is after 1 am
    if (hour >= 1) {
        // Transfer XML files
        pid = fork();
        if (pid == -1) {
            fprintf(fptr, "ERROR. Fork failed.\n");
            exit(1);
        } else if (pid == 0) { // Child process
            char *args[] = {"find", "dashboardDirectory", "-name", "*.xml", "-exec", "cp", "-t", "backupDirectory", "{}", "+", NULL};
            execvp("find", args);
            // If execvp fails, the below code will not be executed
            fprintf(fptr, "ERROR. execvp failed.\n");
            exit(1);
        } else { // Parent process
            // Wait for the child process to finish 
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                fprintf(fptr, "SUCCESS. XML files transferred from dashboardDirectory to backupDirectory.\n");
            } else {
                fprintf(fptr, "ERROR. Failed to transfer XML files from dashboardDirectory to backupDirectory.\n");
            }
        }
    } else {
        fprintf(fptr, "INFO. Waiting for 1 am to transfer XML files.\n");
    }

    // Flush the output buffer again
    fflush(fptr);

    // Close the file
    fclose(fptr);
}


int main() {
    // Your main function code goes here
    return 0;
}
