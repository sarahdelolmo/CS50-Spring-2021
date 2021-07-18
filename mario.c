#include <stdio.h>
#include <cs50.h>

//            int main (void)
//            {
//                int height;
//                do
//                {
//                    height = get_int("Height: ");
//                }
//                while (height < 1 || height > 8);
//                
//                for (int p = 0; p < height; p++)
//                {
//                    for (int q = (height - 1); q > p; q--)
//                    {
//            printf(" ");
//        for (int o = 0; o <= p; o++)
//        {
//            printf("#");
//        }
//      printf("\n");
//    }
//}

int main(void)

{
    //we need to specify the height of the triangle
    int height;
    //always going to DO something at least once...
    do
    {
        //ask for user input (get_int); this will be our height
        height = get_int("Height: ");
    }
    //we want to reject inputs LESS than 1 (height < 1) OR (||) MORE than 8 (height > 8)
    //as long as input is not legit, we will keep DOing it
    while (height < 1 || height > 8); 
    
    //our number of rows starts at 1; we add a row (row++) as long as number of rows is less than/equal to specified height (row <= height)
    for (int row = 1; row <= height; row++)
    {
        //print space to make triangle right-aligned
        //we start with 1 space; we add a space (space++) as long as spaces are less than/euqal to specified height MINUS number of rows (spaces <= height - row)
        for (int spaces = 1; spaces <= height - row; spaces++)
        {
            printf(" ");
        }
        //print # for rach row
        //printer row number of times; i.e. row 2 = 2 hashtags
        for(int hashtags = 1; hashtags <= row; hashtags++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}