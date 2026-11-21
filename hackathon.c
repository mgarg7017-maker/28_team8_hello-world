#include <stdio.h>

int main()
{
    int n, i, j, choice;
    int marks[20][5], total[20], pass[20];
    char name[20][30], grade[20];
    float per[20], avg;
    int topper;

    n = 0;

    do
    {
        printf("\n--- Student Result System ---\n");
        printf("1. Enter student details\n");
        printf("2. Show results\n");
        printf("3. Show topper\n");
        printf("4. Show class average\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter number of students: ");
            scanf("%d", &n);

            if(n > 20 || n <= 0)
            {
                printf("Invalid number of students\n");
                n = 0;
            }
            else
            {
                for(i = 0; i < n; i++)
                {
                    printf("\nEnter name: ");
                    scanf("%29s", name[i]);

                    total[i] = 0;
                    pass[i] = 1;

                    for(j = 0; j < 5; j++)
                    {
                        printf("Enter marks of subject %d: ", j + 1);
                        scanf("%d", &marks[i][j]);

                        total[i] = total[i] + marks[i][j];

                        if(marks[i][j] < 40)
                            pass[i] = 0;
                    }

                    per[i] = total[i] / 5.0;

                    if(pass[i] == 0)
                        grade[i] = 'F';
                    else if(per[i] >= 90)
                        grade[i] = 'A';
                    else if(per[i] >= 80)
                        grade[i] = 'B';
                    else if(per[i] >= 70)
                        grade[i] = 'C';
                    else if(per[i] >= 60)
                        grade[i] = 'D';
                    else if(per[i] >= 50)
                        grade[i] = 'E';
                    else
                        grade[i] = 'F';
                }

                printf("\nDetails entered successfully!\n");
            }
        }

        else if(choice == 2)
        {
            if(n == 0)
                printf("Enter student details first!\n");
            else
            {
                for(i = 0; i < n; i++)
                {
                    printf("\nName: %s\n", name[i]);
                    printf("Total: %d\n", total[i]);
                    printf("Percentage: %.2f\n", per[i]);
                    printf("Grade: %c\n", grade[i]);

                    if(pass[i] == 1)
                        printf("Result: Pass\n");
                    else
                        printf("Result: Fail\n");
                }
            }
        }

        else if(choice == 3)
        {
            if(n == 0)
                printf("Enter student details first!\n");
            else
            {
                topper = 0;

                for(i = 1; i < n; i++)
                {
                    if(total[i] > total[topper])
                        topper = i;
                }

                printf("\nTopper is %s\n", name[topper]);
                printf("Percentage: %.2f\n", per[topper]);
            }
        }

        else if(choice == 4)
        {
            if(n == 0)
                printf("Enter student details first!\n");
            else
            {
                avg = 0;

                for(i = 0; i < n; i++)
                    avg = avg + per[i];

                avg = avg / n;

                printf("Class average = %.2f\n", avg);
            }
        }

        else if(choice == 5)
            printf("Program ended\n");

        else
            printf("Wrong choice!\n");

    } while(choice != 5);

    return 0;
}
