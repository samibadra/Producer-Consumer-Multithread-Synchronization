Sami Badra  
Enrique Leon

CS 570, Spring 2015  
Assignment #3  
FILE: README

Copyright 2015 Sami Badra. All Rights Reserved

##Description
This project is a simulation of a factory where candy is both produced and consumed from the conveyer belt. The simulation must meet the following specifications:  
  - There are precisely 2 producers, and 2 consumers
  - **The producers:** crunchy frog bites and everlasting escargot suckers. These are the two types of candies produced in this factory (Each candy has its own producer thread)
  - **The consumers:** Lucy and Ethel. They are workers in the factory, and consume candies by removing them from the FRONT of the belt (Each worker has its own consumer thread)
  - Each individual producer/consumer has their own 'delay' which is the time needed (milliseconds) to either produce or consume a candy. (See 'Optional Arguments' below)
  - No more than 10 candies are on the conveyer belt at any given time.
  - No more than 3 frog bites can be on the conveyer belt at any given time.
  - Candies are taken off the line in the order that they are produced.

##Optional Arguments
**These arguments specify the delays for each individual producer/consumer. If an argument is omitted, it will have a delay of zero.**  

Argument Flags| Description
--------------| -------------
-E N | Specifies the number of milliseconds N that the Ethel consumer requires to put a candy in the box and should be invoked each time Ethel removes a candy regardless of the candy type.
-L N | Similar argument for the Lucy consumer.
-f N | Specifies the number of milliseconds N between the production of each crunchy frog bite.
-e N | Specifies the number of milliseconds N between the production of each everlasting escargot sucker.

##Lessons Learned
- The most influential lesson that I learned from this assignment is how to use semaphores to synchronize multiple threads that are performing actions with the same objects.
- I also learned how to properly implement critical sections (mutex) to avoid corruption when you have multiple threads accessing the same part of memory.
- This project has also sharpened my Object-Oriented Programming skills immensely, since it works with multiple objects, as well as communication between them.
