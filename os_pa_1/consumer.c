//consumer.c
//Parker Higgins
//Operating Systems Assignment 1
//4/7/22

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "table.h"

#define BLOCK_SIZE 4096


int main(int argc, char *argv[]){

    if (argc != 1){
        printf ("usage - %s //no args", argv[0]);
        return -1;
    }

    //setup semaphores
    sem_unlink(SEM_CONS_FNAME);
    sem_unlink(SEM_PROD_FNAME);

    sem_t *sem_prod = sem_open(SEM_PROD_FNAME, O_CREAT, S_IRUSR| S_IWUSR, 0);
    if(sem_prod == SEM_FAILED){
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONS_FNAME, O_CREAT, S_IRUSR| S_IWUSR, 2);
    if(sem_cons == SEM_FAILED){
        perror("sem_open/consumer");
        exit(EXIT_FAILURE);
    }

    //grab block
    char *block = attach_memory_block(FILENAME, BLOCK_SIZE, 0);
    char *block2 = attach_memory_block(FILENAME2, BLOCK_SIZE, 1);

    if (block == NULL){
        printf("ERROR: couldn't get block\n");
        return -1;
    }


    int out = 0;

    while(1){
        
        sem_wait(sem_prod);
        sleep(1);
           
            if(out == 0){//consume block data 
                
                printf("Reading: \"%s\"\n", block);
                block[0]=0;
                
                out = (out+1)%bufferSize;
                
            }
            else if (out == 1){//consume block 2 data
                
                printf("Reading: \"%s\"\n", block2);
                block2[0]=0;
                
                out = (out+1)%bufferSize;
               
            }

        sem_post(sem_cons);
    }
    
    sem_close(sem_cons);
    sem_close(sem_prod);
    detach_mem_block(block);
    detach_mem_block(block2);

    return 0;




}