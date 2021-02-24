OBJ := obj
BIN := bin
CFLAGS := -Wall

SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, $(OBJ)/%.o, $(SOURCES))
BINS := $(patsubst %.c, bin/%, $(SOURCES))
DIRS := obj bin

.PHONY: directories clean 

all: directories $(BINS)

$(BINS): $(OBJECTS)
	$(CC) $< -o $@

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

directories: $(DIRS)
$(DIRS):
	mkdir -p $@

clean:
	rm -rf $(DIRS)
