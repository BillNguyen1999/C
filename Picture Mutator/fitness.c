#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
    double summation = 0;
    double di, distance;
    for(int i = 0; i < image_size; i++){
        di = (A[i].r - B[i].r)*(A[i].r - B[i].r) + (A[i].g - B[i].g)*(A[i].g - B[i].g) + (A[i].b - B[i].b)*(A[i].b - B[i].b);
        summation += di;
    }
    
    distance = sqrt(summation);
    return distance;
}


void comp_fitness_population(const PIXEL *image , Individual *individual , int population_size){
    int n = individual[0].image.width * individual[0].image.height;
    for(int i = 0; i < population_size; i++){
        individual[i].fitness = comp_distance(image, individual[i].image.data, n);
    }
}
