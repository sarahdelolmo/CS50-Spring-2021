#include <cs50.h>
#include <stdio.h>

// const int TOTAL = _; can be used to retain a constant variable that cannot be changed
const int TOTAL = 3;

int main(void)
{
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
      scores[i] = get_int("Score: ");
    }

    printf("Average: %d\n", (scores[0] + scores[1] + scores[2]) / TOTAL);
}
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
