#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include "table.h"

#define ERROR (-1)

static int get_block (char *filename, int size){
    key_t key;

    //request key linked to filename
    key = ftok (filename, 0);
    if (key == ERROR){
        return ERROR;
    }
    //get shared block
    return shmget(key, size, 0644 | IPC_CREAT);
}

char * connect_to_block(char *filename, int size){
    int block_num = get_block(filename, size);
    char *result;

    //return null if doesnt grab the block
    if(block_num == ERROR){
        return NULL;
    }

    result = shmat(block_num, NULL, 0);
    if (result == (char*)ERROR){
        return NULL;
    }
    return result;

}

bool detach_block(char *block){
    return(shmdt(block) != ERROR);
}

bool destroy_block(char *filename){
    int block_num = get_block(filename, 0);

    if (block_num == ERROR) {
        return NULL;
    }
    return (shmctl(block_num, IPC_RMID, NULL) != ERROR);
}

char randomNumber(){
    int num = rand() % 10;
    char random_num = num+ '0';
    return random_num;
}