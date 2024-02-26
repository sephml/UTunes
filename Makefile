CC_exec=g++ 
CC_FLAGS=--std=c++11 -g

BUILD_DIR=./build
DEV_DIR=./src

CC=${CC_exec} ${CC_FLAGS}

all: utunes.out

utunes.out: ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/filter.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/main.o ${BUILD_DIR}/song.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/user.o
	${CC} ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/filter.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/main.o ${BUILD_DIR}/user.o ${BUILD_DIR}/song.o ${CC_FLAGS} -o utunes.out

${BUILD_DIR}/utunes.o: ./src/utunes/utunes.cpp ./src/exceptions/exceptions.h ./src/filter/filter.h ./src/song/song.h ./src/user/user.h ./src/playlist/playlist.h
	${CC} -c ./src/utunes/utunes.cpp -o ${BUILD_DIR}/utunes.o

${BUILD_DIR}/exceptions.o: ./src/exceptions/exceptions.cpp
	${CC} -c ./src/exceptions/exceptions.cpp -o ${BUILD_DIR}/exceptions.o

${BUILD_DIR}/main.o: ./src/main.cpp ./src/utunes/utunes.h ./src/exceptions/exceptions.h
	${CC} -c ./src/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/song.o: ./src/song/song.cpp
	${CC} -c ./src/song/song.cpp -o ${BUILD_DIR}/song.o

${BUILD_DIR}/user.o: ./src/user/user.cpp ./src/playlist/playlist.h ./src/exceptions/exceptions.h
	${CC} -c ./src/user/user.cpp -o ${BUILD_DIR}/user.o

${BUILD_DIR}/playlist.o: ./src/playlist/playlist.cpp ./src/song/song.h ./src/exceptions/exceptions.h
	${CC} -c ./src/playlist/playlist.cpp -o ${BUILD_DIR}/playlist.o

${BUILD_DIR}/filter.o: ./src/filter/filter.cpp ./src/song/song.h ./src/exceptions/exceptions.h
	${CC} -c ./src/filter/filter.cpp -o ${BUILD_DIR}/filter.o


clean:
	rm -rf build/ && mkdir -p build
