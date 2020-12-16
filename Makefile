CC_exec=g++ 
CC_FLAGS=--std=c++11 -g

BUILD_DIR=./build


CC=${CC_exec} ${CC_FLAGS}

all: utunes.out

utunes.out: ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/main.o ${BUILD_DIR}/song.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/user.o
	${CC} ${BUILD_DIR}/exceptions.o ${BUILD_DIR}/playlist.o ${BUILD_DIR}/utunes.o ${BUILD_DIR}/main.o ${BUILD_DIR}/user.o ${BUILD_DIR}/song.o ${CC_FLAGS} -o utunes.out

${BUILD_DIR}/utunes.o: utunes.cpp exceptions.h song.h user.h playlist.h
	${CC} -c utunes.cpp -o ${BUILD_DIR}/utunes.o

${BUILD_DIR}/exceptions.o: exceptions.cpp
	${CC} -c exceptions.cpp -o ${BUILD_DIR}/exceptions.o

${BUILD_DIR}/main.o: main.cpp utunes.h exceptions.h
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/song.o: song.cpp
	${CC} -c song.cpp -o ${BUILD_DIR}/song.o

${BUILD_DIR}/user.o: user.cpp playlist.h exceptions.h
	${CC} -c user.cpp -o ${BUILD_DIR}/user.o

${BUILD_DIR}/playlist.o: playlist.cpp song.h exceptions.h
	${CC} -c playlist.cpp -o ${BUILD_DIR}/playlist.o

clean:
	rm -rf build/ && mkdir -p build
