/***************************
 * unit test for Adventurer
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "adventurer"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 10;
   int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int newCards = 0;
   int discard = 1;
   int thisPlayer = 0;
   int testH1 = 0, testH2 = 0, testC1 = 0, testC2 = 0, testD1 = 0, testD2 = 0;

   //initialize struct gamstate
   struct gameState G, testG;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Card: %s -----\n", TESTCARD);

   //Test 1: hand count

   printf("----- TEST 1: hand count = +2\n");

   //copy game states for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   choice1 = 1;
   cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
   newCards = 2;
   testH1 = testG.handCount[thisPlayer];
   testH2 = G.handCount[thisPlayer] + newCards - discard;

   //print results in test case to confirm hand count
   printf("new hand count = %d, expected = %d\n", testH1, testH2);

   //Test 2: coin count
   printf("----- TEST 2: coin count\n");


   testC1 = testG.coins;
   testC2 = G.coins;;

   //print results in test case to confirm coin count
   printf("new coin count = %d, expected = %d\n", testC1, testC2);

   //Test 3: discard + deck count
   printf("----- Test 3: discard + deck count\n");

   testD1 = testG.discardCount[thisPlayer] + testG.deckCount[thisPlayer];
   testD2 = G.discardCount[thisPlayer] + G.deckCount[thisPlayer] - newCards;

   //print results in test to confirm discard + deck count
   printf("new discard+deck count = %d, expected = %d\n", testD1, testD2);



   if(testH1 == testH2 && testC1 == testC2 && testD1 == testD2){
	printf("TEST SUCCSESFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }


   
   
   return 0;

}


