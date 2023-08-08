SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)

CROSS_COMPILE ?= native

all: $(TARGET) 

$(TARGET): $(OBJS)
ifeq ($(CROSS_COMPILE), native)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)
endif

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	aarch64-none-linux-gnu-gcc -g -Wall -c -o $(OBJS) $(SRC)
	aarch64-none-linux-gnu-gcc -g -Wall $(OBJS) -o $(TARGET) $(LDFLAGS)
endif

native: $(OBJS)
ifeq ($(CROSS_COMPILE), native)
	gcc -g -Wall $(OBJS) -o $(TARGET) $(LDFLAGS)
endif

clean:
	-rm -f *.o $(TARGET)