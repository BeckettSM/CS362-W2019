/*  unittest4.c  -  Test the WhoseTurn() in dominion.c  */
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

   printf("Unit Test 4: WhoseTurn()\n");

   //Test Player 1
   GS.whoseTurn = 1;
   printf("Test Player 1\n");
   if(whoseTurn(&GS) == 1)
   {  printf("+   Passed for player 1\n");  }
   else
   {  printf("x   Failed for player 1\n");  }

   GS.whoseTurn = 2;
   printf("Test Player 2\n");
   if(whoseTurn(&GS) == 2)
   {  printf("+   Passed for player 2\n");  }
   else
   {  printf("x   Failed for player 2\n");  }

   printf("Unit Test 4 Complete\n");

   return 0;
 }
