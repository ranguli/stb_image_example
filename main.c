#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "stb_image.h"

void get_pixel(stbi_uc *image, size_t imageWidth, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b) {
    // https://redd.it/8gyyb6

    const stbi_uc *pixel = image + (3 * (y * imageWidth + x));

    *r = pixel[0];
    *g = pixel[1];
    *b = pixel[2];
}

int main(void) {
    int width, height, channels;
    unsigned char *img = stbi_load("test_image.png", &width, &height, &channels, 3);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            stbi_uc r;
            stbi_uc g;
            stbi_uc b;

            get_pixel(img, width, x, y, &r, &g, &b);

            printf("(%d,%d): R:%d G:%d B:%d\n", x, y, r, g, b);
        }

    }
}
