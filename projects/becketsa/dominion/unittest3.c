/*  unittest3.c  -  Test the getCost() in dominion.c  */
  #include "assert.h"
  #include "dominion.h"
  #include "dominion_helpers.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #include "rngs.h"


 int main(int argc, char ** argv)
 {
   struct gameState GS;
   srand(time(NULL));
   int k[10]       = {adventurer, baron, great_hall, embargo, village, feast, mine, sea_hag, salvager, smithy};
   int numplayers  = rand() % (MAX_PLAYERS - 1) + 1;
   initializeGame(numplayers, k, rand(), &GS);
   int costArr[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
   int i = 0;

   printf("Unit Test 3: getCost()\n");

   //Fail testing with input that is not a card
   printf("Fail testing with input that is not a card\n");
   if(getCost(-1) == -1)
   {  printf("+   Passed\n");  }
   else
   {  printf("x   Failed\n");  }

   //Test all 28 card values
   printf("Test all 27 card values\n");
   for (i = 0; i < 27; i++)
   {
     if(getCost(i) == costArr[i])
     {  printf("+   Passed\n");  }
     else
     {  printf("x   Failed, at costArr position %d\n", i);  }
   }

   printf("Unit Test 3 Complete\n");

   return 0;
 }
