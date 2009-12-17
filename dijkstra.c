#include "dijkstra.h"

int main( void )
{

	unsigned int j=0, i=0;
	unsigned char matrix[NODES][NODES];
	sets *w = NULL;

	if(! init_matrix((unsigned char*) matrix)) {
		printf("   |");
		for(j=0; j<NODES; j++) {
			printf("%02d ", j);
		}
		printf("\n---");
		for(j=0; j<NODES; j++) {
			printf("---");
		}
		puts("");

		for(i=0;i<NODES;i++) {
			printf("%02d |",i);
			for(j=0; j<NODES; j++) {
				printf("%2d ",matrix[i][j]);
			}
			printf("\n");
		}	

		for(i=0; i<NODES; i++){
			w = get_shortest_paths( i, (unsigned char*) matrix);
			print_solution_set( i, w );
			free_solution_set( w );	
		}
	}
	else return 0;

	return 1;
}

