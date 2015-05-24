/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: Consumer.cpp
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 */

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include "Factory.h"
#include "Consumer.h"

void *consumeCandy(void *arg) {
    Worker *consumer = (Worker*) arg;
    struct timespec ts;
    ts.tv_sec = consumer->delay / MILLI;
    ts.tv_nsec = (consumer->delay % MILLI) * (NANO/MILLI);
    
    while(true) {
        nanosleep(&ts, NULL);
        sem_wait(consumer->empty);      //wait for an item to be placed on belt
        
        sem_wait(consumer->resource);   //grab access to memory
        string candy = consumer->factory->removeItem(consumer->name); //critical section
        sem_post(consumer->resource);   //release access to memory
        
        if(candy.compare(QT) != 0) {        //test if last item was consumed
            sem_post(consumer->beltSpace);      //increase belt space
            if(candy.compare(CFB) == 0){
                sem_post(consumer->frogLimit);  //increase frog limit
                consumer->frogWork++;
            }
            else consumer->escargotWork++;
            consumer->work++;
        }
        else pthread_exit(NULL);
    }
}
