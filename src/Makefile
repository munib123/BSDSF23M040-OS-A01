CC = gcc
CFLAGS = -Wall -I../include
OBJDIR = ../obj
BINDIR = ../bin
SOURCES = mystrfunctions.c myfilefunctions.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = $(BINDIR)/client

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)