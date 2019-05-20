CC=gcc
CFLAGS=-Wall -Werror
SEC_SOLVER=secSolver

secSolver: build/secSolver.o
	$(CC) -o $@ $^ $(CFLAGS)

build/secSolver.o: src/secSolver.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm build/*.o
	rm $(SEC_SOLVER)