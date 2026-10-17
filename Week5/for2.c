#include <stdio.h>
int main ()
{
    int mark[5];
    for (int i =0; i<5; i++)
    {
        printf("Enter mark %d: ", i+1);
        scanf("%d", &mark[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", mark[i]);

    }
    return 0;
}