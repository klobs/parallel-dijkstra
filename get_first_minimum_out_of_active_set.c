#include "dijkstra.h"

listp *get_first_minimum_out_of_active_set(sets *s)
{
	listp *t, *w = s->active_set;
	t=w;
	while( w ){
		if( w->distance_from_root_node < t->distance_from_root_node ) t=w;
		w = w->next;
	}	
	if(t->prev) {
		t->prev->next = t->next;
	}
	if(t->next) {
		t->next->prev = t->prev;
	}
	if(t == s->active_set) s->active_set = t->next;
	t->prev = NULL;
	t->next = NULL;
	return t;
}
