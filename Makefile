GCC=gcc
CFLAGS= -g -Wall

all: dijkstra

me_happy: clean all

dijkstra.o:
	$(GCC) $(CFLAGS) -c dijkstra.c

add_node_neighbours_to_active_set.o:
	$(GCC) $(CFLAGS) -c add_node_neighbours_to_active_set.c

add_node_to_solution_set.o:
	$(GCC) $(CFLAGS) -c add_node_to_solution_set.c

get_first_minimum_out_of_active_set.o:
	$(GCC) $(CFLAGS) -c get_first_minimum_out_of_active_set.c
  

get_shortest_paths.o:  
	$(GCC) $(CFLAGS) -c get_shortest_paths.c

get_distance_from_root_node.o:
	$(GCC) $(CFLAGS) -c get_distance_from_root_node.c


init_matrix.o:
	$(GCC) $(CFLAGS) -c init_matrix.c


dijkstra: add_node_neighbours_to_active_set.o add_node_to_solution_set.o dijkstra.o  get_distance_from_root_node.o get_first_minimum_out_of_active_set.o  get_shortest_paths.o  init_matrix.o 
	$(GCC) $(CFLAGS) -o dijkstra add_node_neighbours_to_active_set.o add_node_to_solution_set.o get_distance_from_root_node.o get_first_minimum_out_of_active_set.o  get_shortest_paths.o  init_matrix.o dijkstra.o
	
clean:
	rm *.o dijkstra
