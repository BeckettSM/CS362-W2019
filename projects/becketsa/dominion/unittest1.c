/*  unittest1.c  -  Test the shuffle() in dominion.c  */
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
   int numtests    = 500;
   int notshuffled = 0;
   int i = 0;

   printf("Unit Test 1: shufle()\n");
   for(i = 0; i < numtests; i++)
   {
     struct gameState startingDeck;
     memcpy(&startingDeck, &GS, sizeof(struct gameState));   //save a copy of the starting deck

     int player = rand() % numplayers;
     shuffle(player, &GS);

     if(memcmp(&startingDeck.deck[player], &GS.deck[player], sizeof(int)*MAX_DECK) != 0)
     {  notshuffled++;  }
   }

   int shuffled = numtests - notshuffled;
   printf("The deck was shuffled %d out of %d times.\n", shuffled, numtests);

   printf("Unit Test 1 Complete\n");

   return 0;
 }
