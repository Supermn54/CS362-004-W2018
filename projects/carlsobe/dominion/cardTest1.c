/***************************
 * unit test for Smithy
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "smithy"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 10;
   int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int newCards = 0;
   int discard = 1;
   int shuffledCards = 0;
   int thisPlayer = 0;
   int testH1 = 0, testH2 = 0, testD1 = 0, testD2 = 0;

   //initialize struct gamstate
   struct gameState G, testG;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Card: %s -----\n", TESTCARD);

   //Test 1: choice1 = 1 = +3 cards

   printf("----- TEST: choice1 = 1 = +3 cards\n");

   //copy game states for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   choice1 = 1;
   cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
   newCards = 3;
   testH1 = testG.handCount[thisPlayer];
   testH2 = G.handCount[thisPlayer] + newCards - discard;
   testD1 = testG.deckCount[thisPlayer];
   testD2 = G.deckCount[thisPlayer] - newCards + shuffledCards;

   //print results in test case to confirm hand count
   printf("hand count = %d, expected = %d\n", testH1, testH2);

   //print results in test case to confirm deck count
   printf("deck count = %d, expected = %d\n", testD1, testD2);


   if(testH1 == testH2 && testD1 == testD2){
	printf("TEST SUCCSESFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }


   
   
   return 0;

}


