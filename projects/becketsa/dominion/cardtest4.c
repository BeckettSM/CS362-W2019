/*  cardtest4.c  -  Test the great hall card  */
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
   struct gameState TEST_GS;
   struct gameState REF_GS;
   srand(time(NULL));
   int k[10]      = {adventurer, baron, great_hall, embargo, village, feast, mine, sea_hag, salvager, smithy};
   int numplayers = 2;
   int choice1    = 0, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;

   //set up 2 copies fo the gameState
   initializeGame(numplayers, k, rand(), &REF_GS);
   memcpy(&TEST_GS, &REF_GS, sizeof(struct gameState));

   printf("Card Test 4: Great Hall\n");

   //Use great hall with valid inputs
   printf("Use Great Hall with valid inputs\n");
   cardEffect(great_hall, choice1, choice2, choice3, &TEST_GS, handPos, &bonus);
   int player = whoseTurn(&TEST_GS);

   //Check players hand
   if(REF_GS.hand[player][TEST_GS.handCount[player]-1] != -1)
   {  printf("+   Passed, Great Hall card added to hand\n");  }
   else
   {  printf("x   Failed, Great Hall card not added to hand\n");  }

   //Check that card was played
   if(TEST_GS.playedCardCount == REF_GS.playedCardCount+1)
   {  printf("+   Passed, playedCardCount is 1 higher\n");  }
   else
   {  printf("x   Failed, playedCardCount is not 1 higher\n");  }

   //Check that a card was discarded
   if(TEST_GS.discardCount[player] == REF_GS.discardCount[player])
   {  printf("+   Passed, card was discarded\n");  }
   else
   {  printf("x   Failed, card was not discarded\n");  }

   //check for the same number of actions
   if(TEST_GS.numActions == REF_GS.numActions)
   {  printf("+   Passed, equal number of actions\n");  }
   else
   {  printf("x   Failed, unequal number of actions (%d vs. %d)\n", TEST_GS.numActions, REF_GS.numActions);  }

   printf("Card Test 4 Complete\n");

   return 0;
 }
