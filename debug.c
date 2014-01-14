#include <stdio.h>

#define __DEBUG__

#ifdef __DEBUG__
    #define DEBUG(format, ...) printf("File: "__FILE__",LINE: %05d: "format"\n",__LINE__,##__VA_ARGS__)
#else
    #define DEBUG(format, ...)
#endif

int main(int argc, char* argv[])
{
    char str[] = "Hello Debug...";
      
    DEBUG("ha ha, check me: %s", str);
    
    DEBUG("ha ha, end");
    
    return 0;   
}    