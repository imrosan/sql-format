demo: demo.o
		g++ demo.o -o demo

demo.o: demo.cpp
		g++ -c demo.cpp -o demo.o --std=c++0x -I./

clean:
		@rm -rf demo demo.o
