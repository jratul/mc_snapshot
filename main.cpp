#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "headers/thread.h"
using namespace std;

bool finish;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("command : ./run n\n");
		exit(1);
	}

	finish = false;
	int threadNum = atoi(argv[1]);

	srand((unsigned)time(NULL));

	int* updateNum = new int[threadNum];
	int totUpdateNum = 0;

	Snapshot* snapshot = new Snapshot(threadNum, 0);

	pthread_t * threads;
	threads = new pthread_t[threadNum];
	threadParam* tp = new threadParam[threadNum];

	for(int i=0;i<threadNum;i++) {
		tp[i].threadId = i;
		tp[i].snapshot = snapshot;
		tp[i].updateNum = updateNum;

		if(pthread_create(&threads[i], 0, threadFunc, (void*) &tp[i]) < 0) {
			printf("pthread_create error!\n");
			return 0;
		}	
	}

	usleep(60000);
	finish = true;

	for(int i=0;i<threadNum;i++) {
		pthread_join(threads[i], NULL);
	}

	for(int i=0;i<threadNum;i++) {
		totUpdateNum += updateNum[i];
	}

	cout << "update : " << totUpdateNum << endl;

	delete [] tp;
	delete [] threads;
	delete [] updateNum;

	return 0;
}