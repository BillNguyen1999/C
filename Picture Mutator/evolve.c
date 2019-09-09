#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//modified and referenced from https://www.geeksforgeeks.org/quick-sort/
static void swap(Individual* A, Individual* B){
    Individual temp = *A;
    *A = *B;
    *B = temp;
}
//modified and referenced from https://www.geeksforgeeks.org/quick-sort/
static int partition (Individual *individual, int low, int high){
    int pivot = individual[high].fitness;
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++)
    {
        
        if (individual[j].fitness <= pivot)
        {
            i++;
            swap(&individual[i], &individual[j]);
        }
    }
    swap(&individual[i + 1], &individual[high]);
    return (i + 1);
}

//modified and referenced from https://www.geeksforgeeks.org/quick-sort/
static void quickSort(Individual *individual, int low, int high){
    if (low < high)
    {
        int pi = partition(individual, low, high);

        quickSort(individual, low, pi - 1);
        quickSort(individual, pi + 1, high);
    }
}




PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
    Individual *evolve_ind = generate_population(population_size, image->width, image->height, image->max_color);
    comp_fitness_population(image->data, evolve_ind, population_size);
    quickSort(evolve_ind, 0, population_size - 1);
    for(int i = 0; i < num_generations; i++){
        crossover(evolve_ind, population_size);
        mutate_population(evolve_ind, population_size, rate);
        comp_fitness_population(image->data, evolve_ind, population_size);
        quickSort(evolve_ind, 0, population_size-1);
    }
    
    PPM_IMAGE *fittest_img; //storing image of individual with best fitness
    fittest_img = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
    fittest_img->width = image->width;
    fittest_img->height = image->height;
    fittest_img->max_color = image->max_color;
    fittest_img->data = evolve_ind[0].image.data;
    
    for(int k = 1; k < population_size; k++){ //free all the other images
        free(evolve_ind[k].image.data);
    }
    
    free(evolve_ind);
    
    return fittest_img;
    
}

void free_image(PPM_IMAGE *p){
    free(p->data);
    free(p);
}

