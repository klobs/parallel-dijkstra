#include "dijkstra.h"

int add_node_to_solution_set(listp *n, sets *s)
{
	while( s->solution_set && (s->solution_set)->next){
		s->solution_set = (s->solution_set)->next;
	}
	n->next = NULL;
	(s->solution_set)->next = n;
	return 1;
}
