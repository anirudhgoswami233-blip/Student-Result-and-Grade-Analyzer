# Student Result and Grade Analyzer

A simple **C program** that reads marks for a group of students, then calculates
their results and prints a clean result sheet. Built as a beginner-friendly
C programming project.

## ✨ Features

- Takes each student's **name, roll number, and marks in 5 subjects**
- Calculates **total** and **percentage**
- Assigns a **grade** (A / B / C / D / F)
- Decides **Pass / Fail** (fails if any subject is below the pass mark)
- Prints a neat **result sheet** for the whole class
- Finds and announces the **class topper**

## 📋 Grading Rules

| Percentage      | Grade |
|-----------------|-------|
| 90% and above   | A     |
| 75% – 89%       | B     |
| 60% – 74%       | C     |
| 33% – 59%       | D     |
| Below 33%       | F     |

> A student who scores below **33** in *any* single subject is marked **FAIL**
> (and their grade becomes **F**), even if the overall percentage is high.

## 🧠 C Concepts Used

- `struct` to group all data about one student
- Arrays (for marks and for the list of students)
- Loops (`for`) for input and output
- Functions (`findGrade`) to keep logic clean
- `if-else` conditions for grading and pass/fail

## ▶️ How to Run

You need a C compiler such as **gcc**.

```bash
# 1. Compile
gcc result_analyzer.c -o result_analyzer

# 2. Run
# Windows (PowerShell):
.\result_analyzer.exe
# Linux / macOS:
./result_analyzer
```

Then follow the on-screen prompts.

> **No compiler installed?** You can also paste the code into an online
> compiler like [onlinegdb.com](https://www.onlinegdb.com/online_c_compiler)
> and run it in the browser.

## 💻 Example

**Input**
```
Enter number of students: 2

----- Student 1 -----
Enter name: Anirudh Goswami
Enter roll number: 1
Enter marks in subject 1 (out of 100): 95
Enter marks in subject 2 (out of 100): 88
Enter marks in subject 3 (out of 100): 92
Enter marks in subject 4 (out of 100): 90
Enter marks in subject 5 (out of 100): 85

----- Student 2 -----
Enter name: Meena Kumari
Enter roll number: 2
Enter marks in subject 1 (out of 100): 40
Enter marks in subject 2 (out of 100): 30
Enter marks in subject 3 (out of 100): 55
Enter marks in subject 4 (out of 100): 60
Enter marks in subject 5 (out of 100): 70
```

**Output**
```
================= RESULT SHEET =================
Name               Roll   Total  Percent  Grade  Result
-------------------------------------------------------
Anirudh Goswami    1      450    90.00  % A      PASS
Meena Kumari       2      255    51.00  % F      FAIL
===============================================

Class Topper: Anirudh Goswami (Roll 1) with 90.00%
```

## 📝 Notes

- Marks are assumed to be out of **100** per subject (5 subjects = 500 total).
- Supports up to **50 students** (change `MAX_STUDENTS` to allow more).
- Names with spaces are supported.

## 📂 Files

| File                | Description                        |
|---------------------|------------------------------------|
| `result_analyzer.c` | The complete, commented source code |
| `README.md`         | This file                          |
