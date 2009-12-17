#include "dijkstra.h"

sets *get_shortest_paths(unsigned int node, unsigned char *mpointer)
{
	listp 	*t;
	sets	*w;
	sets 	s = { 
		.visited = {0}, 
		.active_set = NULL
	};
	s.adjmatrix = mpointer;
	s.solution_set = malloc(sizeof(listp));

	
	if(!s.solution_set){
		printf("Error: Could not reserve memory for solution set\n");
		return NULL;
	}
	
	if(node >= NODES) {
		printf("Error: There are only %d nodes. Can not calculate paths for node %d\n", NODES, node);
		return NULL;
	}

	(s.solution_set)->next = NULL;
	(s.solution_set)->prev = NULL;
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
			s.active_set = add_node_neighbours_to_active_set( t->node_id, &s);
		}
		else{
			free(t);
		}
	}

//	printf("Paths for node %d\n", node);
//	while( s.solution_set ){
//		printf("\tNode %2d via node %2d, distance %2d\n", 
//				s.solution_set->node_id, 
//				s.solution_set->prev_node_id, 
//				s.solution_set->distance_from_root_node);
//		t = s.solution_set;
//		s.solution_set = s.solution_set->next;
//		free(t);	
//	}
	
//<<<<<<< HEAD:get_shortest_paths.c
//	FILE *fp = fopen("path", "a");
//	printf("Paths for node %d\n", node);
//	fprintf(fp, "Paths for node %d\n", node);
//	while( s.solution_set ){
//		fprintf(fp,"\tNode %3d via node %3d, distance %3d\n", 
//				s.solution_set->node_id, 
//				s.solution_set->prev_node_id, 
//				s.solution_set->distance_from_root_node);
//		printf("\tNode %3d via node %3d, distance %3d\n", 
//				s.solution_set->node_id, 
//				s.solution_set->prev_node_id, 
//				s.solution_set->distance_from_root_node);
//		t = s.solution_set;
//		s.solution_set = s.solution_set->next;
//		free(t);	
//	}
//	fclose(fp);
//	return 0;
//=======
	w = malloc(sizeof(sets));	
	memcpy(w, &s, sizeof(sets));
	
	return w;
}

