GCC=gcc
CFLAGS= -O2

all: dijkstra

dijkstra.o:
	$(GCC) -c dijkstra.c

add_node_neighbours_to_active_set.o:
	$(GCC) -c add_node_neighbours_to_active_set.c

get_first_minimum_out_of_active_set.o:
	$(GCC) -c get_first_minimum_out_of_active_set.c
  

get_shortests_paths.o:  
	$(GCC) -c get_shortests_paths.c


init_matrix.o:
	$(GCC) -c init_matrix.c


dijkstra: add_node_neighbours_to_active_set.o  dijkstra.o  get_first_minimum_out_of_active_set.o  get_shortests_paths.o  init_matrix.o
	$(GCC) $(CFLAGS) -o dijkstra add_node_neighbours_to_active_set.o  dijkstra.o  get_first_minimum_out_of_active_set.o  get_shortests_paths.o  init_matrix.o 
	
clean:
	rm *.o dijkstra
