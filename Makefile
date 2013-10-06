heap:compile-heap
	./heap 
	diff out1 out2
compile-heap:
	g++ -Wall heap.cc -o heap
