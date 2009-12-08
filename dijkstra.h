#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>

#define NODES		50
#define MAX_WEIGHT 	20

typedef struct listp_s listp;

struct listp_s 
{
	listp 			*next;

	unsigned int	distance_from_root_node;
	unsigned int	weight;
	unsigned int 	node_id;
	unsigned int	prev_node_id;
};

#endif
