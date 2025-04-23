#include <stdio.h>
#include <string.h>

// Function prototypes
void inputMarks(char subjects[][50], float marks[], int numSubjects);
float calculateTotal(float marks[], int numSubjects);
float calculateAverage(float total, int numSubjects);
char determineGrade(float average);
void displayResults(char subjects[][50], float marks[], int numSubjects, float total, float average, char grade);

int main() {
    // Constants
    const int NUM_SUBJECTS = 5;
    
    // Variables
    char studentName[50];
    char subjects[5][50] = {"Mathematics", "Science", "English", "History", "Computer Science"};
    float marks[5];
    float total, average;
    char grade;
    
    // Program header
    printf("\n==== STUDENT MARKS & GRADE MANAGEMENT SYSTEM ====\n\n");
    
    // Input student name
    printf("Enter student name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0'; // Remove newline character
    
    // Input marks for each subject
    inputMarks(subjects, marks, NUM_SUBJECTS);
    
    // Calculate total, average and grade
    total = calculateTotal(marks, NUM_SUBJECTS);
    average = calculateAverage(total, NUM_SUBJECTS);
    grade = determineGrade(average);
    
    // Display results
    printf("\n==== RESULTS FOR %s ====\n", studentName);
    displayResults(subjects, marks, NUM_SUBJECTS, total, average, grade);
    
    return 0;
}

// Function to input marks for each subject
void inputMarks(char subjects[][50], float marks[], int numSubjects) {
    int i;
    
    printf("\nEnter marks for each subject (0-100):\n");
    
    for (i = 0; i < numSubjects; i++) {
        do {
            printf("%s: ", subjects[i]);
            scanf("%f", &marks[i]);
            
            // Validate marks (0-100)
            if (marks[i] < 0 || marks[i] > 100) {
                printf("Invalid marks! Please enter marks between 0 and 100.\n");
            }
        } while (marks[i] < 0 || marks[i] > 100);
    }
}

// Function to calculate total marks
float calculateTotal(float marks[], int numSubjects) {
    float sum = 0;
    int i;
    
    for (i = 0; i < numSubjects; i++) {
        sum += marks[i];
    }
    
    return sum;
}

// Function to calculate average marks
float calculateAverage(float total, int numSubjects) {
    return total / numSubjects;
}

// Function to determine grade based on average
char determineGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to display the results
void displayResults(char subjects[][50], float marks[], int numSubjects, float total, float average, char grade) {
    int i;
    
    printf("\nSUBJECT-WISE MARKS:\n");
    printf("------------------\n");
    
    for (i = 0; i < numSubjects; i++) {
        printf("%-20s: %.2f\n", subjects[i], marks[i]);
    }
    
    printf("\nSUMMARY:\n");
    printf("--------\n");
    printf("Total Marks      : %.2f / %.2f\n", total, numSubjects * 100.0);
    printf("Average          : %.2f%%\n", average);
    printf("Grade            : %c\n", grade);
    
    // Add a message based on the grade
    printf("\nREMARK: ");
    switch (grade) {
        case 'A':
            printf("Excellent performance!\n");
            break;
        case 'B':
            printf("Good performance!\n");
            break;
        case 'C':
            printf("Average performance.\n");
            break;
        case 'D':
            printf("Below average. Need improvement.\n");
            break;
        case 'F':
            printf("Failed. Need significant improvement.\n");
            break;
    }
}
