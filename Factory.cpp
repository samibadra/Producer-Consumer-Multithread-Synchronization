/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: Factory.cpp
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 */

#include "Factory.h"
#include <semaphore.h>
#include <pthread.h>
#include "Producer.h"
#include "Consumer.h"

using namespace std;

/* sem_init is deprecated in OSX! */


/* Constructor for initializing Factory info */
Factory::Factory() {
    sem_init(&resource, 0, 1);              //critical section
    sem_init(&beltSpace, 0, BELT_LIMIT);    //spaces left on belt
    sem_init(&empty, 0, 0);                 //signifies if belt is empty
    sem_init(&frogLimit, 0, FROG_LIMIT);    //frog limit (max 3 frogs on the belt)
    sem_init(&prodLimit, 0, 0);              //production limit (produces 100 candies)
    totalProduced = 0;
    totalConsumed = 0;
    currentFrog = 0;
    currentEscargot = 0;
    numProducers = 0;
    numConsum = 0;
}

/* add another candy from the belt (Critical Section) */
bool Factory::addItem(string candy) {
    if(totalProduced >= TOTAL_LIMIT)  //Stop production once limit is reached
        return false;
    
    factoryBelt.push(candy);    //place candy in back of queue
    totalProduced++;
    
    if(candy.compare(CFB)==0) currentFrog++;
    else currentEscargot++;
    printBeltInfo("Added " + candy + ".");
    return true;
}

/* remove the next candy from the belt (Critical Section) */
string Factory::removeItem(string name) {
    if(totalConsumed >= TOTAL_LIMIT)    //Signal to consumer to terminate thread
        return QT;
    
    string consumedCandy = factoryBelt.front(); //grab item at front of queue
    factoryBelt.pop();  //remove from queue
    totalConsumed++;
    
    bool cfb = consumedCandy.compare(CFB)==0;
    if(cfb) currentFrog--;
    else currentEscargot--;
    
    printBeltInfo(name + " consumed " + (cfb? CFB:ES) + ".");
    if(totalConsumed >= TOTAL_LIMIT) sem_post(&prodLimit);
    return consumedCandy;
}

void Factory::printBeltInfo(string msg) {
    cout<<"Belt: ("<<currentFrog<<" frogs) + ("<<currentEscargot<<" escargots) = "
    <<currentFrog + currentEscargot<<". (produced: "<<totalProduced<<")\t"<<msg<<endl;
}

/* Create a Worker type based on the name and delay and enlist in vector */
void Factory::enlistConsumer(string name, int delay) {
    Worker consumer = {name,0,delay,0,0,this,&resource,&beltSpace,&empty,&frogLimit,&prodLimit};
    consumers.push_back(consumer);
    numConsum++;
}

/* Create a Worker type based on the name and delay and enlist in vector */
void Factory::enlistProducer(string name, int delay) {
    Worker producer = {name,0,delay,0,0,this,&resource,&beltSpace,&empty,&frogLimit,&prodLimit};
    producers.push_back(producer);
    numProducers++;
}

/* Prints the results of the simulation */
void Factory::productionResults() {
    cout<<"\nPRODUCTION REPORT"<<endl;
    cout<<"----------------------------"<<endl;
    
    for(int i = 0; i < (signed)producers.size();i++){
        cout<<producers[i].name<<" producer generated "
        <<producers[i].work<<" candies"<<endl;
    }
    for(int i = 0; i < (signed)consumers.size();i++){
        cout<<consumers[i].name<<" consumed "
        <<consumers[i].frogWork<<" "<<CFB<<" + "
        <<consumers[i].escargotWork<<" "<<ES
        <<" = "<<consumers[i].work<<endl;
    }
}

/* Initializes threads for each producer and consumer */
void Factory::startProduction() {
    for(int i = 0; i < (signed)producers.size();i++) {
        Worker *wp = &producers[i];
        pthread_t candyProducer;
        pthread_create(&candyProducer, NULL, produceCandy,(void*) wp);
    }
    for(int i = 0; i < (signed)consumers.size();i++) {
        Worker *wp = &consumers[i];
        pthread_t candyConsumer;
        pthread_create(&candyConsumer, NULL, consumeCandy,(void*) wp);
    }
}
