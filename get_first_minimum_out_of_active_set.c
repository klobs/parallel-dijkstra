#include "dijkstra.h"

listp *get_first_minimum_out_of_active_set(sets *s)
{
	listp *t = NULL;
	if( s->active_set ){
		t = s->active_set;
		s->active_set = (s->active_set)->next;
	}	
	return t;
}
