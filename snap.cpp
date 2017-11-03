#include "headers/snap.h"

Snap::Snap(int value) {
	this->stamp = 0;
	this->value = value;
	this->snap = NULL;
}

Snap::Snap(long stamp, int value, int* snap) {
	this->stamp = stamp;
	this->value = value;
	this->snap = snap;
}