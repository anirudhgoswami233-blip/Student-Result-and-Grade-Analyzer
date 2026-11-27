# Student Result and Grade Analyzer

A simple C program that reads marks for a group of students, works out their
total, percentage and grade, and prints a clean result sheet with the class topper.

## How it works
- Enter the number of students, then each student's name, roll number and marks in 5 subjects.
- The program adds up the marks, finds the percentage, and gives a grade:
  A (90+), B (75+), C (60+), D (33+), F below that.
- Fail any one subject (below 33) and the grade is F.
- At the end it shows a result sheet and the student with the highest total.

## Build and run
```
gcc result_analyzer.c -o result_analyzer
./result_analyzer
```

## Testing
I ran it a few times to make sure the numbers come out right:

| Marks entered        | Total | Percent | Grade | Result |
|----------------------|-------|---------|-------|--------|
| 90 88 95 70 85       | 428   | 85.60%  | B     | PASS   |
| 30 60 60 60 60       | 270   | 54.00%  | F     | FAIL   |
| 95 92 98 90 91       | 466   | 93.20%  | A     | PASS   |

Checks I made sure of:
- A student failing one subject gets F even if the percentage is high.
- Entering 0 or more than 50 students is rejected with a message.
- Names with spaces (like "Alice Smith") are read fully.
- The topper is the one with the highest total.
