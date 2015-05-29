/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: Factory.h
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 
 */

#ifndef __Assignment3__Factory__
#define __Assignment3__Factory__
#include <queue>
#include <iostream>
#include <string>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define MILLI 1000
#define NANO 1000000000
#define CFB "crunchy frog bite"
#define ES "escargot sucker"
#define QT "Quota"

using namespace std;

class Factory{
private:
    queue<string> factoryBelt;  //Shared Resource between producers/consumers
    
    vector<struct Worker> producers;    //Producers will add to the belt
    vector<struct Worker> consumers;    //Consumers will remove from the belt
    int totalProduced;  //Total candies produced
    int totalConsumed;  //Total candies consumed
    int currentFrog;    //current frogs on belt
    int currentEscargot;//current escargot on belt
    int numProducers;
    int numConsum;
    sem_t resource;
    sem_t beltSpace;
    sem_t empty;
    sem_t frogLimit;
public:
    sem_t prodLimit;
    Factory();
    static const int TOTAL_LIMIT = 100;
    static const int BELT_LIMIT = 10;
    static const int FROG_LIMIT = 3;
    
    /* These 2 functions need to enter Critical Section */
    bool addItem(string candy);
    string removeItem(string name);
    
    /* These 2 functions enlist producers/consumers to the Factory */
    void enlistProducer(string name, int delay);
    void enlistConsumer(string name,int delay);
    
    void printBeltInfo(string msg);
    void productionResults();
    void startProduction();
};

/* A general structure representing each producer/consumer */
struct Worker{
    string name;
    int work;
    int delay;
    int frogWork;
    int escargotWork;
    Factory *factory;
    sem_t *resource;
    sem_t *beltSpace;
    sem_t *empty;
    sem_t *frogLimit;
    sem_t *prodLimit;
};

#endif /* defined(__Assignment3__Factory__) */
