#include "dijkstra.h"

listp *add_node_neighbours_to_active_set(unsigned int node, sets *s)
{

	unsigned int i; 
	listp *tmp1;//, *tmp2;
	listp *as = s->active_set;
	
	/* Es gibt keine Adjazenzmatrix */
	if (!s->adjmatrix) {
		printf("Error: no pointer to a valid matrix\n");
		return 0;
	}
	
		// Gehe die zu node gehoerende Zeile der Matrix durch, um die 
		// Nachbarn zu finden.
		for(i=0; i< NODES; i++) {

			// Falls eine Verbindung zu anderen Knoten existiert 
			// (in der Zeile durch einen Wert > 0 gekennzeichnet)
			// und der Knoten nich schon besucht ist, 
			// füge die Verbindung geordnet zum Active Set hinzu.
			if ((*(s->adjmatrix + node * NODES + i) > 0) && (*(s->visited + i) < 1)) {

				tmp1 = malloc(sizeof(listp));
				if (!tmp1) {
					printf("Error: could not reserve memory for the list\n");
					return 0;
				}

				tmp1->distance_from_root_node	= (unsigned int) *(s->adjmatrix + node * NODES + i) +
					get_distance_from_root_node(node, s);
				tmp1->weight					= (unsigned int) *(s->adjmatrix + node * NODES + i);
				tmp1->node_id					= i;
				tmp1->next						= NULL;
				tmp1->prev						= NULL;

				if(! as ){
					s->active_set = tmp1;
					as = tmp1;
				}
				else {
					tmp1->next = as;
					as->prev   = tmp1;
					as = tmp1;	
				}
			}
		}
	return as;
}

