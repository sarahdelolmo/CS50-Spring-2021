#include <stdio.h>
#include <cs50.h>

 //American Express: 15 digits, starts with 34 or 37
 //Mastercard: 16 digits, starts with 51, 52, 53, 54, or 55
 //Visa: 13 or 16 digits, starts with 4

//CHECKSUM:
//a mathematical relationship between at least one number and others
    //enables computers (or humans who like math) to detect typos (e.g., transpositions),
    //if not fraudulent numbers, without having to query a database, which can be slow


//OBJECTIVE:
//write a program that prompts the user for a credit card number and then reports (via printf)
//whether it is a valid American Express, MasterCard, or Visa card number,

//we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n

//assume that the user’s input will be entirely numeric - do not assume that the user’s input will fit in an int!
//best to use get_long from CS50’s library to get users’ input.

//INFO ABOUT NOTES:
// if it begins with a capital letter, it is description of what is being done; if it doesn't it is an explanation

int main(void)

{
    // Prompt user for card_num between 12 and 16 digits.
    long card_num = 0;
    do
    {
       card_num = get_long("Card number: ");
    }
    while (card_num < 100000000000 || card_num > 9999999999999999);

    // Introduce new variable temp_num to count digits in card_num
    // this is necessary because we do not want to manipulate card_num so we can return to it
    long temp_num = card_num;
    int count = 0;

    // "do" - ALWAYS BRACKETS
    // "while" - ALWAYS PAR
    // "if" && for" - ALWAYS BRACKETS && PAR

    do
    {
        temp_num = temp_num / 10;
        count ++;
    }
    while (temp_num > 0);

    // Eliminate cards without 13, 15, or 16 digits as invalid
    // return 0 means that, if the card number is invalid, we won't have it returned as a value
    //(!) means "does not"
    if (count != 13 && count != 15 && count != 16)
    {
        printf("Invalid.\n");
        return 0;
    }

    // LUHN'S ALGORITHM
    int sum1 = 0; //sum of every other number starting with the LAST digit
    int sum2 = 0; //sum of every other number starting with SECOND TO LAST digit
    int total = 0; //sum of sum1 && sum2
    temp_num = card_num; //we reset the number because we just reduced it to zero via division
    int mod1; //furtherst right side digit
    int mod2;
    int d1;
    int d2;

    //Set up a do-while so the DO (action) repeats WHILE the conditions are met
    do
    {
        // Add last digit to the sum using remainder (mod)
        // the last number will be the number we don't double
            // % 10, therefore gives us the last number of the card number
            // / 10 allows us, then, to remove the last value
            // 1. % 10 gives us the last digit, which we save as mod1
            // 2. we reset temp_num (so we have the whole number again) but divide it by 10
            // ex: 4222222222222 = 2
            // 3. this gives us the card number without the last digit, making the second-last digit the last one
            // ex: 4222222222232 = 422222222223.2; (but since it is an integer we chop off everything behind the decimal) = 422222222223
            // this value is used for the next step to find the second, now last, digit
            // save the value as mod1, add it to sum1
        mod1 = temp_num % 10;
        sum1 = sum1 + mod1; // since sum1 was defined as 0, adding mod1 would make sum1 equal to mod1 - last digit
        temp_num = temp_num / 10;
        // Add the second-last digit (whose digits will be doubled)
        // % 10 on the new temp_num (after it was divided by 10) and save it as mod2
        // / 10 again so, if the do-while is repeated, we start with the third, now last, digit

        // Double second last digit and add digits to sum2
        // after doubling, separate the digits; / 10 gives us the first digit and % 10 gives us the second digit
        // add both digits together to sum2
        mod2 = temp_num % 10;
        mod2 = mod2 * 2;
        d1 = mod2 / 10;
        d2 = mod2 % 10;
        sum2 = sum2 + d1 + d2;
        temp_num = temp_num / 10;

    }
    while (temp_num > 0);

    // Invalidate sums that don't end in zero; if it does, proceed to the card company verification
    total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("Invalid.\n");
        return 0;
    }

    // Isolate the first two numbers (company id)
    // first reset temp_num, then divide by 10 as long as the card has 3 digits (leaving us finally at 2 digits)
    // save the new temp_num (after division) as company_id
    temp_num = card_num;
    do
    {
        temp_num = temp_num / 10;
    }
    while (temp_num > 100);

    int company_id = temp_num;

    // Validate company_id
    // based on criteria given; if we wanted to be more specific, we could add in the Luhn information to our "if" criteria
    // (we don't have to because it was already validated, so it'd just take up more space)
    if ((company_id > 50 && company_id < 56) && (count == 16))
    {
       printf("Mastercard.\n");
    }
    else if ((company_id == 34 || company_id == 37) && (count ==15))
    {
        printf("American Express.\n");
    }
    // we collected the first 2 digits, so we divide by 10 to get the very first digit (and see if its equal to 4)
    else if ((company_id / 10 == 4) && (count == 13 || count == 16))
    {
        printf("Visa.\n");
    }
    else
    {
        printf("Invalid.\n");
    }
}