#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    // All logic goes here
    return 0;
}
int counts[13] = {0}; // counts[2] to counts[12] will be used
int trials = 1000000; // number of simulations
int die1, die2, sum; // These store current roll values
srand(time(NULL));
int rollOneDie(void) {
    return (rand() % 6) + 1; // Gives value 1-6
}
for(int i = 0; i < trials; ++i) {
    die1 = rollOneDie();
    die2 = rollOneDie();
    sum = die1 + die2;
    if(sum >=2 && sum <= 12){
        counts[sum]++;
    }
}
printf("Sum\tCount\tEmpirical Prob\tTheoretical Prob\n");
for(int s = 2; s <= 12; ++s) {
    double empirical = (double)counts[s] / trials;
    // Theoretical probabilities: 2 (1/36), 3 (2/36), ..., 7 (6/36), ..., 12 (1/36)
    int ways;
    if     (s==2 || s==12) ways = 1;
    else if(s==3 || s==11) ways = 2;
    else if(s==4 || s==10) ways = 3;
    else if(s==5 || s==9)  ways = 4;
    else if(s==6 || s==8)  ways = 5;
    else if(s==7)          ways = 6;
    double theoretical = (double)ways / 36.0;
    printf("%d\t%d\t%.4lf\t\t%.4lf\n", s, counts[s], empirical, theoretical);
}
