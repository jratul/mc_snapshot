#ifndef SNAPSHOT
#define SNAPSHOT

#include "snap.h"

class Snapshot {
public:
	Snap* aTable;
	int capacity;

	Snapshot(int capacity, int init);
	Snap* collect();
	void update(int value, int threadId);
	int* scan();
};

#endif