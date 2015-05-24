/*
 Sami Badra
 Enrique Leon
 
 CS 570, Spring 2015
 Assignment #3, producer/consumer simulation
 FILE: CFactoryParse.cpp
 
 Copyright (c) 2015 Sami Badra. All rights reserved.
 */

#include <stdio.h>
#include <getopt.h>
#include <cstdlib>
#include "CFactoryParse.h"

CFactoryParse::CFactoryParse(int argc,char *argv[]) {
    etheldelay=lucydelay=frogdelay=escargotdelay=0;
    CFactoryParse::parse(argc, argv);
}

void CFactoryParse::parse(int argc,char* argv[]) {
    int c;
    int optionIndex;
    /* struct containing the options used */
    struct option long_options[5] = {
        {"Ethel Delay",required_argument,0,'E'},
        {"Lucy Delay",required_argument,0,'L'},
        {"Frog Delay",required_argument,0,'f'},
        {"Escargot Delay",required_argument,0,'e'},
        {0,0,0,0}
    };
    while((c = getopt_long(argc, argv, "E:L:e:f:", long_options, &optionIndex))!=-1){
        switch (c) {
            case 'E':
                etheldelay = atoi(optarg);
                break;
            case 'L':
                lucydelay = atoi(optarg);
                break;
            case 'f':
                frogdelay = atoi(optarg);
                break;
            case 'e':
                escargotdelay = atoi(optarg);
                break;
            case'?':
                fprintf(stderr, "%s Usage:[-E millsec] [-L millsec] [-E millsec] [-E millsec]",argv[0]);
                break;
            default:
                break;
        }
        
    };
}

int CFactoryParse::getEthelDelay(){
    return this->etheldelay;
}

int CFactoryParse::getLucyDelay(){
    return this->lucydelay;
}

int CFactoryParse::getFrogDelay() {
    return this->frogdelay;
}

int CFactoryParse::getEscargotDelay(){
    return this->escargotdelay;
}
