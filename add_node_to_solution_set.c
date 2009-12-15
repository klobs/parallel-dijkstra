#include "dijkstra.h"

int add_node_to_solution_set(listp *n, sets *s)
{
	listp *t = s->solution_set;
	if (! t){
		s->solution_set = n;
		return 1;
	}
	while( t->next ){
		t = t->next;
	}
	n->next = NULL;
	n->prev = t;
	t->next = n;
	return 1;
}
