#include "dijkstra.h"

int get_shortest_paths(int node, int *mpointer)
{
	listp *solution_set = null;
	listp *active_set = null;
	unsigned int visited[NODES] = { 0 }

	if(node >= NODES) {
		printf("Error: There are only %d nodes. Can not calculate paths for node %d\n", NODES, node);
		return -1;
	}

	add_neighbours_to_active_set( node, visited, mpointer, NULL );

	return 0;
}

