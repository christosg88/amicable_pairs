main: main.cpp Makefile
	g++ -Wall -Werror -Wextra -Wpedantic -std=c++17 -O3 -I${TBB_INSTALL_DIR}/include -Wl,-rpath=${TBB_INSTALL_DIR}/lib -L${TBB_INSTALL_DIR}/lib -ltbb -o main main.cpp
