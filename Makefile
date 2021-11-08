main: main.cpp Makefile
	g++ -std=c++17 -O3 -I${TBB_INSTALL_DIR}/include -L${TBB_INSTALL_DIR}/lib -ltbb -o main main.cpp
