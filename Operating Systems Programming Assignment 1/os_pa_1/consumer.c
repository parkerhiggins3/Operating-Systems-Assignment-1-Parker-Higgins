//phiggin4
//Operating Systems Programming Assignment 1
//consumer.c

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
#include <fcntl.h>

#define BLOCK_SIZE 4096


int main(int argc, char *argv[]){

    if (argc != 1){
        printf ("usage - %s //no args", argv[0]);
        return -1;
    }

    //remove semaphores if they have the same name
    sem_unlink(CONSUMER_SEM);
    sem_unlink(PRODUCER_SEM);

    //set up the semaphores
    sem_t *sem_prod = sem_open(PRODUCER_SEM, O_CREAT, S_IRUSR|S_IWUSR, 0);
    if (sem_prod == SEM_FAILED){
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(CONSUMER_SEM, O_CREAT, S_IRUSR|S_IWUSR, 1);
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

    while(true){
        sem_wait(sem_prod);
        if(strlen(block)>0){
            printf("Reading \"%s\"\n", block);
            bool done = (strcmp(block, "quit")==0);
            block[0]=0;
            if (done) {break;}
        }
        sem_post(sem_cons);
    }
    
    sem_close(sem_prod);
    sem_close(sem_cons);

    detach_block(block);
    

    return 0;




}



