# Philosophers

This project in c language is a training to multi-threads/multi-process programming with the use of mutex to resolve The dining philosophers problem.
The dining philosophers problem is a famous problem in computer science used to illustrate common issues in concurrent programming.

---

## Author
[iragusa](https://github.com/IvanaRagusa)

---

## Status
Finished: 2023-06-26. Grade: 125/100.

---

## The dining philosophers problem:

The problem was originally formulated in 1965 by Edsger Dijkstra, and is stated as follows:
X amount of philosophers sit at a round table with bowls of food.
Forks are placed in front of each philosopher.
There are as many forks as philosophers.
All day the philosophers take turns eating, sleeping, and thinking.
A philosopher must have two forks in order to eat, and each fork
may only be used by one philosopher at a time. At any time a
philosopher can pick up or set down a fork,
but cannot start eating until picking up both forks.
The philosophers alternatively eat, sleep, or think.
While they are eating, they are not thinking nor sleeping,
while thinking, they are not eating nor sleeping,
and, of course, while sleeping, they are not eating nor thinking.

---

## Usage

Note that this project was tested on Linux only. It may run on MacOS with small adjustments to the Makefile.
You will now be in the correct directory for compilation. Compile with ```make```. Philosopers should now be ready!

---

## Run Philosopers
You can do some tests and sometime our philosophers die, sometime philosophers will think, sleep and eat for aaaaaa really long time, maybe infinity

Test 1: The philosopher should not eat and should die.
``` 
./Philosophers 1 800 200 200 
```
Test 2: No philosopher should die.
``` 
./Philosophers 5 800 200 200
```
Test 3: No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
``` 
./Philosophers 5 800 200 200 7
```
Test 4: The philosopher should not eat and should die.
``` 
./Philosophers 4 410 200 200
```
Test 5: One philosopher should die.
``` 
./Philosophers 4 310 200 100
```

---



