#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for a cc number; if they give invalid number print inv

    long cardinfo = get_long ("Enter your card number:  ");
    bool brand = true;
    bool runtest = true;

    //test for valid input
        if (cardinfo / 1000000000000 == 0 || cardinfo / 10000000000000000 > 0)
            {
                    printf ("INVALID, try running the program again \n");
                    runtest = false;
                    brand = false;
            }

        if (runtest == true)
        {
            // test card via algorithm

                    // test one - multiply every other digit by 2 (starting with second to last) then add the DIGITS of the product together
                    int running_total = 0;
                    int checktwosum = 0;
                    int finaltotal = 0;
                    int test = 0;
                    for (long checkone = cardinfo / 10; checkone > 0; checkone = checkone / 100)
                    {
                        int y = 0;
                        int z = 0;
                        int a = 0;
                        test = 1;
                        long x = (checkone % 10);
                        x = x * 2;
                        if (x >= 10)
                        {
                                y = x % 10;
                                z = x / 10;
                                a = y + z;
                        }
                        else
                        {
                                a = x;
                        }
                        running_total = a + running_total;
                    }

                    // test two - add (the sum of the DIGITS that weren't multiplied by 2) to (the result from part one)
                    for (long checktwo = cardinfo; checktwo > 0; checktwo = checktwo / 100)
                    {
                            long y = (checktwo % 10);
                            checktwosum = y + checktwosum;
                    }

                        finaltotal = running_total + checktwosum;
                    // test three - check if last digit is 0 , you might need to move this section below the brand
                    if (finaltotal % 10 == 0)
                        {
                                printf ("Valid  ");
                        }
                    else
                    {
                            printf ("INVALID \n");
                            brand = false;
                    }
        }

        if (brand == true)
        {
                bool otherbrand = true;
            // check card brand
                // test 13 digit card
                long b = 0;
                for (int i = 1; i > 0; i--)
                {
                        b = cardinfo / 1000000000000;
                      if (b == 4)
                      {
                              printf ("VISA \n");
                              otherbrand = false;
                      }
                }
                // 15 digit test
                for (int i = 1; i > 0; i--)
                {
                        b = cardinfo / 10000000000000;
                        if (b == 34 || b == 37)
                        {
                                printf ("AMERICAN EXPRESS \n");
                                otherbrand = false;
                        }
                }

                //16 digit tests
                for (int i = 1; i > 0; i--)
                {
                 b = cardinfo / 100000000000000;
                        // mastercard test
                        if (b == 51 || b == 52 || b == 53 || b == 54 || b == 55)
                        {
                                printf ("MASTERCARD \n");
                                otherbrand = false;

                        }
                        // visa test
                        if (b == 40 || b == 41 || b == 42 || b == 43 || b == 44 || b == 45 || b == 46 || b == 47 || b == 48 || b == 49)
                        {
                                printf ("VISA \n");
                                otherbrand = false;
                        }
                }
                if (otherbrand == true)
                {
                        printf ("-- Your card is valid but it's not an AMEX, VISA, or Mastercard. Get a new provider! \n");
                }


        }













}