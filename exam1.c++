#include <stdio.h>
#include <math.h> //pow함수 쓰기위해서

void TruthValueSet(int *list, int n, int size);
void print(int *list, int size);

int main()
{
    int n, *list;

    printf("Input Number(n): ");
    scanf(" %d", &n);
    list = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        list[i] = 0;

    // 	printf("가능한 총 경우의 수는 %.0f개이며, \n", pow(2.0, (double)n));

    TruthValueSet(list, n, n);

    return 0;
}

void TruthValueSet(int *list, int n, int size)
{
    if (n == 0)
        print(list, size);
    else
    {
        TruthValueSet(list, n - 1, size);
        list[n - 1] = 1;
        TruthValueSet(list, n - 1, size);
        list[n - 1] = 0;
    }
}

void print(int *list, int size)
{
    int i = size - 1;
    printf("< ");

    for (; i >= 0; i--)
    {
        if (list[i] == 0)
            printf("FALSE ");
        else
            printf("TRUE ");
    }
    printf(">\n");
}