/***************************
 * unit test for Great Hall
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "great hall"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 10;
   int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int newCards = 0;
   int discard = 0;
   int discardAction = 0;
   int thisPlayer = 0;
   int testH1 = 0, testH2 = 0, testA1 = 0, testA2 = 0;
   int addActions = 0;
   //initialize struct gamstate
   struct gameState G, testG;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Card: %s -----\n", TESTCARD);

   //Test 1: hand count

   printf("----- TEST 1: hand count = +1\n");

   //copy game states for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   choice1 = 1;
   cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
   newCards = 1;
   discard = 1;
   testH1 = testG.handCount[thisPlayer];
   testH2 = G.handCount[thisPlayer] + newCards - discard;

   //print results in test case to confirm hand count
   printf("new hand count = %d, expected = %d\n", testH1, testH2);

   //Test 2: action count
   printf("----- TEST 2: action count\n");


   addActions = 1;
   discardAction = 1;
   testA1 = testG.numActions;
   testA2 = G.numActions + addActions - discardAction;

   //print results in test case to confirm coin count
   printf("new action count = %d, expected = %d\n", testA1, testA2);


   if(testH1 == testH2 && testA1 == testA2){
	printf("TEST SUCCSESFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }


   
   
   return 0;

}


