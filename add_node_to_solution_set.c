#include "dijkstra.h"

int add_node_to_solution_set(listp *n, sets *s)
{
	if (! s->solution_set ){
		s->solution_set = n;
		return 1;
	}
	while( (s->solution_set)->next ){
		s->solution_set = (s->solution_set)->next;
	}
	n->next = NULL;
	n->prev = s->solution_set;
	(s->solution_set)->next = n;
	return 1;
}
