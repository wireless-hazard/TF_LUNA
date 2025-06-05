TF_LUNA_TARGET = linux

all: pal.o i2c_tf_luna.o
	$(CXX) examples/read_distance.cpp -Iinclude -IEmbedded_PAL -o read_distance pal.o i2c_tf_luna.o -li2c

i2c_tf_luna.o: 
	$(CXX) src/i2c_tf_luna.cpp -IEmbedded_PAL -Iinclude -o i2c_tf_luna.o -c

pal.o:
	$(CXX) Embedded_PAL/$(TF_LUNA_TARGET)/i2c_pal.cpp -IEmbedded_PAL -o pal.o -c

clean:
	rm -rf *.o *~ read_distance