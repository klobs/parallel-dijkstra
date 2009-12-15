#include "dijkstra.h"

int get_shortest_paths(unsigned int node, unsigned int *mpointer)
{
	listp 	*t;
	sets 	s = { 
		.visited = {0}, 
		.active_set = NULL
	};
	s.adjmatrix = mpointer;
	s.solution_set = malloc(sizeof(listp));

	
	if(!s.solution_set){
		printf("Error: Could not reserve memory for solution set\n");
		return -1;
	}
	
	if(node >= NODES) {
		printf("Error: There are only %d nodes. Can not calculate paths for node %d\n", NODES, node);
		return -1;
	}

	(s.solution_set)->node_id = node;
	(s.solution_set)->distance_from_root_node = 0;
	(s.solution_set)->prev_node_id = node;
	(s.visited[node]) = 1;

	s.active_set = add_node_neighbours_to_active_set( node, &s);
	
	while( s.active_set ){
		t = get_first_minimum_out_of_active_set(&s);

		if (!s.visited[t->node_id]){
			s.visited[t->node_id] = 1;	
			add_node_to_solution_set(t,&s);
			// TODO for new nodes form active sets: add node to neighbours:w
		}
		else{
			free(t);
		}
	}
	
	printf("Paths for node %d\n", node);
	while( s.solution_set && s.solution_set->next){
		printf("\tNode %d via node %d, distance %d\n", 
				s.solution_set->node_id, 
				s.solution_set->prev_node_id, 
				s.solution_set->distance_from_root_node);
		t = s.solution_set;
		s.solution_set = s.solution_set->next;
		free(t);	
	}

	return 0;
}

