TF_LUNA_TARGET = linux

all: osal.o i2c_tf_luna.o
	$(CXX) examples/read_distance.cpp -Iinclude -Iosal -o read_distance osal.o i2c_tf_luna.o -li2c

i2c_tf_luna.o: 
	$(CXX) src/i2c_tf_luna.cpp -Iosal -Iinclude -o i2c_tf_luna.o -c

osal.o:
	$(CXX) osal/$(TF_LUNA_TARGET)/i2c_osal.cpp -Iosal -o osal.o -c 

clean:
	rm -rf *.o *~ read_distance