# 28_team8_hello-world

Program Description

The Student Result System is a menu-driven C program designed to manage, calculate, and analyze academic performance for up to 20 students across 5 subjects.
It uses parallel arrays to store each student's name, subject marks, total score, percentage, grade, and pass/fail status, running inside a do-while loop until the user chooses to exit.

Key Features & Functionality

• Data Entry & Validation (Option 1): Prompts the user for the number of students (validating that the count is between 1 and 20) and records each student's name and marks for 5 subjects.
• Automated Evaluation: Automatically calculates the total marks and percentage (total / 5.0), checks if the student scored at least 40 in every subject to pass, and assigns a letter grade (A through F) based on percentage slabs.
• Result Display (Option 2): Prints a formatted summary for every student showing their name, total marks, percentage, grade, and overall Pass/Fail status.
• Topper Identification (Option 3): Compares total marks across all entered students to find and display the highest scorer along with their percentage.
• Class Average (Option 4): Computes and displays the overall average percentage of the class.
• Input Guardrails: Prevents the user from viewing results, toppers, or averages before entering student data (n == 0), and handles invalid menu selections gracefully.
RESULT OF THE CODE
madhavgarg@Madhavs-MacBook-Air desktop % ./hackathon

--- Student Result System ---
1. Enter student details
2. Show results
3. Show topper
4. Show class average
5. Exit
Enter choice: 1
Enter number of students: 3

Enter name: stu1
Enter marks of subject 1: 91
Enter marks of subject 2: 87
Enter marks of subject 3: 86
Enter marks of subject 4: 89
Enter marks of subject 5: 92

Enter name: stu2
Enter marks of subject 1: 78
Enter marks of subject 2: 87
Enter marks of subject 3: 77
Enter marks of subject 4: 79
Enter marks of subject 5: 71

Enter name: stu3
Enter marks of subject 1: 23
Enter marks of subject 2: 56
Enter marks of subject 3: 55
Enter marks of subject 4: 59
Enter marks of subject 5: 60

Details entered successfully!

--- Student Result System ---
1. Enter student details
2. Show results
3. Show topper
4. Show class average
5. Exit
Enter choice: 2

Name: stu1
Total: 445
Percentage: 89.00
Grade: B
Result: Pass

Name: stu2
Total: 392
Percentage: 78.40
Grade: C
Result: Pass

Name: stu3
Total: 253
Percentage: 50.60
Grade: F
Result: Fail

--- Student Result System ---
1. Enter student details
2. Show results
3. Show topper
4. Show class average
5. Exit
Enter choice: 3

Topper is stu1
Percentage: 89.00

--- Student Result System ---
1. Enter student details
2. Show results
3. Show topper
4. Show class average
5. Exit
Enter choice: 4
Class average = 72.67

--- Student Result System ---
1. Enter student details
2. Show results
3. Show topper
4. Show class average
5. Exit
Enter choice: 5
Program ended

Algorithm

1. Start the program.
2. Initialize n = 0 (number of students) and declare arrays for name, marks, total, per (percentage), grade, and pass.
3. Display the main menu with 5 options and read the user's choice.
4. Evaluate the choice:
	• If choice == 1 (Enter student details):
		• Read the number of students n.
		• If n <= 0 or n > 20, display "Invalid number of students" and reset n = 0.
		• Otherwise, for each student i from 0 to n - 1:
			• Read name[i].
			• Set total[i] = 0 and pass[i] = 1.
			• For each subject j from 0 to 4:
				• Read marks[i][j] and add it to total[i].
				• If marks[i][j] < 40, set pass[i] = 0.
			• Calculate percentage: per[i] = total[i] / 5.0.
			• Assign grade[i]: 'F' if pass[i] == 0 or per[i] < 50; 'A' for >= 90; 'B' for >= 80; 'C' for >= 70; 'D' for >= 60; 'E' for >= 50.
	• If choice == 2 (Show results):
		• If n == 0, display "Enter student details first!".
		• Otherwise, loop through all n students and print their name, total, per, grade, and "Pass" (if pass[i] == 1) or "Fail".
	• If choice == 3 (Show topper):
		• If n == 0, display "Enter student details first!".
		• Otherwise, set topper = 0. Loop from i = 1 to n - 1; if total[i] > total[topper], update topper = i. Print name[topper] and per[topper].
	• If choice == 4 (Show class average):
		• If n == 0, display "Enter student details first!".
		• Otherwise, sum all per[i] values, divide by n, and print the class average.
	• If choice == 5 (Exit):
		• Display "Program ended".
	• Otherwise:
		• Display "Wrong choice!".
