#ifndef THREAD
#define THREAD
#include <time.h>
#include "snapshot.h"

struct threadParam {
	int threadId;
	Snapshot* snapshot;
	int* updateNum;
};

void* threadFunc(void* arg);

#endif