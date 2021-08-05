#include "delay.h"

void delay(int secs) {
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
