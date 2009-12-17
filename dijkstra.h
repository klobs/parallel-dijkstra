#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>

#define NODES		20
#define MAX_WEIGHT  99	

typedef struct listp_s listp;
typedef struct sets_s sets;

struct listp_s 
{
	listp 			*next;
	listp			*prev;

	unsigned int	distance_from_root_node;
	unsigned char	weight;
	unsigned int 	node_id;
	unsigned int	prev_node_id;
};

struct sets_s
{
	unsigned int visited[NODES];
	unsigned char   *adjmatrix;
	listp *solution_set;
	listp *active_set;
};

listp*			add_node_neighbours_to_active_set(unsigned int, sets*);
int				add_node_to_solution_set(listp*, sets*);
unsigned int 	get_distance_from_root_node(unsigned int, sets*);
listp*			get_first_minimum_out_of_active_set(sets*);
int 			get_shortest_paths(unsigned int, unsigned char*);
unsigned int 	init_matrix(unsigned char *);

#endif
