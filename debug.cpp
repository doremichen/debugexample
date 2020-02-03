/**
 *	debug utils
 */
#include <stdlib.h>
#include <stdio.h>
#include "stdafx.h"
#include "debug.h"

#include <stdarg.h>

static FILE* sFp;

/*
 * initial dumpm file
 */
void openDumpFile(const char* path)
{
	errno_t err;

	if ((err = fopen_s(&sFp, path, "w+")) != 0) {
		DEBUG("open file fail: fp is NULL...");
	}
}

/*
 * dump message to file
 */
void dumpMsg(const char* format, ...)
{	
	if (sFp == NULL) {
		DEBUG("dumpMsg fail: fp is NULL...");
		return;
	}

	char info[256] = { '\0' };
	va_list argptr;
	va_start(argptr, format);
	vsnprintf(info, sizeof(info), format, argptr);
	fputs(info, sFp);
	va_end(argptr);
}

/*
 * close dump file
 */
void closeDumpFile()
{
	if (sFp == NULL) {
		DEBUG("close fail: fp is NULL...");
		return;
	}

	fclose(sFp);
}
