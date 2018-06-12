CC = c++
CFLAGS = -std=c++14

build: main.o interface.o producer.o product_chemicals.o product_food.o
	$(CC) $(CFLAGS) main.o interface.o producer.o product_chemicals.o product_food.o -o shop -L ./lib
	./shop

main.o: main.cpp
	$(CC) $(CFLAGS) -I ./lib -c main.cpp

interface.o: interface.cpp
	$(CC) $(CFLAGS) -I ./lib -c interface.cpp

producer.o: producer.cpp
	$(CC) $(CFLAGS) -I ./lib -c producer.cpp

product_chemicals.o: product_chemicals.cpp
	$(CC) $(CFLAGS) -I ./lib -c product_chemicals.cpp

product_food.o: product_food.cpp
	$(CC) $(CFLAGS) -I ./lib -c product_food.cpp

clean:
	rm -f *.o
	rm shop.exe
