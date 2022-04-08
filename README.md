# Operating-Systems-Assignment-1-Parker-Higgins
Assignment 1 for Parker Higgins in the operating systems class of spring 2022

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

The table.h and table.c files are made to hold the shared memory and the functions that both the producer and consumer use.

When the producer is run, it writes a random number to one of the two memory blocks.
Once both memory blocks are full it has to wait for the consumer to consume an item before it can produce another item to the block.

The producer has 10 integers that it wants to play into memory for the consumer to consume.

Once all 10 integers have been produced the producer program terminates.

The consumer.elf program can be terminated by using Ctrl + C in the terminal.

At the conclusion of this program, the producer will have produced ten integers and the consumer will consume all ten using a memory buffer that can
hold two integer values at a time.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
I provided the example of two terminals where one is producing and one is consuming with the code in the screenshot provided.

