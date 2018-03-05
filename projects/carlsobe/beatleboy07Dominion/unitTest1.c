/***************************
 * unit test for drawCard()
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "drawCard()"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 1000;
   int thisPlayer = 0;
   int testH1 = 0, testH2 = 0, testD1 = 0, testD2 = 0;

   //initialize struct gamstate
   struct gameState G, testG;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Function: %s -----\n", TESTCARD);

   //Test 1: +1 card
   printf("----- TEST: +1 card to hand\n");

   //copy game state for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   drawCard(thisPlayer, &testG);
   testH1 = testG.handCount[thisPlayer];
   testH2 = G.handCount[thisPlayer] + 1;
   
   //print results in test case to confirm hand count
   printf("hand count = %d, expected = %d\n", testH1, testH2);

   //Test 2: -1 deck
   printf("----- TEST: -1 card from deck\n");

   testD1 = testG.deckCount[thisPlayer];
   testD2 = G.deckCount[thisPlayer] - 1;
   
   //print results in test case to confirm deck count
   printf("deck count = %d, expected = %d\n", testD1, testD2);


   if(testH1 == testH2 && testD1 == testD2){
	printf("TEST SUCCSESSFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }

   return 0;

}


