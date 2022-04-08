//Parker Higgins
//Operating Systems Assignment 1
//4/7/22

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "table.h"

#define ERROR (-1)

static int get_shared_block(char *filename, int size, int blockNum){

    key_t key;

    key = ftok(filename, blockNum);
    if (key == ERROR){
        printf("ERROR: in getsharedblock\n");
        return ERROR;
    }
        
    return shmget(key, size, 0644 | IPC_CREAT); 

}

char * attach_memory_block(char *filename, int size, int blockNum) {
    int shared_block_id = get_shared_block(filename, size, blockNum);


    char *result;

    if (shared_block_id == ERROR){
        return NULL;
    }


    result = shmat(shared_block_id, NULL, 0); 
    if (result == (char *)ERROR){
        return NULL;
    }

    return result;
}

bool detach_mem_block(char *block){
    return (shmdt(block) != ERROR); 
}