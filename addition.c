#include <stdio.h>
#include <cs50.h>

//"int" is capped on the size of our integers (2bill ints) since there bc limitations in computer hardwar
    //as we express more bits && bites with bigger integers, we use more data and further stress our hardware

//we can switch data-type "get_int" (%i) to "get_long" (%lo) that uses more bits to store greater values

//you can also switch data-type into "get_float" (%f) to include decimal numbers 

int main(void)
{
    int x;
    int y;
    x = get_int("x: ");
    
    y = get_int("y: ");
    
    printf("%i\n", x + y;
}