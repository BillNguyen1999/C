#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


PIXEL *generate_random_image(int width, int height, int max_color){
    PIXEL *rand_img = (PIXEL *)malloc((width*height)*(sizeof(PIXEL)));
    srand(time(NULL));
    for(int i = 0; i < width*height; i++){
        rand_img[i].r = lrand48() % (max_color + 1);
        rand_img[i].g = lrand48() % (max_color + 1);
        rand_img[i].b = lrand48() % (max_color + 1);
    }
    return rand_img;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
    Individual *gen_pop = (Individual *)malloc(population_size*sizeof(Individual));
    for(int i = 0; i < population_size; i++){
        gen_pop[i].image.width = width;
        gen_pop[i].image.height = height;
        gen_pop[i].image.max_color = max_color;
        gen_pop[i].image.data = generate_random_image(width, height, max_color);
        
    }
    
    return gen_pop;
}
