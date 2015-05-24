/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: CFactoryParse.h
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 
 DISCLAIMER: Any unauthorized use, including but not limited to, copying or
 redistributing any chunk of the source code (or an entire file) will result in
 punishment by law. I, Sami Badra, own all rights to the files and their contents.
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
