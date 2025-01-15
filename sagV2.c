#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {    
    int menuChoice, arr[10];
    while(true) {
        printf("\n\nData Structures and Algorithms\n       Final Project \n\n         Main Menu\n----------------------------------\n[1] Bubble Sort\n[2] Largest Element in the Array\n[3] Prime Number Identifier\n[4] Exit\n\n");
        printf("Enter your choice: ");
        menuChoice = getValidInput();  
        switch (menuChoice) {
            case 1:
                while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n        Bubble Sort\n----------------------------------\nThis mini program will sort a set of 10 numbers using the Bubble Sort algorithm.\n");
                    enterNumber(arr);  bubbleSort(arr);
                    if (continueProgram()) { continue; } else { break;}
                }
                break;
            case 2:
            while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n Largest Element in the Array\n----------------------------------\nThis mini program will find the largest element in a set of 10 numbers.\n");
                    enterNumber(arr);  largestElement(arr);
                    if (continueProgram()) { continue; } else { break;}
                }
                break;
            case 3:
            while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n   Prime Number Identifier\n----------------------------------\nThis mini program will find all prime numbers in a set of 10 numbers.\n");
                    enterNumber(arr);  primeNumber(arr);
                    if (continueProgram()) { continue; } else { break;}
                }
                break;
            case 4:
                exitProgram();
                break; 
        }   
    } 
}

int getValidInput() {
    int input;
    while (true) {
        if (scanf("%d", &input) != 1 || getchar() != '\n') {
            printf("\033[1;31mInvalid input. Please enter a valid number.\033[0m\n");
            while (getchar() != '\n');
            printf("Enter your choice: ");
        } else {
            if (input >= 1 && input <= 4) {
                return input;
            } else {
                printf("\033[1;31mInvalid choice. Please enter a number between 1 and 4.\033[0m\n");
                printf("Enter your choice: ");
            }
        }
    }
}

void exitProgram() {
    char continueChoice;
    do {
        printf("\nAre you sure you want to EXIT [Y/N]: ");
        if (scanf(" %c", &continueChoice) != 1 || getchar() != '\n') {
            printf("\033[1;31mInvalid input. Please enter a single character: 'Y' or 'N'.\033[0m\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (strchr("yYnN", continueChoice) == NULL) {
            printf("\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n");
        } else if (continueChoice == 'Y' || continueChoice == 'y') {
            exit(0); 
        } else {
            system("cls");
            return; 
        }
    } while (true);
}

int continueProgram() {
    char continueChoice;
    do {
        printf("\nDo you want to continue [Y/N]: ");
        if (scanf(" %c", &continueChoice) != 1 || getchar() != '\n') {
            printf("\033[1;31mInvalid input. Please enter a single character: 'Y' or 'N'.\033[0m\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (strchr("yYnN", continueChoice) == NULL) {
            printf("\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n");
        } else if (continueChoice == 'Y' || continueChoice == 'y') {
            return true;
        } else {
            return false;
        }
    } while (true);
}

void enterNumber(int arr[]) {
    char input[200];
    int numCount;
    printf("\nEnter a set of 10 values (separated by spaces): ");
    while (true) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        char *token = strtok(input, " ");
        numCount = 0;
        int valid = 1;
        while (token != NULL) {
            for (int i = 0; token[i] != '\0'; i++) {
                if (!isdigit(token[i]) && !(i == 0 && token[i] == '-')) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                break;
            }
            arr[numCount++] = atoi(token);
            token = strtok(NULL, " ");
        }
        if (valid && numCount == 10) {
            break;
        } else {
            printf("\033[1;31mInvalid input. Please enter exactly 10 integers separated by spaces.\033[0m\n");
            printf("\nEnter a set of 10 values (separated by spaces): ");
        }
    }
}

void bubbleSort(int arr[]) {
    bool isSorted = false;
    int pass = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < 9 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;   
            }
        }
        printf("Pass %d: ", ++pass);
        for (int k = 0; k < 10; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void largestElement(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The largest element in the array is: %d\n", max);
}

void primeNumber(int arr[]) {
    printf("Prime numbers in the array are: ");
    for (int i = 0; i < 10; i++) {
        int isPrime = arr[i] > 1;
        for (int j = 2; j * j <= arr[i] && isPrime; j++) {
            if (arr[i] % j == 0) isPrime = 0;
        }
        if (isPrime) printf("%d ", arr[i]);
    }
    printf("\n");
}




