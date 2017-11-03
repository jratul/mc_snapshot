#ifndef SNAP
#define SNAP

class Snap {
public:
	long stamp;
	int value;
	int* snap;

	Snap();
	Snap(int value);
	setSnap(long stamp, int value, int* snap);
};
#endif