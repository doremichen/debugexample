/**
 * debug utils header file 
 */
#pragma once


#if debug_log == 0
#define DEBUG(format, ...) printf("LINE: %05d: "format"\n",__LINE__,##__VA_ARGS__)
#elif debug_log == 1
#define DEBUG(format, ...) dumpMsg("LINE: %05d: "format"\n",__LINE__,##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

void openDumpFile(const char* path);
void dumpMsg(const char* format, ...);
void closeDumpFile();