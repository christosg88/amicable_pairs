# Introduction

This program finds and prints all amicable number pairs, up to LIMIT.

It's using Thread Building Blocks (TBB) as the implementation of the parallel execution policy in the transform
algorithm, to compute the sum of proper divisors of each number up to LIMIT in parallel.

# Amicable numbers

A pair of numbers x and y is called amicable if the sum of the proper divisors of either one is equal to the other.

# Twin amicable numbers

A pair of numbers x and y are called *twin* amicable if there not any part of another amicable pair between x and y.

# List of amicable numbers up to 1,000,000

```none
220 284 twins!
1184 1210 twins!
2620 2924 twins!
5020 5564 twins!
6232 6368 twins!
10744 10856 twins!
12285 14595 twins!
17296 18416 twins!
63020 76084
66928 66992 twins!
67095 71145
69615 87633
79750 88730
100485 124155
122265 139815
122368 123152 twins!
141664 153176
142310 168730
171856 176336
176272 180848
185368 203432
196724 202444 twins!
280540 365084
308620 389924
319550 430402
356408 399592
437456 455344 twins!
469028 486178 twins!
503056 514736 twins!
522405 525915 twins!
600392 669688
609928 686072
624184 691256
635624 712216
643336 652664 twins!
667964 783556
726104 796696
802725 863835 twins!
879712 901424
898216 980984
```
