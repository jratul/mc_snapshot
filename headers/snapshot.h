#ifndef SNAPSHOT
#define SNAPSHOT

#include "snap.h"

class Snapshot {
	Snap* aTable;
	int capacity;

	Snapshot(int capacity, int init);
	snap* collect();
	void update(int value, int threadId);
	int* scan();
}

#endif