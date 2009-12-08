#include "dijkstra.h"

unsigned int get_distance_from_root_node(unsigned int n, sets *s)
{
	listp *t;
	if (s->solution_set){
		t = s->solution_set;
		while(t && (t->node_id != n)){
			t = t->next;
		}
		if(t) return t->distance_from_root_node;	
	}
	printf("Error: no valid solution set. Can not calculate destination to root node\n");
	return 0;
}
