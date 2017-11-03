#include "headers/thread.h"

void* threadFunc(void* arg) {
	int threadId = arg->threadId;
	Snapshot* snapshot = arg->snapshot;
	int* updateNum = arg->updateNum;
	int updateNum = 0;
	int randomValue;

	while(true) {
		randomValue = rand()%100;
		snapshot->update(randomValue, threadId);
		updateNum[threadId]++;
	}
}