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

unittestresults.out:
	echo "Running Unit Tests..." > unittestresults.out

	echo "unitTest1.c:" >> unittestresults.out
	gcc -o unitTest1 unitTest1.c -g dominion.c rngs.c $(CFLAGS)
	unitTest1 >> unittestresults.out
	gcov unitTest1 >> unittestresults.out

	echo "unitTest2.c:" >> unittestresults.out
	gcc -o unitTest2 unitTest2.c -g dominion.c rngs.c $(CFLAGS)
	unitTest2 >> unittestresults.out
	gcov unitTest2 >> unittestresults.out
	
	echo "unitTest3.c:" >> unittestresults.out
	gcc -o unitTest3 unitTest3.c -g dominion.c rngs.c $(CFLAGS)
	unitTest3 >> unittestresults.out
	gcov unitTest3 >> unittestresults.out
	
	echo "unitTest4.c:" >> unittestresults.out
	gcc -o unitTest4 unitTest4.c -g dominion.c rngs.c $(CFLAGS)
	unitTest4 >> unittestresults.out
	gcov unitTest4 >> unittestresults.out
	
	echo "cardTest1.c:" >> unittestresults.out
	gcc -o cardTest1 cardTest1.c -g dominion.c rngs.c $(CFLAGS)
	cardTest1 >> unittestresults.out
	gcov cardTest1 >> unittestresults.out

	echo "cardTest2.c:" >> unittestresults.out
	gcc -o cardTest2 cardTest2.c -g dominion.c rngs.c $(CFLAGS)
	cardTest2 >> unittestresults.out
	gcov cardTest2 >> unittestresults.out

	echo "cardTest3.c:" >> unittestresults.out
	gcc -o cardTest3 cardTest3.c -g dominion.c rngs.c $(CFLAGS)
	cardTest3 >> unittestresults.out
	gcov cardTest3 >> unittestresults.out

	echo "cardTest4.c:" >> unittestresults.out
	gcc -o cardTest4 cardTest4.c -g dominion.c rngs.c $(CFLAGS)
	cardTest4 >> unittestresults.out
	gcov cardTest4 >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f cardTest1 cardTest2 cardTest3 cardTest4 unitTest1 unitTest2 unitTest3 unitTest4 unittestrestuls.out
