#pragma once

#include <iostream>

inline void clear_console() {
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) ||
		  defined (__gnu_linux__) ||
		  defined (__linux__) ||
		  defined (__APPLE__)
		system("clear");
	#endif
}

inline void clear_buffer() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

inline void pause_console() {
	clear_buffer();
	std::cin.get();
}