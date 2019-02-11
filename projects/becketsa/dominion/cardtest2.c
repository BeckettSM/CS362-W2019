/*  cardtest2.c  -  Test the adventurer card  */
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
   int player     = 0, i       = 0, count1  = 0, count2  = 0;

   //set up 2 copies fo the gameState
   initializeGame(numplayers, k, rand(), &REF_GS);
   memcpy(&TEST_GS, &REF_GS, sizeof(struct gameState));

   printf("Card Test 2: Adventurer\n");

   //Use adventurer with valid inputs
   printf("Use Adventurer with valid inputs\n");
   cardEffect(adventurer, choice1, choice2, choice3, &TEST_GS, handPos, &bonus);
   player = whoseTurn(&TEST_GS);

   //Check that an unknown number have cards have been drawn from the deck
   if(TEST_GS.deckCount[player] != REF_GS.deckCount[player])
   {  printf("+   Passed, cards have been drawn from the deck\n");  }
   else
   {  printf("x   Failed, the deck is unchanged\n");  }

   //Check that cards have been added to the hand

   if(TEST_GS.handCount[player]-1 == REF_GS.handCount[player])
   {  printf("+   Passed, check handcount\n");  }
   else
   {  printf("x   Failed, check handcount\n");  }

   //Check players hand
   if(REF_GS.hand[player][TEST_GS.handCount[player]] != -1)
   {  printf("+   Passed, Adventurer card added to hand\n");  }
   else
   {  printf("x   Failed, Adventurer card not added to hand\n");  }

   //Check that card was played
   if(TEST_GS.playedCardCount == REF_GS.playedCardCount+1)
   {  printf("+   Passed, playedCardCount is 1 higher\n");  }
   else
   {  printf("x   Failed, playedCardCount is not 1 higher\n");  }

   //Count Adventurer cards in hand
   for (i = 0; i < REF_GS.handCount[0]; i++)
   {
     if(REF_GS.hand[0][i] == adventurer);
     {  count1++;  }
   }

   for (i = 0; i < TEST_GS.handCount[0]; i++)
   {
     if(TEST_GS.hand[0][i] == adventurer);
     {  count2++;  }
   }

   if(count1 == count2-1)
   {  printf("+   Passed, there is -1 adventurer cards in the hands\n");  }
   else
   {  printf("x   Failed, there is some other value than -1 adventurer cards in the hands\n");  }

   //Check that a card was discarded
   if(TEST_GS.discardCount[player] == REF_GS.discardCount[player])
   {  printf("+   Passed, card was discarded\n");  }
   else
   {  printf("x   Failed, card was not discarded\n");  }

   //Check for -1 Action
   if(TEST_GS.numActions == REF_GS.numActions-1)
   {  printf("+   Passed, 1 action has been used\n");  }
   else
   {  printf("x   Failed, actions have not been reduced by 1 (%d vs. %d)\n", TEST_GS.numActions, REF_GS.numActions);  }

   printf("Card Test 2 Complete\n");

   return 0;
 }
