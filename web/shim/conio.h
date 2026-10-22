/*
 * Browser shim for <conio.h>, used only by the WebAssembly build (web/build.sh).
 * _getch() suspends the program (via Asyncify) until the page delivers a key.
 */
#ifndef UCARD_WEB_CONIO_H
#define UCARD_WEB_CONIO_H

#include <cstdio>
#include <iostream>
#include <emscripten.h>

EM_ASYNC_JS(int, ucard_wait_key, (), {
	return await Module.ucardWaitKey();
});

static inline int _getch(void){
	// Prompts are printed without a newline, so flush before waiting for input.
	std::cout.flush();
	std::fflush(stdout);
	return ucard_wait_key();
}

#endif /* UCARD_WEB_CONIO_H */
