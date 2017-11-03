#include "headers/snapshot.h"

Snapshot::Snapshot(int capacity, int init) {
	aTable = new Snap[capacity];
	this->capacity = capacity;
	for(int i=0;i<capacity; i++) {
		aTable[i] = new Snap(init);
	}
}

snap* Snapshot::collect() {
	snap* copy = new snap[capacity];
	for(int i=0;i<capacity;i++) {
		copy[i] = aTable[i];
	}

	return copy;
}

void Snapshot::update(int value, int threadId) {
	int* snapArray = scan();
	snap oldValue = aTable[threadId];
	snap newValue = new snap(oldValue.stamp+1, value, snap);
	aTable[threadId] = newValue;
}

int* Snapshot::scan() {
	snap* oldCopy;
	snap* newCopy;
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