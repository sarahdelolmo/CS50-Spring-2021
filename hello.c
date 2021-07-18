#include <stdio.h>
#include <cs50.h>

//(cd) stands for "current directory"

int main(void)

{
    printf("Hello, world\n");

    string name = get_string("What is your name?\n");

    printf("Hello, %s\n", name);
}
