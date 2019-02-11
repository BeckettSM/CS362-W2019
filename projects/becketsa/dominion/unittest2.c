/*  unittest2.c  -  Test the buyCard() in dominion.c  */

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
   int supplyPos   = 2;

   printf("Unit Test 2: buyCard()\n");

   //Fail testing with not enough coins
   GS.coins   = 4;
   GS.numBuys = 2;
   int c      = GS.coins;
   int nb     = GS.numBuys;

   printf("Fail testing with not enough coins\n");
   if(buyCard(supplyPos, &GS) == -1)
   {  printf("+   Passed with %d coins & %d buys\n", c, nb);  }
   else
   {  printf("x   Failed with %d coins & %d buys\n", c, nb);  }

   //Testing with enough coins
   GS.coins   = 10;
   GS.numBuys = 2;
   c          = GS.coins;
   nb         = GS.numBuys;

   printf("Testing with enough coins\n");
   if(buyCard(supplyPos, &GS) == 0)
   {  printf("+   Passed with %d coins & %d buys\n", c, nb);  }
   else
   {  printf("x   Failed with %d coins & %d buys\n", c, nb);  }

   //Testing with not enough buys
   GS.coins   = 10;
   GS.numBuys = 0;
   c          = GS.coins;
   nb         = GS.numBuys;

   printf("Testing with not enough buys\n");
   if(buyCard(supplyPos, &GS) == -1)
   {  printf("+   Passed with %d coins & %d buys\n", c, nb);  }
   else
   {  printf("x   Failed with %d coins & %d buys\n", c, nb);  }

   printf("Unit Test 2 Complete\n");

   return 0;
 }
