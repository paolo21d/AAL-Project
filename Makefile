#Makefile
main: objects.o
	g++ -o aalProject main.o BrutforceResolver.o Compare.o OptimalResolver.o Resolver.o
	@echo "Run ./aalProject"
objects.o:
	g++ -c main.cpp BrutforceResolver.cpp Compare.cpp OptimalResolver.cpp Resolver.cpp

clean:
	rm -f *.o out aalProject
