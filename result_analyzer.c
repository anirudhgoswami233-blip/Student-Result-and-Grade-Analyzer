#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 50
#define SUBJECTS     5
#define PASS_MARK    33

typedef struct {
    char  name[50];
    int   roll;
    int   total;
    float percentage;
    char  grade;
    bool  passed;
} Student;

static char findGrade(float p) {
    if (p >= 90) return 'A';
    if (p >= 75) return 'B';
    if (p >= 60) return 'C';
    if (p >= 33) return 'D';
    return 'F';
}

int main(void) {
    Student students[MAX_STUDENTS];
    int n, topper = 0;

    printf("=========================================\n"
           "   STUDENT RESULT AND GRADE ANALYZER\n"
           "=========================================\n\n"
           "Enter number of students: ");

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS) {
        printf("Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Student *s = &students[i];
        s->total  = 0;
        s->passed = true;

        printf("\n----- Student %d -----\n", i + 1);
        printf("Enter name: ");
        scanf(" %49[^\n]", s->name);

        printf("Enter roll number: ");
        scanf("%d", &s->roll);

        for (int j = 0; j < SUBJECTS; j++) {
            int mark;
            printf("Enter marks in subject %d (out of 100): ", j + 1);
            scanf("%d", &mark);
            s->total += mark;
            if (mark < PASS_MARK) s->passed = false;
        }

        s->percentage = (float)s->total / SUBJECTS;
        s->grade = s->passed ? findGrade(s->percentage) : 'F';

        if (s->total > students[topper].total)
            topper = i;
    }

    printf("\n\n================= RESULT SHEET =================\n"
           "%-18s %-6s %-6s %-8s %-6s %-6s\n"
           "-------------------------------------------------------\n",
           "Name", "Roll", "Total", "Percent", "Grade", "Result");

    for (int i = 0; i < n; i++) {
        Student *s = &students[i];
        printf("%-18s %-6d %-6d %-7.2f%% %-6c %-6s\n",
               s->name, s->roll, s->total, s->percentage,
               s->grade, s->passed ? "PASS" : "FAIL");
    }

    printf("===============================================\n\n"
           "Class Topper: %s (Roll %d) with %.2f%%\n",
           students[topper].name, students[topper].roll, students[topper].percentage);

    return 0;
}
