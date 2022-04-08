//producer.c
//Parker Higgins
//Operating Systems Assignment 1
//4/7/22

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>

#include "table.h"

#define BLOCK_SIZE 4096
#define NUM_ITERATIONS 10

int main(int argc, char *argv[]){

    //check to see if program called right
    if (argc != 1){
        printf("usage - %s [stuff to write]", argv[0]);
        return -1;
    }

    //setup semaphores
    sem_t *sem_prod = sem_open(SEM_PROD_FNAME, 0);
    if(sem_prod == SEM_FAILED){
        perror("sem_open/myproducer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONS_FNAME, 0);
    if(sem_cons == SEM_FAILED){
        perror("sem_open/myconsumer");
        exit(EXIT_FAILURE);
    }


    //grab block
    char *block = attach_memory_block(FILENAME, BLOCK_SIZE, 0);
    char *block2 = attach_memory_block(FILENAME2, BLOCK_SIZE, 1);

    if (block == NULL){
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    if (block2 == NULL){
        printf("ERROR: couldn't get block2\n");
        return -1;
    }



    int in = 0;

    for (int i=0; i < NUM_ITERATIONS; i++){
        int x = rand() % 100; //create random into to put in shm 
        char exam[20];
        sprintf(exam, "%d", x); //converts int to string

        sem_wait(sem_cons);
        
            if(in == 0){//produce block data 
                
                printf("Writing: \"%s\"\n", exam);
                strncpy(block, exam, BLOCK_SIZE);
                
                in = (in+1)%bufferSize;
                
            }
            else if (in == 1){//produce block 2 data
                
                printf("Writing: \"%s\"\n", exam);
                
                strncpy(block2, exam, BLOCK_SIZE);
                
                in = (in+1)%bufferSize;
                
            } 
        sem_post(sem_prod); 
    }
   
    sem_close(sem_prod);
    sem_close(sem_cons);

    detach_mem_block(block);
    detach_mem_block(block2);

    return 0;

}