#include "dijkstra.h"

int main( void )

{

	unsigned int j=0, i=0;
	unsigned int matrix[NODES][NODES];

	if(! init_matrix((unsigned int*) matrix)) {
		for(i=0;i<NODES;i++) {
			for(j=0; j<NODES; j++) {
				printf("%2d ",matrix[i][j]);
			}
			printf("\n");
		}	
		for(i=0; i<NODES; i++){
			get_shortest_paths( i, (unsigned int*) matrix);
		}
	}
	else return 0;

	return 1;
}

