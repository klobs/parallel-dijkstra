#include "dijkstra.h"

void print_solution_set(int node, sets *s)
{
	listp *w = s->solution_set;	
	listp *d = w;
	// Dirty hack
	char file_name[20] = {0};
	FILE *fh;

	snprintf(file_name, 20,"%02d.path", node);

	fh = fopen(file_name, "a");
	if (fh){

		fprintf(fh,"Paths for node %d\n", node);
		while( d ){
			fprintf(fh,"\tNode %2d via node %2d, distance %2d\n", 
					d->node_id, 
					d->prev_node_id, 
					d->distance_from_root_node);
			d = d->next;
		}

	}	

//	printf("Paths for node %d\n", node);
//	while( w ){
//		printf("\tNode %2d via node %2d, distance %2d\n", 
//				w->node_id, 
//				w->prev_node_id, 
//				w->distance_from_root_node);
//		w = w->next;
//	}
}
