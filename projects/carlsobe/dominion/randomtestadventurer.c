/*****************************
 * random test for Adventurer
 * **************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TESTCARD "adventurer"

int main() {

  //initialize variables
  int players = 0;
  int seed = 10;
  int thisPlayer = 0;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int newCards = 2;
  int testH1 = 0, testH2 = 0, testD1 = 0, testD2 = 0;
  int n = 1000; //number of random tests
  int i = 0, x = 0, y = 0, pass = 0, fail = 0;

  //initialise struct gamestate
  struct gameState G, testG;

  //initialize srand
  srand(time(NULL));
  
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
 
  //Print test
  printf("----- Testing Card: %s -----\n", TESTCARD);
  printf("----- RANDOM TEST -----\n");

  //insert random input for n number of times for gamestate
  for (x = 0; x < n; x++){
  	//add memory
  	for (i = 0; i < sizeof(struct gameState); i++){
		((char*)&G)[i] = rand() % 256;
	}
	
	int treasure1 = 0, treasure2 = 0;

	players = (rand() % 3)+2;
	
	//initialize gamestate
	initializeGame(players, k, seed, &G);
	
	//randomly assign input
        thisPlayer = whoseTurn(&G); //assign current turn to current player
	G.handCount[thisPlayer] = (rand() % (MAX_HAND/2))+1; //at least half in the case of 2 players
	G.deckCount[thisPlayer] = (rand() % (MAX_DECK/2))+1; //at least half in the case of 2 players  
 	handpos = (rand() % G.handCount[thisPlayer]);		
   	
	//count number of G treasure cards
	y = 0;
	while (y < numHandCards(&G)){
	   if (handCard(y, &G) == copper || handCard(y, &G) == silver || handCard(y, &G) == gold){
	      treasure1++;
	   }
	   y++;
	}

	//copy game state for test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	//call target function
	//choice1 =1;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	//assign output variables
	testH1 = testG.handCount[thisPlayer];
	testH2 = G.handCount[thisPlayer] + newCards;
	testD1 = testG.deckCount[thisPlayer] + testG.discardCount[thisPlayer];
	testD2 = G.deckCount[thisPlayer] + G.discardCount[thisPlayer] - newCards;

	//count number of testG treasure cards
	y = 0;
	while (y < numHandCards(&G)){
	   if (handCard(y, &G) == copper || handCard(y, &G) == silver || handCard(y, &G) == gold){
	      treasure2++;
	   }
	   y++;
	}
	
   	//print results in test case to confirm hand count
        //printf("hand count = %d, expects = %d\n", testH1, testH2);
   
	//print results in test case to confirm deck count
	//printf("total count = %d, expected = %d\n", testD1, testD2);
	
	//print results in test case to confirm action account
	//printf("treasure card count = %d, expected = %d\n", treasure2, treasure1);
		
   	//print overall test result
	if(testH1 == testH2 && testD1 == testD2 && treasure1 == treasure2){
	  // printf("TEST SUCCESFULLY COMPLETED\n");
	  pass++;
	}
	else{
	   //printf("TEST FAILED\n");
	   fail++;
	}
  };
printf("The %s card failed %d times and passed %d times out of a total of %d tests.\n", TESTCARD, fail, pass, n);


   return 0;
}
