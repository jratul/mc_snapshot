#ifndef THREAD
#define THREAD
#include <time.h>
#include <stdlib.h>
#include "snapshot.h"

extern bool finish;

struct threadParam {
	int threadId;
	Snapshot* snapshot;
	unsigned long long* updateNum;
};

void* threadFunc(void* arg);

#endif