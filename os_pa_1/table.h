//Parker Higgins
//Operating Systems Assignment 1
//4/7/22

#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <pthread.h>
#include <stdbool.h>

char * attach_memory_block(char *filename, int size, int blockNum);
bool detach_mem_block(char *block);



#define BLOCK_SIZE 4096
#define bufferSize 2
#define FILENAME "producer.c"
#define FILENAME2 "producer.c"
#define IPC_RESULT_ERROR (-1)

#define SEM_PROD_FNAME "/myproducer"
#define SEM_CONS_FNAME "/myconsumer"


#endif