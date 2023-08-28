# CSE30 Makefile
# 
# EXE - objects we want to build
# OBJS - ojects we want to compile (from c)
# 
# We provide a phony target clean to rm all the .o files
# 
# Run make to run with warnings
# Run make WARN= to run without warnings
# Run make DEBUG= to run without debug
# Run make DEBUG= WARN= to run without debug and warnings
# Run make clean to clean objects

EXE = tree_lookup 
all: $(EXE)
HEAD = node.h
OBJS = tree_lookup.o node_lookup.o insert_node.o load_table.o  print_info.o \
       delete_table.o hash.o
ASM = hash.S
CC = gcc
DEBUG = -g
WARN = -Wall -Wextra -Werror -Wformat-security
CFLAGS = -I. -std=gnu11 $(DEBUG) $(WARN) -O0
LIBS = 

.PHONY: clean

%.o : %.c $(HEAD)
	$(CC) $(CFLAGS) $< -c

$(EXE):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(ASM) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
