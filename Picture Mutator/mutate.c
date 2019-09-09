#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void mutate(Individual *individual, double rate){
    srand(time(NULL));
    int random_mutate, n, random_pixel, max_color;
    max_color = individual[0].image.max_color;
    n = individual[0].image.width * individual[0].image.height;
    random_mutate = (rate/100)*n;
    for(int i = 0; i < random_mutate; i++){
        random_pixel = lrand48() % n;
        individual->image.data[random_pixel].r =  lrand48() % (max_color + 1);
        individual->image.data[random_pixel].g =  lrand48() % (max_color + 1);
        individual->image.data[random_pixel].b =  lrand48() % (max_color + 1);
    }
}

void mutate_population(Individual *individual, int population_size, double rate){
    for(int i = population_size/4; i < population_size; i++){
        mutate(&individual[i], rate);
    }
}
