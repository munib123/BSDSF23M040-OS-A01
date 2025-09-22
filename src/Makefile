CC = gcc
CFLAGS = -Wall -I../include
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib
LIB = $(LIBDIR)/libmyutils.a
DYNLIB = $(LIBDIR)/libmyutils.so
DYNFLAGS = -fPIC
LIBOBJS = mystrfunctions.o myfilefunctions.o
MAINOBJ = main.o
TARGET = $(BINDIR)/client_static

all: $(TARGET) $(BINDIR)/client_dynamic

$(LIB): $(LIBOBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $@ $(LIBOBJS)
	ranlib $@

$(DYNLIB): $(LIBOBJS)
	$(CC) -shared $(LIBOBJS) -o $@

$(TARGET): $(MAINOBJ) $(LIB)
	$(CC) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

$(BINDIR)/client_dynamic: $(MAINOBJ) $(DYNLIB)
	$(CC) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DYNFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(BINDIR)/client_dynamic $(LIB) $(DYNLIB)