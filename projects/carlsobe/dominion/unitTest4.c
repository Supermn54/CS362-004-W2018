/********************************
 * unit test for numHandCards()
 * *****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "numHandCards()"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 1000;
   int currentPlayer = 0;
   //initialize struct gamstate
   struct gameState G, testG;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Function: %s -----\n", TESTCARD);

   //Test 1: Test Hand Count
   printf("----- TEST 1: Hand Count\n");

   //copy game state for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   int newCount = numHandCards(&testG);
   int oldCount = G.handCount[currentPlayer];

   //print results in test case to confirm current player
   printf("Hand Count: %d, expected: %d\n", newCount, oldCount);

   if(newCount == oldCount){
	printf("TEST SUCCSESSFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }

   return 0;

}


