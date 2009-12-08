#include "dijkstra.h"

listp *add_neighbours_to_active_set(int node, unsigned int *visited, 
		unsigned int *mpointer, listp *active_set) { 

	int i; 
	listp *tmplpointer1, *tmplpointer2;
	
	// Es gibt keine Adjazenzmatrix
	if (!mpointer) {
		printf("Error: no pointer to a valid matrix\n");
		return 0;
	}
	
		// Gehe die zu node gehoerende Zeile der Matrix durch, um die 
		// Nachbarn zu finden.
		for(i=0; i< NODES; i++) {

			// Falls eine Verbindung zu anderen Knoten existiert 
			// (in der Zeile durch einen Wert > 0 gekennzeichnet)
			// und der Knoten nich schon besucht ist, 
			// füge die Verbindung zum Active Set hinzu.
			if ((*(mpointer + 1) > 0) && ( *(visited + i) < 1)) {

				tmplpointer1 = malloc( sizeof(listp) );
				if (!tmplpointer1) {
					printf("Error: could not reserve memory for the list\n");
					return 0;
				}

//				tmplpointer1->distance_from_root_node	= *(mpointer + i);
				tmplpointer1->weight					= *(mpointer + i);
				tmplpointer1->node_id					= i;
				tmplpointer1->prev_node_id				= node;
				tmplpointer1->next						= NULL;
				
				if(! active_set){
					active_set = tmplpointer1;
				}
				else {
					tmplpointer2 = active_set;
					// An das Ende hangeln
					while (tmplpointer2->next){
						tmplpointer2 = tmplpointer2->next;
					}
					tmplpointer2->next = tmplpointer1;
				}
			}
			return active_set;
		}
	return 0;
}

