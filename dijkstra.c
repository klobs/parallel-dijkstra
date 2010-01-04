#include "dijkstra.h"

int main(int argc, char **argv)
{

	unsigned int j=0, i=0;
	unsigned char matrix[NODES][NODES];
	sets *w = NULL;
	FILE *fp;

#ifdef MPI
	int rank;	// own process rank
	int size;	// number of processes + 1

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if(! rank) j = init_matrix((unsigned char*) matrix);
#else
	j = init_matrix((unsigned char*) matrix);
#endif
	if(! j) {
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
		
		//file output
		fp = fopen("matrix.path", "a");
		if (fp){

			fprintf(fp,"   |");
			for(j=0; j<NODES; j++) {
				fprintf(fp,"%02d ", j);
			}
			fprintf(fp,"\n---");
			for(j=0; j<NODES; j++) {
				fprintf(fp,"---");
			}
			fprintf(fp,"\n");

			for(i=0;i<NODES;i++) {
				fprintf(fp,"%02d |",i);
				for(j=0; j<NODES; j++) {
					fprintf(fp,"%2d ",matrix[i][j]);
				}
				fprintf(fp,"\n");
			}	
		}		

#ifdef MPI
		MPI_Bcast(matrix, NODES*NODES, MPI_UNSIGNED_CHAR, 0, MPI_COMM_WORLD);
		j = NODES / size;

		for(i=rank*j; i< ((rank+1)*j-1); i++){
			w = get_shortest_paths( i, (unsigned char*) matrix);
			print_solution_set( i, w );
			printf("Duration for node %2d = %d s\n", i, w->duration_stop - w->duration_start);
			free_solution_set( w );	
		}
		
		j = (NODES - 1) % size;

		if((rank>0) && (rank <= j)){ // lasting nodes
			w = get_shortest_paths((NODES - 1 - rank), (unsigned char*) matrix);
			print_solution_set((NODES - 1 - rank), w );
			printf("Duration for node %2d = %d s\n", (NODES - 1 - rank), w->duration_stop - w->duration_start);
			free_solution_set( w );	
		}
#else
		for(i=0; i<NODES; i++){
			w = get_shortest_paths( i, (unsigned char*) matrix);
			print_solution_set( i, w );
			printf("Duration for node %2d = %d s\n", i, w->duration_stop - w->duration_start);
			free_solution_set( w );	
		}
#endif
	}
	else {
		puts("ERROR: Matrix could not be initialized");
		return 0;
	}

#ifdef MPI
	MPI_Finalize();
#endif
	return 1;
}

