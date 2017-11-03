#include "headers/snapshot.h"
#include <cstddef>

Snapshot::Snapshot(int capacity, int init) {
	aTable = new Snap[capacity];
	this->capacity = capacity;
	for(int i=0;i<capacity; i++) {
		aTable[i].setSnap(0, init, NULL);
	}
}

Snap* Snapshot::collect() {
	snap* copy = new snap[capacity];
	for(int i=0;i<capacity;i++) {
		copy[i] = aTable[i];
	}

	return copy;
}

void Snapshot::update(int value, int threadId) {
	int* snapArray = scan();
	Snap oldValue = aTable[threadId];
	Snap newValue = new Snap(oldValue.stamp+1, value, snapArray);
	aTable[threadId] = newValue;
}

int* Snapshot::scan() {
	Snap* oldCopy;
	Snap* newCopy;
	bool* moved = new bool[capacity];
	oldCopy = collect();

	collect: while(true) {
		newCopy = collect();
		for(int i=0;i<capacity;i++) {
			if(oldCopy[i].stamp != newCopy[i].stamp) {
				if(moved[i]) {
					return oldCopy[i].snap;
				} else {
					moved[i] = true;
					oldCopy = newCopy;
					continue collect;
				}
			}
		}

		int* result = new int[capacity];
		for(int i=0;i<capacity;i++) {
			result[i] = newCopy[i].value;
		}

		return result;
	}
}