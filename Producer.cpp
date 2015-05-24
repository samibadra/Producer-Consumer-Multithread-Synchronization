/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: Producer.cpp
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 
 DISCLAIMER: Any unauthorized use, including but not limited to, copying or
 redistributing any chunk of the source code (or an entire file) will result in
 punishment by law. I, Sami Badra, own all rights to the files and their contents.
 */

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include "Factory.h"
#include "Producer.h"

void *produceCandy(void *arg) {
    Worker *producer = (Worker*) arg;
    struct timespec ts;
    ts.tv_sec = producer->delay / MILLI;
    ts.tv_nsec = (producer->delay % MILLI) * (NANO/MILLI);
    bool cfb = (producer->name.compare(CFB)==0);
    
    while(true) {
        nanosleep(&ts, NULL);
        
        if(cfb) sem_wait(producer->frogLimit);  //wait if frog limit is reached
        sem_wait(producer->beltSpace);          //wait for space on the belt
        
        sem_wait(producer->resource);           //grab access to memory
        bool success = (producer->factory->addItem(producer->name)); //critical section
        sem_post(producer->resource);           //release access to memory
        
        if(success) {
            sem_post(producer->empty);  //increase empty signifier
            producer->work++;
            if(cfb)producer->frogWork++;
            else producer->escargotWork++;
        }
        else pthread_exit(NULL);
    }
}
