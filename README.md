# Philosophers

This project in c language is a training to multi-threads/multi-process programming with the use of mutex to resolve The dining philosophers problem.
The dining philosophers problem is a famous problem in computer science used to illustrate common issues in concurrent programming. The problem was originally formulated in 1965 by Edsger Dijkstra, and is stated as follows:

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
