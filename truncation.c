#include <cs50.h>
#include <stdio.h>

//when we put something in quotes, we are telling the computer to say verbatim what is in the quotes
    //computer will also fail to interpret a command within the quotes
    

int main(void)
{
    //get numbers from user
   
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    //for variable "z" we would use "float" in order to store fractions
    //keep in mind: we cannot fit floating point values in integers — CASTING
        //CASTING: supplement (float) to convert variables into floates
    
    float z = (float) x / (float) y;
    
    printf("%f\n", z);
}