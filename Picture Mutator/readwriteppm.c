#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PPM_IMAGE *read_ppm(const char *file_name){
    FILE *read_file;
    read_file = fopen(file_name, "r");
    unsigned char a,b;
    int w, h, m_color;
    int red, green, blue;
    fscanf(read_file, "%c%c", &a, &b);
    fscanf(read_file, "%d", &w);
    fscanf(read_file, "%d", &h);
    fscanf(read_file, "%d", &m_color);
    PPM_IMAGE *copy_img;
    
    
    copy_img = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
    copy_img->width = w;
    copy_img->height = h;
    copy_img->max_color = m_color;
    copy_img->data = (PIXEL *)malloc((w*h)*(sizeof(PIXEL)));
    for(int i = 0; i < w*h; i++){
        
        fscanf(read_file, "%d", &red);
        fscanf(read_file, "%d", &green);
        fscanf(read_file, "%d", &blue);
        copy_img->data[i].r = red;
        copy_img->data[i].g = green;
        copy_img->data[i].b = blue;
    }
    
    fclose(read_file);
    return copy_img;

}

void write_ppm(const char *file_name , const PPM_IMAGE *image){
    FILE *write_file;
    int increment = 0;
    write_file = fopen(file_name, "w");
    fprintf(write_file, "P3\n");
    fprintf(write_file, "%d %d\n", image->width, image->height);
    fprintf(write_file, "%d\n", image->max_color);
    
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            fprintf(write_file, "%d ", image->data[increment].r);
            fprintf(write_file, "%d ", image->data[increment].g);
            fprintf(write_file, "%d ", image->data[increment].b);
            increment++;
        }
        fprintf(write_file, "\n");
    }
    fclose(write_file);
}
