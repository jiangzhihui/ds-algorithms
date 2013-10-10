dijkstra:
	g++ -Wall -g dijkstra.cc 
	./a.out < graph 
ufset:compile-ufset
	./ufset 
compile-ufset:
	g++ -Wall UFSet.cc -o ufset 
heap:compile-heap
	./heap 
	diff out1 out2
compile-heap:
	g++ -Wall heap.cc -o heap
