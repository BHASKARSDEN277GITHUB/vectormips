TARGET_ARCH = linux

CC     = g++
OPT    = -O3
DEBUG  = -g
OTHER  = 
CFLAGS = $(OPT) $(OTHER)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = output

## This is the line to put all the filenames (cpp) of your source code, separated by space.
SRCS = iFetch.h iFetch.cpp vReg.h vReg.cpp iDecode.h iDecode.cpp alu.h alu.cpp main.cpp  
##SRCS=iFetch.h iFetch.cpp

OBJS = $(SRCS:%.cpp=%.o)

## Variable that points to SystemC installation path
SYSTEMC = /usr/local/systemc-2.3.1

INCDIR = -I. -I$(SYSTEMC)/include
LIBDIR = -L. -L$(SYSTEMC)/lib-linux64

LIBS   =  -lsystemc -lm 


EXE    = $(MODULE)

.SUFFIXES: .cc .cpp .o .x

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt
.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean::
	rm -rf $(EXE) *.o core* *.d *.vcd *.dump

