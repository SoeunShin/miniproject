.SUFFIXES:.c.o

CC = gcc
CFLAGS = -W -Wall
TARGET = product
DTARGET = product_debug
OBJECTS = main.c product.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

.c .o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o product product_debug
