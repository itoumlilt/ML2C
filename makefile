# ML2C
#
# @author Ilyas Toumlilt <toumlilt.ilyas@gmail.com>
#
# @version 1.0
# @package toumlilt/M1/AR

CC=gcc
BIN=bin
INC=include
LIB=lib
OBJ=obj
SRC=src


all: directories runtime


directories: ${OBJ} ${BIN} ${LIB}

${OBJ}:
	mkdir ${OBJ}
${BIN}:
	mkdir ${BIN}
${LIB}:
	mkdir ${LIB}


# regles generales :
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c -o $@ $< -I$(INC)

$(BIN)/% : $(OBJ)/%.o
	$(CC) -o $@ $<
#fin regles generales

runtime: $(OBJ)/runtime.o



clean:
	rm -f ${OBJ}/* ${BIN}/* ${LIB}/*

cleanall:
	rm -rf ${OBJ} ${BIN} ${LIB}
	rm -f ${INC}/*~ ${SRC}/*~ *~

# auto-generated makefile by toumlilt-makegen