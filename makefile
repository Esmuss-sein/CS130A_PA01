prog1.out: prog1.cpp BST.cpp hash.cpp
	g++ -o prog1.out BST.cpp hash.cpp prog1.cpp
clean: 
	rm -f prog1.o BSTnp.o hash.o
