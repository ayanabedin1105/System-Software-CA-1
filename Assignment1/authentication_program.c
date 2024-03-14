#include <stdio.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];

    // Predefined username and password
    char correctUsername[] = "ubuntu";
    char correctPassword[] = "ubuntu";

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Compare entered username and password with predefined ones
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        printf("Login successful.\n");
        // Proceed with Makefile commands or other actions
    } else {
        printf("Login failed. Invalid username or password.\n");
        // Exit or handle failure accordingly
    }

    return 0;
}
