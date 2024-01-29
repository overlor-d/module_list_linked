-include Makefile.rules

SRC_DIR = src

SRCS = $(SRC_DIR)/list_linked.c $(SRC_DIR)/stack_linked.c $(SRC_DIR)/queue_linked.c
OBJS = $(SRCS:.c=.o)
NAME = jean.lepeltier
LIB_STATIC = libmylpf.a

LIB_SHARED = libmylpf.so

ARCHIVE_NAME = $(NAME)-MiniProjet1.tar.gz2

FILES = AUTHORS README Makefile configure src/list_linked.c src/list_linked.h src/queue_linked.c src/queue_linked.h src/stack_linked.c src/stack_linked.h

# notre prof pourrait avoir la méchante idée d'ajouter un fichier avec le même nom qu'une des fonctions du makefile eh eh
.PHONY: all clean dist distclean check libmylpf shared static

all: libmylpf

libmylpf: shared static

static: $(OBJS)
	@$(AR) rcs $(LIB_STATIC) $(OBJS)

shared: $(OBJS)
	@$(CC) -shared -o $(LIB_SHARED) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	@rm -f $(SRC_DIR)/*.o $(LIB_STATIC) $(LIB_SHARED)

dist: all
	@tar -czvf $(ARCHIVE_NAME) $(FILES)

distclean: clean
	@rm -f $(ARCHIVE_NAME)

compil_all: all
	cp libmylpf.a ./check/
	cd check && ./check.sh

check: compil_all
	./check/test

list: compil_all
	./check/test-list_linked

queue: compil_all
	./check/test-queue_linked

stack: compil_all
	./check/test-stack_linked