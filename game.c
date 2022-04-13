#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dificult;
    int value1;
    int value2;
    int operation;
    int result;
} calculate;

void    play();
void    viewinfo(calculate calc);
int sum();
int multiplication();
int subtraction();


int score = 0;

int main()
{
    play();
}

void    play()
{
    calculate calc;
    int answer;
    int contnue;

    printf("Choose the difficulty level: [1, 2, 3 or 4]: ");
    scanf("%d", &calc.dificult);

    calc.operation = rand() % 3;
    if (calc.dificult == 1)
    {
        calc.value1 = rand() % 11;
        calc.value2 = rand() % 11;
    }
    else if (calc.dificult == 2)
    {
        calc.value1 = rand() % 101;
        calc.value2 = rand() % 101;
    }
    else if (calc.dificult == 3)
    {
        calc.value1 = rand() % 1001;
        calc.value2 = rand() % 1001;
    }
    else if (calc.dificult == 4)
    {
        calc.value1 = rand() % 10001;
        calc.value2 = rand() % 10001;
    }
    else
    {
        calc.value1 = rand() % 100001;
        calc.value2 = rand() % 100001;
    }
    printf("Report the result of the operation\n");

    if (calc.operation == 0)
    {
        printf("%d + %d: ", calc.value1, calc.value2);
        scanf("%d", &answer);

        if (sum(answer, calc))
        {
            score +=1;
            printf("Your score: %d\n", score);
        }
    }
    else if (calc.operation == 1)
    {
        printf("%d - %d: ", calc.value1, calc.value2);
        scanf("%d", &answer);

        if (subtraction(answer, calc))
        {
            score +=1;
            printf("Your score: %d\n", score);
        }
    }
    else if (calc.operation == 2)
    {
        printf("%d * %d: ", calc.value1, calc.value2);
        scanf("%d", &answer);

        if (multiplication(answer, calc))
        {
            score +=1;
            printf("Your score: %d\n", score);
        }
    }
    else
        printf("Invalid operation: %d",calc.operation);
    
    printf("Do you want to continue playing? [1 - Yes, 0 - No]: ");
    scanf("%d", &contnue);

    if (contnue)
        play();
    else
    {
        printf("The end, your score: %d\n", score);
        printf("See you later\n");
    }

}

void    viewinfo(calculate calc)
{
    char    op[25];

    if (calc.operation == 0)
        sprintf(op, "Sum");
    else if (calc.operation == 1)
        sprintf(op, "Subtraction");
    else if (calc.operation == 2)
        sprintf(op, "Multiplication");
    else
        sprintf(op, "Invalid operation");
    printf("Value 1: %d\nValue 2: %d\nDificult: %d\nOperation: %s", calc.value1, calc.value2, calc.dificult, op);
}

int sum(int answer, calculate calc)
{
    int result;
    int right;

    result = calc.value1 + calc.value2;
    calc.result = result;
    right = 0;

    if (answer == calc.result)
    {
        printf("Correct answer\n");
        right = 1;
    }
    else
        printf("Wrong answer\n");
    printf("%d + %d = %d\n",calc.value1, calc.value2, calc.result);
    return (right);
}

int subtraction(int answer, calculate calc)
{
    int result;
    int right;

    result = calc.value1 - calc.value2;
    calc.result = result;
    right = 0;

    if (answer == calc.result)
    {
        printf("Correct answer\n");
        right = 1;
    }
    else
        printf("Wrong answer\n");
    printf("%d - %d = %d\n",calc.value1, calc.value2, calc.result);
    return (right);
}

int multiplication(int answer, calculate calc)
{
    int result;
    int right;

    result = calc.value1 * calc.value2;
    calc.result = result;
    right = 0;

    if (answer == calc.result)
    {
        printf("Correct answer\n");
        right = 1;
    }
    else
        printf("Wrong answer\n");
    printf("%d * %d = %d\n",calc.value1, calc.value2, calc.result);
    return (right);
}