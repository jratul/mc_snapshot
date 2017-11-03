run : main.o snap.o snapshot.o thread.o
	g++ -o run main.o snap.o snapshot.o thread.o -g -lpthread

main.o : headers/thread.h main.cpp
	g++ -c main.cpp

snap.cpp : headers/snap.h snap.cpp
	g++ -c snap.cpp

snapshot.cpp : headers/snapshot.h headers/snap.h snapshot.cpp
	g++ -c snapshot.cpp

thread.cpp : headers/thread.h thread.cpp
	g++ -c thread.cpp

clean :
	-rm -rf *.o run