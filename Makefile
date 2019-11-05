CC=g++
CFLAGS=-O2 -pedantic -Wall
INCLUDEDIR=.

TARGET=$(MAKECMDGOALS)
INCLUDEDIR += -I./$(TARGET)

color-%:  color.o main.o image.o
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) $^ -o $@.bin
	rm color.o

color.o: $(TARGET)/color.cpp
	@echo "Compiling $(TARGET)..."
	$(CC) $(CFLAGS) -c $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $^

clean:
	rm *.bin *.o
