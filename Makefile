all:
	$(CXX) examples/read_distance.cpp -li2c -o read_distance

clean:
	rm -rf *.o *~ read_distance