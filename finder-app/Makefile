CC = gcc

SRC := writer.c
TARGET = $(basename $(SRC))
OBJS = $(addsuffix .o, $(basename $(SRC)))

INCLUDES= -I./
CFLAGS = -g -Wall

.PHONY: all
all: $(TARGET) $(OBJS)

$(TARGET) : $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $(SRC)

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