5. Repeat steps 3–4 until choice == 5.
6. Stop the program.

Pseudocode

text
BEGIN
    DECLARE n, i, j, choice, topper AS INTEGER
    DECLARE marks[20][5], total[20], pass[20] AS INTEGER
    DECLARE name[20][30], grade[20] AS CHARACTER
    DECLARE per[20], avg AS FLOAT

    SET n = 0

    DO
        PRINT "--- Student Result System ---"
        PRINT "1. Enter student details"
        PRINT "2. Show results"
        PRINT "3. Show topper"
        PRINT "4. Show class average"
        PRINT "5. Exit"
        PRINT "Enter choice: "
        READ choice

        IF choice == 1 THEN
            PRINT "Enter number of students: "
            READ n

            IF n > 20 OR n <= 0 THEN
                PRINT "Invalid number of students"
                SET n = 0
            ELSE
                FOR i = 0 TO n - 1 DO
                    PRINT "Enter name: "
                    READ name[i]

                    SET total[i] = 0
                    SET pass[i] = 1

                    FOR j = 0 TO 4 DO
                        PRINT "Enter marks of subject ", j + 1
                        READ marks[i][j]

                        SET total[i] = total[i] + marks[i][j]

                        IF marks[i][j] < 40 THEN
                            SET pass[i] = 0
                        END IF
                    END FOR

                    SET per[i] = total[i] / 5.0

                    IF pass[i] == 0 THEN
                        SET grade[i] = 'F'
                    ELSE IF per[i] >= 90 THEN
                        SET grade[i] = 'A'
                    ELSE IF per[i] >= 80 THEN
                        SET grade[i] = 'B'
                    ELSE IF per[i] >= 70 THEN
                        SET grade[i] = 'C'
                    ELSE IF per[i] >= 60 THEN
                        SET grade[i] = 'D'
                    ELSE IF per[i] >= 50 THEN
                        SET grade[i] = 'E'
                    ELSE
                        SET grade[i] = 'F'
                    END IF
                END FOR

                PRINT "Details entered successfully!"
            END IF

        ELSE IF choice == 2 THEN
            IF n == 0 THEN
                PRINT "Enter student details first!"
            ELSE
                FOR i = 0 TO n - 1 DO
                    PRINT "Name: ", name[i]
                    PRINT "Total: ", total[i]
                    PRINT "Percentage: ", per[i]
                    PRINT "Grade: ", grade[i]

                    IF pass[i] == 1 THEN
                        PRINT "Result: Pass"
                    ELSE
                        PRINT "Result: Fail"
                    END IF
                END FOR
            END IF

        ELSE IF choice == 3 THEN
            IF n == 0 THEN
                PRINT "Enter student details first!"
            ELSE
                SET topper = 0
                FOR i = 1 TO n - 1 DO
                    IF total[i] > total[topper] THEN
                        SET topper = i
                    END IF
                END FOR

                PRINT "Topper is ", name[topper]
                PRINT "Percentage: ", per[topper]
            END IF

        ELSE IF choice == 4 THEN
            IF n == 0 THEN
                PRINT "Enter student details first!"
            ELSE
                SET avg = 0
                FOR i = 0 TO n - 1 DO
                    SET avg = avg + per[i]
                END FOR

                SET avg = avg / n
                PRINT "Class average = ", avg
            END IF

        ELSE IF choice == 5 THEN
            PRINT "Program ended"

        ELSE
            PRINT "Wrong choice!"
        END IF

    WHILE choice != 5
END
