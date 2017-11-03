#ifndef SNAP
#define SNAP

class Snap {
	long stamp;
	int value;
	int* snap;

	Snap(int value);
	Snap(long stamp, int value, int* snap);
};
#endif