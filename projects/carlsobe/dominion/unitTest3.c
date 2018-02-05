/********************************
 * unit test for whoseTurn()
 * *****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "whoseTurn()"

int main() {

   //initialize variables
   int numPlayers = 2;
   int seed = 1000;
   int currentPlayer = 0;

   //initialize struct gamstate
   struct gameState G, testG, testG2;

   //initialize kingdom cards
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};


   //initialize game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   
   printf("----- Testing Function: %s -----\n", TESTCARD);

   //Test 1: Test Current Player
   printf("----- TEST 1: Current Player\n");

   //copy game state for test case
   memcpy(&testG, &G, sizeof(struct gameState));
   testG.whoseTurn = currentPlayer;

   //print results in test case to confirm current player
   if(whoseTurn(&testG) == 0){
     printf("We have a Winner! Test Successful!\n");
   }
   else{
     printf("TEST FAILED\n");
   } 

   //Test 2: Test Player 2
   printf("----- TEST 2: Player 2\n");

   //copy game state for test case
   memcpy(&testG2, &G, sizeof(struct gameState));
   testG2.whoseTurn = currentPlayer + 1;

   //print results in test case to confirm current player
   if(whoseTurn(&testG2) == 1){
     printf("We have a Winner! Test Successful!\n");
   }
   else{
     printf("TEST FAILED\n");
   } 

   if(whoseTurn(&testG)==0 && whoseTurn(&testG2)==1){
	printf("TEST SUCCSESSFULLY COMPLETED\n");
   }
   else{
   	printf("TEST FAILED\n");
   }

   return 0;

}


