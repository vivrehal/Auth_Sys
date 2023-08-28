#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vcrypt.h"
#include <time.h>

struct User {
    char username[50];
    char password[65];
};

int userExists(const char *username) {
    struct User user;
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return 0;
    }

    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int registerUser() {
    struct User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    if (userExists(newUser.username)) {
        printf("Username already exists.\n");
        return 0;
    }
    printf("Enter a password: ");
    char pass[50];
    scanf("%s",pass);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    vcrypt((uint8_t *)pass, strlen(pass), newUser.password);
    printf("Your Hashed Password: %s\n", newUser.password);
 
    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);

    printf("Registration successful!\n");
    return 1;

}


void loginUser() {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);
    
    if (!userExists(username)) {
        printf("User does not exist.\n");
        return;
    }

    printf("Enter your password: ");
    scanf("%s", password);

    struct User user;
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char hashedpass[65];
    vcrypt((uint8_t *)password, strlen(password), hashedpass);
    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0 && strcmp(hashedpass, user.password) == 0) {
            fclose(file);
            printf("Login successful!\n");
            return;
        }
    }

    fclose(file);
    printf("Incorrect password.\n");
}

int main() {
    int reg_count=0;
    clock_t start,end;
    double timetaken;
    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
		start=clock();
                int flag=registerUser();
		if(flag){
			reg_count++;
		}
		end=clock();
		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
                printf("\nTime Taken: %f seconds\n",timetaken);
		break;
            case 2:
		start=clock();
                loginUser();
		end=clock();
		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
                printf("\nTime Taken: %f seconds\n",timetaken);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
	printf("\n");
    } while (choice != 3);

    size_t spaceused=sizeof(struct User);
    printf("Total new Registrations: %d\n", reg_count);
    printf("Space used by new registrations: %f KB\n", (double)(spaceused*reg_count)/(double)1024);

    return 0;
}
