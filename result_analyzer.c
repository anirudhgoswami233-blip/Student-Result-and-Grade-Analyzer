#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define SUBJECTS      5
#define PASS_MARK     33

struct Student {
    char  name[50];
    int   roll;
    int   marks[SUBJECTS];
    int   total;
    float percentage;
    char  grade;
    char  result[5];        /* "PASS" or "FAIL" */
};

char findGrade(float percentage)
{
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 33) return 'D';
    else                       return 'F';
}

int main(void)
{
    struct Student students[MAX_STUDENTS];
    int n, i, j;

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
        printf("\n----- Student %d -----\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);  /* reads full name, spaces allowed */

        printf("Enter roll number: ");
        scanf("%d", &students[i].roll);

        students[i].total  = 0;
        students[i].result[0] = '\0';
        strcpy(students[i].result, "PASS");   /* assume pass until a subject fails */

        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter marks in subject %d (out of 100): ", j + 1);
            scanf("%d", &students[i].marks[j]);

            students[i].total += students[i].marks[j];

            if (students[i].marks[j] < PASS_MARK)
                strcpy(students[i].result, "FAIL");
        }

        students[i].percentage = students[i].total / (float)(SUBJECTS * 100) * 100;

        students[i].grade = findGrade(students[i].percentage);

        if (strcmp(students[i].result, "FAIL") == 0)
            students[i].grade = 'F';
    }

    printf("\n\n================= RESULT SHEET =================\n");
    printf("%-18s %-6s %-6s %-8s %-6s %-6s\n",
           "Name", "Roll", "Total", "Percent", "Grade", "Result");
    printf("-------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-18s %-6d %-6d %-7.2f%% %-6c %-6s\n",
               students[i].name,
               students[i].roll,
               students[i].total,
               students[i].percentage,
               students[i].grade,
               students[i].result);
    }
    printf("===============================================\n");

    int topper = 0;
    for (i = 1; i < n; i++) {
        if (students[i].total > students[topper].total)
            topper = i;
    }

    printf("\nClass Topper: %s (Roll %d) with %.2f%%\n",
           students[topper].name,
           students[topper].roll,
           students[topper].percentage);

    return 0;
}
