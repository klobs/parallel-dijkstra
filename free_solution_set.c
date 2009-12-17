#include "dijkstra.h"

void free_solution_set(sets *s)
{
	listp *p = s->solution_set;
	
	while(p){
		s->solution_set = s->solution_set->next;
		free(p);
		p = s->solution_set;	
	}	
}
