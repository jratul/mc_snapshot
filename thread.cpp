#include "headers/thread.h"

void* threadFunc(void* arg) {
	threadParam * tp = (threadParam*) arg;
	int threadId = tp->threadId;
	Snapshot* snapshot = tp->snapshot;
	unsigned long long* updateNum = tp->updateNum;
	//int updateNum = 0;
	int randomValue;

	while(!finish) {
		randomValue = rand()%100;
		snapshot->update(randomValue, threadId);
		updateNum[threadId]++;
	}
}