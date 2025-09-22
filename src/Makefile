CC = gcc
CFLAGS = -Wall -I../include
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib
LIB = $(LIBDIR)/libmyutils.a
LIBOBJS = mystrfunctions.o myfilefunctions.o
MAINOBJ = main.o
TARGET = $(BINDIR)/client_static

all: $(TARGET)

$(LIB): $(LIBOBJS)
	@mkdir -p $(LIBDIR)  # Ensure lib directory exists
	ar rcs $@ $(LIBOBJS)
	ranlib $@

$(TARGET): $(MAINOBJ) $(LIB)
	$(CC) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@  # Output .o to obj/ directory

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(LIB)