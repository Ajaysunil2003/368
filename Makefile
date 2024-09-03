CC = gcc
CFLAGS = -Wall -g

TARGET = coins

all: $(TARGET)

$(TARGET): coins.c
	$(CC) $(CFLAGS) -o $(TARGET) coins.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
