CC = c++
CFLAGS = -std=c++14

build: shop.o interface.o producer.o
	$(CC) $(CFLAGS) shop.o interface.o producer.o -o shop -L ./lib
	./shop

shop.o: shop.cpp
	$(CC) $(CFLAGS) -I ./lib -c shop.cpp

interface.o: interface.cpp
	$(CC) $(CFLAGS) -I ./lib -c interface.cpp

producer.o: producer.cpp
	$(CC) $(CFLAGS) -I ./lib -c producer.cpp

clean:
	rm -f *.o
