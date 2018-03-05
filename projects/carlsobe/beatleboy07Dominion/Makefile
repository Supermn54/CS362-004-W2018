CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

testresults.out:
	echo "Running Unit Tests & Random Tests..." > testresults.out

	echo "cardTest1.c:" >> testresults.out
	gcc -std=c99 -o cardTest1 cardTest1.c -g dominion.c rngs.c $(CFLAGS)
	cardTest1 >> testresults.out
	gcov dominion.c >> testresults.out

	echo "randomtestcard1.c:" >> testresults.out
	gcc -std=c99 -o randomtestcard1 randomtestcard1.c -g dominion.c rngs.c $(CFLAGS)
	randomtestcard1 >> testresults.out
	gcov -abcfu dominion.c >> testresults.out 
	
	echo "cardTest2.c:" >> testresults.out
	gcc -std=c99 -o cardTest2 cardTest2.c -g dominion.c rngs.c $(CFLAGS)
	cardTest2 >> testresults.out
	gcov dominion.c >> testresults.out

	echo "randomtestadventurer.c:" >> testresults.out
	gcc -std=c99 -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.c $(CFLAGS)
	randomtestadventurer >> testresults.out
	gcov -abcfu dominion.c >> testresults.out
	

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f cardTest1 cardTest2 randomtestcard1 randomtestadventurer testresults.out
