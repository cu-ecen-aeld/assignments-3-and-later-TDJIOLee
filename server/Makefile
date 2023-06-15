CC = gcc

SRC := aesdsocket.c \
       client.c

TARGET = $(basename $(SRC))
OBJS = $(addsuffix .o, $(basename $(SRC)))

INCLUDES= -I./
CFLAGS = -g -Wall -Werror

.PHONY: all
all: $(TARGET) $(OBJS)

$(TARGET) : $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(addsuffix .o, $@) -o $@

.c.o:
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)

.DEFAULT_GOAL := all
