#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* obfuscate(int num, int obfLimit) {
    int newNum = 0;
    int currentSum = 0;

    int obfArray[obfLimit];
    for (int i = 0; i <= obfLimit; i++) {
        if (newNum >= num) {
            break;
        }

        if (i < obfLimit) {
            // randomize 0 to allowed max addition
            newNum = rand() % (num - currentSum);

            // replace randomize newNum: 0 with negative randomized number.
            if (newNum == 0) {
                newNum = -(rand() % (currentSum - 0));
            }
        } else {
            // must add up to num now.
            newNum = num - currentSum;
        }
        currentSum = currentSum + newNum;
        obfArray[i] = newNum;
    }

    int *obfPointer = obfArray;
    return obfPointer;
}

int main() {

    // random config
    time_t t;
    srand((unsigned) time(&t));

    int num = 10;
    int obfLimit = 10;

    int *obfuscated;
    obfuscated = obfuscate(num, obfLimit);

    for (int i = 0; i <= obfLimit; i++) {
        printf("%d\n", obfuscated[i]);
    }

    return 0;
}
