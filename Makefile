matmul: main.o main.s
	g++ -march=native -o matmul main.o

main.o:
	g++ -march=native -O3 -c main.cpp -o main.o

main.s:
	g++ -march=native main.cpp -O3 -S

.PHONY: clean

clean:
	rm -f matmul main.o main.s