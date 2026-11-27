#include <stdio.h>

#define MAX_STUDENTS 50
#define SUBJECTS 5
#define PASS_MARK 33

struct Student {
    char name[50];
    int roll;
    int total;
    float percentage;
    char grade;
    int passed;
};

char findGrade(float p) {
    if (p >= 90) return 'A';
    else if (p >= 75) return 'B';
    else if (p >= 60) return 'C';
    else if (p >= 33) return 'D';
    else return 'F';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n, i, j, mark;
    int topper = 0;

    printf("=========================================\n");
    printf("   STUDENT RESULT AND GRADE ANALYZER\n");
    printf("=========================================\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_STUDENTS) {
        printf("Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 0;
    }

    for (i = 0; i < n; i++) {
        students[i].total = 0;
        students[i].passed = 1;

        printf("\n----- Student %d -----\n", i + 1);

        printf("Enter name: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].roll);

        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter marks in subject %d (out of 100): ", j + 1);
            scanf("%d", &mark);

            students[i].total += mark;
            if (mark < PASS_MARK) {
                students[i].passed = 0;
            }
        }

        students[i].percentage = (float)students[i].total / SUBJECTS;

        if (students[i].passed == 1) {
            students[i].grade = findGrade(students[i].percentage);
        } else {
            students[i].grade = 'F';
        }

        if (students[i].total > students[topper].total) {
            topper = i;
        }
    }

    printf("\n\n================= RESULT SHEET =================\n");
    printf("%-18s %-6s %-6s %-8s %-6s %-6s\n",
           "Name", "Roll", "Total", "Percent", "Grade", "Result");
    printf("-------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-18s %-6d %-6d %-7.2f%% %-6c ",
               students[i].name,
               students[i].roll,
               students[i].total,
               students[i].percentage,
               students[i].grade);

        if (students[i].passed == 1) {
            printf("PASS\n");
        } else {
            printf("FAIL\n");
        }
    }

    printf("===============================================\n");
    printf("\nClass Topper: %s (Roll %d) with %.2f%%\n",
           students[topper].name,
           students[topper].roll,
           students[topper].percentage);

    return 0;
}
