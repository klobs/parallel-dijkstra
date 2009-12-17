#include "dijkstra.h"

unsigned int init_matrix(unsigned char *mpointer)
{
	unsigned int j=0, i=0;

	if(! mpointer) return -1;

	for(i=0;i<NODES;i++) {
		for(j=0; j<NODES; j++) {
			unsigned char r = (unsigned char) random() % MAX_WEIGHT;
			*(mpointer + NODES * i + j) = r;
			*(mpointer + NODES * j + i) = r;
		}
	}

	for(i=0; i<NODES; i++) {
		*(mpointer + NODES * i + i) = 0;
	}	

	return 0;
}
