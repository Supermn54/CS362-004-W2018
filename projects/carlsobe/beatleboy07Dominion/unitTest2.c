/***************************
 * unit test for isGameOver()
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "isGameOver()"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 1000;

   //initialize struct gamstate
   struct gameState G, testG, testG2;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Function: %s -----\n", TESTCARD);

   //Test 1: Winner when Province Pile is Empty
   printf("----- TEST: Province Pile is Empty\n");

   //copy game state for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   testG.supplyCount[province] = 0;
  
   //print results in test case to confirm winner when province is 0
   if(isGameOver(&testG)){
	 printf("We have a Winner! Test Successful!\n");
   }
   else{
   	printf("We don't have a Winner. Test Failed!\n");
   }

   //Test 2: Winner when 3 piles are Empty
   printf("----- TEST: 3 Piles are Empty\n");

   memcpy(&testG2, &G, sizeof(struct gameState));
   testG2.supplyCount[0] = 0;
   testG2.supplyCount[1] = 0;
   testG2.supplyCount[2] = 0;
   
   //print results in test case to confirm deck count
   if(isGameOver(&testG2)){
	 printf("We have a Winner! Test Successful!\n");
   }
   else{
   	printf("We don't have a Winner. Test Failed!\n");
   }

   if(isGameOver(&testG) && isGameOver(&testG2)){
	printf("TEST SUCCSESSFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }

   return 0;

}


