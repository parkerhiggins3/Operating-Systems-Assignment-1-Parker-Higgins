//phiggin4
//Operating Systems Programming Assignment 1
//table.c

#define TABLE_H


#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <string.h>
#include <sys/sem.h>



char * connect_to_block(char *filename, int size);
bool disconnect_from_block(char *block); 
bool destroy_block(char *filename);
bool detach_block(char *block);

#define BLOCK_SIZE 4096
#define FILENAME "producer.c"
#define ERROR (-1)

#define PRODUCER_SEM "/myproducer"
#define CONSUMER_SEM "/myconsumer"

