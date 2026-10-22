/*
 * Browser shim for the few <windows.h> console functions used by U-Card.
 * Used only by the WebAssembly build (web/build.sh).
 */
#ifndef UCARD_WEB_WINDOWS_H
#define UCARD_WEB_WINDOWS_H

#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <emscripten.h>

EM_JS(void, ucard_clear_screen, (), {
	Module.ucardClear();
});

static inline int SetConsoleTitle(const char *title){ (void)title; return 1; }
static inline int SetConsoleOutputCP(unsigned int codepage){ (void)codepage; return 1; }
static inline int SetConsoleCP(unsigned int codepage){ (void)codepage; return 1; }

// The game calls system("CLS") to clear the console; there is no shell in the browser.
static inline int ucard_system(const char *command){
	std::cout.flush();
	std::fflush(stdout);
	if (command && (std::strcmp(command, "CLS") == 0 || std::strcmp(command, "cls") == 0)){
		ucard_clear_screen();
		return 0;
	}
	return -1;
}
#define system(command) ucard_system(command)

#endif /* UCARD_WEB_WINDOWS_H */
