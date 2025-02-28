/*
C - basicC-1 /
├── README.md              # Overview of the repository and learning journey
├── basics.c               # Simple operations, loops, conditionals
├── pointers.c             # Pointer examples
├── structures.c           # Structs and unions
├── user_input.c           # User interaction with scanf and select
└── LICENSE                # Optional: e.g., MIT License
*/


// 1.basics.c
#include <stdio.h>

// Print numbers 1 to 5 using an array and a loop
void print_numbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Calculate and print the average of three numbers
void print_average() {
    int numbers[3] = { 100, 200, 120 };
    int average = (numbers[0] + numbers[1] + numbers[2]) / 3;
    printf("The average value is %d\n", average);
}

// Check if a number is between 1 and 10 using && operator
void check_range() {
    int number;
    printf("Type a number from 1 to 10: ");
    scanf("%d", &number);
    if (number >= 1 && number <= 10) {
        printf("Valid number\n");
    }
    else {
        printf("Invalid number\n");
    }
}

int main() {
    // Example 1: Printing numbers
    int numbers[5] = { 1, 2, 3, 4, 5 };
    printf("Numbers 1 to 5: ");
    print_numbers(numbers, 5);

    // Example 2: Average calculation
    print_average();

    // Example 3: Range check with user input
    check_range();

    return 0;
}


// 2.pointers.c

#include <stdio.h>

int main() {
    // Basic pointer example
    int a = 19;
    int* pa = &a;
    printf("Value of a: %d\n", a);
    printf("Value via pointer: %d\n", *pa);

    // Increment a variable using a pointer
    int y = 5;
    int* yp = &y;
    y += 1;     // Direct increment
    *yp += 1;   // Increment via pointer
    printf("Value of y after increments: %d\n", *yp);

    // Validation (optional, shows understanding of pointers)
    if (yp != &y || *yp != 7) {
        printf("Something went wrong with the pointer operations.\n");
        return 1;
    }
    printf("Pointer operations completed successfully.\n");

    return 0;
}


// 3.structures.c

#include <stdio.h>

// Define a person structure
typedef struct {
    char* name;
    int age;
}person;

// Define a union where members share the same memory address
union abc {
    int a;
    char b;
};

int main() {
    // Struct example
    Person p;
    p.name = "L";
    p.age = 29;
    printf("Person: %s, Age: %d\n", p.name, p.age);

    // Union example
    union abc var;
    var.a = 90;              // Set integer value
    union abc* p_var = &var; // Pointer to union
    printf("Union values - Integer: %d, Char: %c\n", p_var->a, p_var->b);
    // Output: 90, Z (90 is ASCII 'Z' when interpreted as char)

    return 0;
}


// 4.user_input.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>

// Read a line with a time limit using select()
char* timed_read_line(int timeout) {
    static char buffer[512];  // Static to persist after function return
    fd_set rfds;
    struct timeval tv;
    int ret;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);  // Monitor stdin (file descriptor 0)

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    ret = select(1, &rfds, NULL, NULL, &tv);
    if (ret > 0 && FD_ISSET(0, &rfds)) {
        memset(buffer, 0, 512);
        ret = read(0, buffer, 511);
        if (ret < 1) return NULL;
        buffer[ret - 1] = '\0';  // Remove newline
        return buffer;
    }
    return NULL;
}

// Simple user input with scanf
void calculate_distance() {
    int speed, time;
    printf("Speed: ");
    scanf("%d", &speed);
    printf("Time: ");
    scanf("%d", &time);
    printf("Distance: %d\n", speed * time);
}

// Check letters common in English and Russian pronunciation
void check_letter() {
    char letter;
    const char* common_letters = "abekmot";
    printf("Type a letter with same pronunciation in English and Russian: ");
    scanf(" %c", &letter);
    if (strchr(common_letters, letter)) {
        printf("That is correct.\n");
    }
    else {
        printf("Try again.\n");
    }
}

int main() {
    // Example 1: Timed input
    printf("What is your name? You have 4 seconds!\n");
    char* name = timed_read_line(4);
    if (name) {
        printf("Hello, %s\n", name);
    }
    else {
        printf("Too slow!\n");
    }

    // Example 2: Distance calculation
    calculate_distance();

    // Example 3: Letter checker
    check_letter();

    return 0;
}

