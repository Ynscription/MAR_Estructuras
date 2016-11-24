CC        := g++
LD        := g++

TARGET    := run.x
SRC       := $(wildcard src/*.cpp)
INCLUDES  := -I src/headers

.PHONY: all clean

all:
	$(CC) $(INCLUDES) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -rf $(TARGET)
	rm -rf src/*.o
