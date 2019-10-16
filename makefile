install:
	sudo cp bin/x86-64-paping /usr/bin/paping

all:
	g++ -m64 ./src/print.cpp ./src/stats.cpp ./src/timer.cpp ./src/arguments.cpp ./src/i18n.cpp ./src/host.cpp ./src/socket.cpp ./src/main.cpp -o ./bin/x86-64-paping
	# g++ -m32 ./src/print.cpp ./src/stats.cpp ./src/timer.cpp ./src/arguments.cpp ./src/i18n.cpp ./src/host.cpp ./src/socket.cpp ./src/main.cpp -o ./bin/i386-paping
