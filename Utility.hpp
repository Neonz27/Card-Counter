#pragma once

#include <iostream>

/// <summary>
/// Clears the console of all text.
/// </summary>
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

/// <summary>
/// Clears the console's input buffer.
/// </summary>
inline void clear_buffer() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

/// <summary>
/// Pauses the console to prevent the program from continuing or closing.
/// </summary>
inline void pause_console() {
	clear_buffer();
	std::cin.get();
}