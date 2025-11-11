#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollOneDie(void) {
    return (rand() % 6) + 1; // Returns 1 to 6 each time
}

int main() {
    int counts[13] = {0};
    int trials = 1000000;
    int die1, die2, sum;
    srand(time(NULL)); // Only call this ONCE, and INSIDE main()

    for (int i = 0; i < trials; ++i) {
        die1 = rollOneDie();
        die2 = rollOneDie();
        sum = die1 + die2;
        if (sum >= 2 && sum <= 12) {
            counts[sum]++;
        }
    }

    printf("Sum\tCount\tEmpirical Prob\tTheoretical Prob\n");
    for (int s = 2; s <= 12; ++s) {
        double empirical = (double)counts[s] / trials;
        int ways;
        if (s == 2 || s == 12) ways = 1;
        else if (s == 3 || s == 11) ways = 2;
        else if (s == 4 || s == 10) ways = 3;
        else if (s == 5 || s == 9) ways = 4;
        else if (s == 6 || s == 8) ways = 5;
        else if (s == 7) ways = 6;
        double theoretical = (double)ways / 36.0;
        printf("%d\t%d\t%.4lf\t\t%.4lf\n", s, counts[s], empirical, theoretical);
    }
    return 0;
}
