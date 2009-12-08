#include "dijkstra.h"

int get_shortest_paths(int node, int *mpointer)
{
	listp *solution_set = NULL;
	listp *active_set = NULL;
	unsigned int visited[NODES] = { 0 };

	if(node >= NODES) {
		printf("Error: There are only %d nodes. Can not calculate paths for node %d\n", NODES, node);
		return -1;
	}

	active_set = add_neighbours_to_active_set( node, visited, mpointer, NULL );

	return 0;
}

