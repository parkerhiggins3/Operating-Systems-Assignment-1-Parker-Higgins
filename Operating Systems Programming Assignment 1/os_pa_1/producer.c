//phiggin4
//Operating Systems Programming Assignment 1
//producer.c

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/sem.h>
#include "table.h"


#define BLOCK_SIZE 4096
int NUM_ITERATIONS = 10;


int main(int argc, char *argv[]){

    //check to see if prgram called right
    if (argc != 1){
        printf("usage - %s [stuff to write]", argv[0]);
        return -1;
    }



    //set up the semaphores
    sem_t *sem_prod = sem_open(PRODUCER_SEM, 0);
    if (sem_prod == SEM_FAILED){
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(CONSUMER_SEM, 0);
    if (sem_cons == SEM_FAILED){
        perror("sem_open/consumer");
        exit(EXIT_FAILURE);
    }




    //grab block
    char *block = connect_to_block(FILENAME, BLOCK_SIZE);
    if (block == NULL){
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    for (int i = 0; i < NUM_ITERATIONS; i++){   
        int x = rand() % 100; //create random into to put in shm 
        char exam[20];
        sprintf(exam, "%d", x);

        sem_wait(sem_cons);
        printf("Writing: \%s\"\n", exam);
        strncpy(block, exam, BLOCK_SIZE);
        sem_post(sem_prod);//signal to put somehting in memory
    }




    sem_close(sem_prod);
    sem_close(sem_cons);
    detach_block(block);

    return 0;

}
