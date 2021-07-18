#include <stdio.h>
#include <cs50.h>

//int main(void)
//
//    {
//    int height;
//        // prompt user for height
//        do 
//        {
//            height = get_int("Height: ");
//        }
//        while (height < 1 || height > 8);
//        
//        // int p indicates the height, so for each row...
//        for (int p = 0; p < height; p++)
//        {
//           // add the appropriate spaces (always one less than the height)
//           for (int q = (height - 1); q > p; q--)
//           {
//               printf(" ");
//           }
//           // add the appropriate #
//           for (int r = 0; r <= p; r++)
//           {
//               printf("#");
//           }
//           // add a gap
//            printf("  ");
//           // add the final #, which follows the same format of line 24 because there would be the same amount on each side as the gap
//           for (int s = 0; s <= p; s++)
//           {
//               printf("#");
//           }
//        // start a new row
//        printf("\n");
//        }
//  }
//
//    #
//   ##
//  ###
// ####

int main(void)

{
    //ASKING FOR HEIGHT
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); 
    
    //MAKING LEFT TRIANGLE
    for (int row = 1; row <= height; row++)
    {
        for (int spaces = 1; spaces <= height - row; spaces++)
        {
            printf(" ");
        }
        for (int hashtags = 1; hashtags <= row; hashtags++)
        {
            printf("#");
        }
        
        //MAKE THE DIVIDE BETWEEN TRIANGLES (2 spaces)
        printf("  ");
        
        //MAKING THE RIGHT TRIANGLE
         for (int hashtags = 1; hashtags <= row; hashtags++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    return 0;
}