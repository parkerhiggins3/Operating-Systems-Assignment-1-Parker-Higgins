Hello,
 This is my operating systems programming assignment 1 github repository.
  
 In order to run the producer and consumer programs, first you compile the files using:
          make
Then, you run the consumer program by using:
          ./consumer.elf
Once you do this, you will see that the program is waiting to read in (or consume) whatever the producer is writing (or producing).

To run the producer, you use:
          ./producer.elf
This will start a loop that writes to the shared memory. Now you will see that the consumer is reading in what the producer is writing.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Documentation:

For starters, I decided to use a Makefile in order to compile the files I am using.

The destroy files are made in order to test the shared memory when I was writing the program and should be disregarded.

The table.h and table.c files are made to hold the shared memory and the functions that both the producer and consumer use.

When the producer is run, it writes a random number to the memory location.

