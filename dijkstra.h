#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NODES		99
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
	unsigned int 	visited[NODES];
	unsigned char   *adjmatrix;
	listp 			*solution_set;
	listp 			*active_set;
	time_t			duration_start;	
	time_t			duration_stop;	
};

listp*			add_node_neighbours_to_active_set(unsigned int, sets*);
int				add_node_to_solution_set(listp*, sets*);
void 			free_solution_set(sets*);
unsigned int 	get_distance_from_root_node(unsigned int, sets*);
listp*			get_first_minimum_out_of_active_set(sets*);
sets* 			get_shortest_paths(unsigned int, unsigned char*);
unsigned int 	init_matrix(unsigned char *);
void		 	print_solution_set(int,sets*); 

#endif
