#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    int x = get_int("x: ");
    
    //prompt user for y
    int y = get_int("y: ");
    
    //compare x and y - to compare use a conditional
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    // by inference, you can also just write "else"
    else if (x == y)
    {
        printf("x is equal to y\n");
    }
}