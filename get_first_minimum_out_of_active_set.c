#include "dijkstra.h"

listp *get_first_minimum_out_of_active_set(listp *as)
{
	listp *tmplistp1, *tmplistp2;

	if(! as) {
		printf("Error: there is no more active Set");
		return NULL;
	}
	
	tmplistp1 = as;
	tmplistp2 = as;

	while( tmplistp2->next){
		if ( (tmplistp2->next)->distance_from_root_node < 
				tmplistp1->distance_from_root_node){
			tmplistp1 = tmplistp2;
		}
		
		tmplistp2 = tmplistp2->next;

	}	
	
	return tmplistp1;

}
