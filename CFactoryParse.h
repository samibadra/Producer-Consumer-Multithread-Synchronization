/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: CFactoryParse.h
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 */

#ifndef __Assignment3__CFactoryParse__
#define __Assignment3__CFactoryParse__

class CFactoryParse {
private:
    int etheldelay,lucydelay,frogdelay,escargotdelay;
    void parse(int argc,char* argv[]);
    
public:
    CFactoryParse(int argc,char *argv[]);
    int getEthelDelay();
    int getLucyDelay();
    int getFrogDelay();
    int getEscargotDelay();
};

#endif
