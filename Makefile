CC_exec=g++ 
CC_FLAGS=--std=c++11 -g

BUILD_DIR=./build
DEV_DIR=./src

CC=${CC_exec} ${CC_FLAGS}

all: utunes.out

utunes.out: ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/filter.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/main.o ${BUILD_DIR}/song.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/user.o
	${CC} ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/filter.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/main.o ${BUILD_DIR}/user.o ${BUILD_DIR}/song.o ${CC_FLAGS} -o utunes.out

${BUILD_DIR}/utunes.o: ${DEV_DIR}/utunes/utunes.cpp ${DEV_DIR}/exceptions/exceptions.h ${DEV_DIR}/filter/filter.h ${DEV_DIR}/song/song.h ${DEV_DIR}/user/user.h ${DEV_DIR}/playlist/playlist.h
	${CC} -c ${DEV_DIR}/utunes/utunes.cpp -o ${BUILD_DIR}/utunes.o

${BUILD_DIR}/exceptions.o: ${DEV_DIR}/exceptions/exceptions.cpp
	${CC} -c ${DEV_DIR}/exceptions/exceptions.cpp -o ${BUILD_DIR}/exceptions.o

${BUILD_DIR}/main.o: ${DEV_DIR}/main.cpp ${DEV_DIR}/utunes/utunes.h ${DEV_DIR}/exceptions/exceptions.h
	${CC} -c ${DEV_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/song.o: ${DEV_DIR}/song/song.cpp
	${CC} -c ${DEV_DIR}/song/song.cpp -o ${BUILD_DIR}/song.o

${BUILD_DIR}/user.o: ${DEV_DIR}/user/user.cpp ${DEV_DIR}/playlist/playlist.h ${DEV_DIR}/exceptions/exceptions.h
	${CC} -c ${DEV_DIR}/user/user.cpp -o ${BUILD_DIR}/user.o

${BUILD_DIR}/playlist.o: ${DEV_DIR}/playlist/playlist.cpp ${DEV_DIR}/song/song.h ${DEV_DIR}/exceptions/exceptions.h
	${CC} -c ${DEV_DIR}/playlist/playlist.cpp -o ${BUILD_DIR}/playlist.o

${BUILD_DIR}/filter.o: ${DEV_DIR}/filter/filter.cpp ${DEV_DIR}/song/song.h ${DEV_DIR}/exceptions/exceptions.h
	${CC} -c ${DEV_DIR}/filter/filter.cpp -o ${BUILD_DIR}/filter.o


clean:
	rm -rf build/ && mkdir -p build
