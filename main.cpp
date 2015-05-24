/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: main.cpp
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 
 DISCLAIMER: Any unauthorized use, including but not limited to, copying or
 redistributing any chunk of the source code (or an entire file) will result in
 punishment by law. I, Sami Badra, own all rights to the files and their contents.
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "CFactoryParse.h"
#include "Factory.h"
#include <semaphore.h>

int main(int argc, char *argv[]) {
    CFactoryParse parse(argc,argv);
    int ethel = parse.getEthelDelay();
    int lucy = parse.getLucyDelay();
    int frog = parse.getFrogDelay();
    int escargot = parse.getEscargotDelay();
    Factory factory;
    factory.enlistProducer(CFB, frog);
    factory.enlistProducer(ES, escargot);
    factory.enlistConsumer("Ethel", ethel);
    factory.enlistConsumer("Lucy", lucy);
    factory.startProduction();
    sem_wait(&factory.prodLimit);
    factory.productionResults();
}

